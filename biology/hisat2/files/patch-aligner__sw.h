--- aligner_sw.h.orig	2026-08-31 12:31:38 UTC
+++ aligner_sw.h
@@ -70,11 +70,8 @@
 #include <iostream>
 #include <limits>
 #include "threading.h"
-#if defined(__aarch64__) || defined(__arm__) || defined(_M_ARM64)
-#  include "sse2neon.h"
-#else
-#  include <emmintrin.h>
-#endif
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
 #include "aligner_sw_common.h"
 #include "aligner_sw_nuc.h"
 #include "ds.h"
