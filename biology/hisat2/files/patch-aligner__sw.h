--- aligner_sw.h.orig	2020-07-24 20:07:54 UTC
+++ aligner_sw.h
@@ -66,11 +66,13 @@
 
 #define INLINE_CUPS
 
+#define	SIMDE_ENABLE_NATIVE_ALIASES
+
+#include <simde/x86/sse2.h>
 #include <stdint.h>
 #include <iostream>
 #include <limits>
 #include "threading.h"
-#include <emmintrin.h>
 #include "aligner_sw_common.h"
 #include "aligner_sw_nuc.h"
 #include "ds.h"
