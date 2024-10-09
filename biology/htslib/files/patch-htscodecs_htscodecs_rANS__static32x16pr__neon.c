--- htscodecs/htscodecs/rANS_static32x16pr_neon.c.orig	2024-10-09 21:43:35 UTC
+++ htscodecs/htscodecs/rANS_static32x16pr_neon.c
@@ -32,7 +32,7 @@
  */
 
 #include "config.h"
-#if defined(__ARM_NEON) && defined(__aarch64__)
+#if defined(__ARM_NEON)
 #include <arm_neon.h>
 
 #include <limits.h>
