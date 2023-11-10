--- include/quickcpplib/uint128.hpp.orig	2023-10-24 05:06:15 UTC
+++ include/quickcpplib/uint128.hpp
@@ -53,7 +53,7 @@ namespace integers128
 #if defined(__SSE2__) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 2)
     __m128i as_m128i;
 #endif
-#if defined(__GNUC__) || defined(__clang__)
+#if defined(__SIZEOF_INT128__)
     unsigned __int128 as_uint128;
 #endif
     //! Default constructor, no bits set
@@ -100,7 +100,7 @@ namespace integers128
     }
     uint128 operator+=(const uint128 &v) noexcept
     {
-#if defined(__GNUC__) || defined(__clang__)
+#if defined(__SIZEOF_INT128__)
       as_uint128 += v.as_uint128;
       return *this;
 #endif
@@ -118,7 +118,7 @@ namespace integers128
     }
     uint128 operator-=(const uint128 &v) noexcept
     {
-#if defined(__GNUC__) || defined(__clang__)
+#if defined(__SIZEOF_INT128__)
       as_uint128 -= v.as_uint128;
       return *this;
 #endif
@@ -146,7 +146,7 @@ namespace integers128
     {
       if(!b)
         throw std::domain_error("divide by zero");
-#if defined(__GNUC__) || defined(__clang__)
+#if defined(__SIZEOF_INT128__)
       as_uint128 %= b.as_uint128;
       return *this;
 #endif
@@ -169,7 +169,7 @@ namespace integers128
     {
       if(!b)
         throw std::domain_error("divide by zero");
-#if defined(__GNUC__) || defined(__clang__)
+#if defined(__SIZEOF_INT128__)
       as_uint128 %= b;
       return *this;
 #endif
@@ -215,7 +215,7 @@ namespace integers128
     }
     uint128 operator<<=(uint8_t v) noexcept
     {
-#if defined(__GNUC__) || defined(__clang__)
+#if defined(__SIZEOF_INT128__)
       as_uint128 <<= v;
       return *this;
 #endif
@@ -232,7 +232,7 @@ namespace integers128
     }
     uint128 operator>>=(uint8_t v) noexcept
     {
-#if defined(__GNUC__) || defined(__clang__)
+#if defined(__SIZEOF_INT128__)
       as_uint128 >>= v;
       return *this;
 #endif
