--- htscodecs/htscodecs/rANS_static32x16pr_neon.c.orig	2026-03-24 19:00:35 UTC
+++ htscodecs/htscodecs/rANS_static32x16pr_neon.c
@@ -32,7 +32,7 @@
  */
 
 #include "config.h"
-#ifdef __ARM_NEON
+#if defined(__ARM_NEON) && defined(__aarch64__)
 #include <arm_neon.h>
 
 #include <limits.h>
