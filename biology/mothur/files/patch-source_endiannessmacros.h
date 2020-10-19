--- source/endiannessmacros.h.orig	2020-10-19 10:22:23 UTC
+++ source/endiannessmacros.h
@@ -53,16 +53,6 @@
 #  define SP_BIG_ENDIAN
 #endif
 
-/*
- * PowerPC
- */
-#if defined(__ppc__) || defined(__ppc)
-#  if defined(SP_LITTLE_ENDIAN)
-#    undef SP_LITTLE_ENDIAN
-#  endif
-#  define SP_BIG_ENDIAN
-#endif
-
 /* Some catch-alls */
 #if defined(__LITTLE_ENDIAN__) || defined(__LITTLEENDIAN__)
 #    define SP_LITTLE_ENDIAN
