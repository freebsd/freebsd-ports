--- gfm.h.orig	2026-09-18 19:08:30 UTC
+++ gfm.h
@@ -59,6 +59,11 @@
 #include "repeat.h"
 #include "repeat_kmer.h"
 
+#if defined(POPCNT_CAPABILITY) && !defined(__x86_64__) && !defined(__i386__) && \
+    !defined(_M_X64) && !defined(_M_IX86)
+#undef POPCNT_CAPABILITY
+#endif
+
 #ifdef POPCNT_CAPABILITY
 #include "processor_support.h"
 #endif
