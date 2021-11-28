--- sse_util.h.orig	2021-11-27 23:25:39 UTC
+++ sse_util.h
@@ -20,11 +20,13 @@
 #ifndef SSE_UTIL_H_
 #define SSE_UTIL_H_
 
+#define SIMDE_ENABLE_NATIVE_ALIASES
+#include <simde/x86/sse2.h>
+
 #include "assert_helpers.h"
 #include "ds.h"
 #include "limit.h"
 #include <iostream>
-#include <emmintrin.h>
 
 class EList_m128i {
 public:
