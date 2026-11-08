--- third_party/fontconfig/src/src/fccompat.c.orig	2026-08-24 20:59:34 UTC
+++ third_party/fontconfig/src/src/fccompat.c
@@ -176,7 +176,9 @@ FcRandom (void)
 {
     int32_t result;
 
-#if HAVE_RANDOM_R
+#if HAVE_ARC4RANDOM
+    result = arc4random() & 0x7fffffff;
+#elif HAVE_RANDOM_R
     static struct random_data fcrandbuf;
     static char               statebuf[256];
     static FcBool             initialized = FcFalse;
