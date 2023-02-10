--- third_party/fontconfig/src/src/fccompat.c.orig	2022-02-07 13:39:41 UTC
+++ third_party/fontconfig/src/src/fccompat.c
@@ -169,7 +169,9 @@ FcRandom(void)
 {
     int32_t result;
 
-#if HAVE_RANDOM_R
+#if HAVE_ARC4RANDOM
+    result = arc4random() & 0x7fffffff;
+#elif HAVE_RANDOM_R
     static struct random_data fcrandbuf;
     static char statebuf[256];
     static FcBool initialized = FcFalse;
