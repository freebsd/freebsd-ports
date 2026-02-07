--- src/lib/OpenEXRCore/unpack.c.orig	2025-11-17 01:18:11 UTC
+++ src/lib/OpenEXRCore/unpack.c
@@ -15,7 +15,7 @@
 
 /* TODO: learn arm neon intrinsics for this */
 #if (defined(__x86_64__) || defined(_M_X64))
-#    if defined(__AVX__) && (defined(__F16C__) || defined(__GNUC__) || defined(__clang__))
+#    if defined(__AVX__) && defined(__F16C__) && (defined(__GNUC__) || defined(__clang__))
 #        define USE_F16C_INTRINSICS
 #    elif (defined(__GNUC__) || defined(__clang__))
 #        define ENABLE_F16C_TEST
