--- sse_util.h.orig	2026-08-31 12:36:06 UTC
+++ sse_util.h
@@ -24,11 +24,9 @@
 #include "ds.h"
 #include "limit.h"
 #include <iostream>
-#if defined(__aarch64__) || defined(__arm__) || defined(_M_ARM64)
-#  include "sse2neon.h"
-#else
-#  include <emmintrin.h>
-#endif
+
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 
 class EList_m128i {
 public:
