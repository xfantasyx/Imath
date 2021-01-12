///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2007-2011, Industrial Light & Magic, a division of Lucas
// Digital Ltd. LLC
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Industrial Light & Magic nor the names of
// its contributors may be used to endorse or promote products derived
// from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////

// clang-format off

#ifndef _PyImathVecOperators_h_
#define _PyImathVecOperators_h_

namespace PyImath {

template <class T>
struct op_vecDot {
    static inline typename T::BaseType apply(const T &a, const T &b) { return a.dot(b); }
};

template <class T,
          IMATH_ENABLE_IF(!std::is_integral<typename T::BaseType>::value)>
struct op_vecLength {
    static inline typename T::BaseType apply(const T &v) { return v.length(); }
};

template <class T>
struct op_vecLength2 {
    static inline typename T::BaseType apply(const T &v) { return v.length2(); }
};

template <class T,
          IMATH_ENABLE_IF(!std::is_integral<typename T::BaseType>::value)>
struct op_vecNormalize {
    static inline void apply(T &v) { v.normalize(); }
};

template <class T,
          IMATH_ENABLE_IF(!std::is_integral<typename T::BaseType>::value)>
struct op_vecNormalized {
    static inline T apply(const T &v) { return v.normalized(); }
};

template <class T,
          IMATH_ENABLE_IF(!std::is_integral<typename T::BaseType>::value)>
struct op_vecNormalizeExc {
    static inline void apply(T &v) { v.normalizeExc(); }
};

template <class T,
          IMATH_ENABLE_IF(!std::is_integral<typename T::BaseType>::value)>
struct op_vecNormalizedExc {
    static inline T apply(const T &v) { return v.normalizedExc(); }
};
  
template <class T>
struct op_vec3Cross {
    static inline IMATH_NAMESPACE::Vec3<T> apply(const IMATH_NAMESPACE::Vec3<T> &a, const IMATH_NAMESPACE::Vec3<T> &b) { return a.cross(b); }
};

template <class T>
struct op_vec2Cross {
    static inline T apply(const IMATH_NAMESPACE::Vec2<T> &a, const IMATH_NAMESPACE::Vec2<T> &b) { return a.cross(b); }
};

}  // namespace PyImath

#endif // _PyImathVecOperators_h_