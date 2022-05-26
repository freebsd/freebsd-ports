--- src/s2/util/math/exactfloat/exactfloat.cc.orig	2022-05-24 22:12:24 UTC
+++ src/s2/util/math/exactfloat/exactfloat.cc
@@ -141,7 +141,7 @@ inline static uint64 BN_ext_get_uint64(const BIGNUM* b
 #ifdef IS_LITTLE_ENDIAN
   S2_CHECK_EQ(BN_bn2lebinpad(bn, reinterpret_cast<unsigned char*>(&r),
               sizeof(r)), sizeof(r));
-#elif IS_BIG_ENDIAN
+#elif defined(IS_BIG_ENDIAN)
   S2_CHECK_EQ(BN_bn2binpad(bn, reinterpret_cast<unsigned char*>(&r),
               sizeof(r)), sizeof(r));
 #else
