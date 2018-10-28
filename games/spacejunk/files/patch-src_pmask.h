--- src/pmask.h.orig	2018-10-16 15:21:01 UTC
+++ src/pmask.h
@@ -36,7 +36,7 @@ extern "C" {
 //e.g. 4 for 16-bit ints, 5 for 32-bit ints, 6 for 64-bit ints
 //don't worry about setting it incorrectly
 //you'll get a compile error if you do, not a run-time error
-#if defined(__alpha__) || defined(__ia64__) || defined(__x86_64__)
+#if defined(__alpha__) || defined(__ia64__) || defined(__x86_64__) || defined(__powerpc64__)
 #define MASK_WORD_BITBITS 6
 #else
 #define MASK_WORD_BITBITS 5
