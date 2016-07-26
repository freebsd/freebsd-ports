--- libaften/cpu_caps.h.orig	2007-08-11 16:13:25 UTC
+++ libaften/cpu_caps.h
@@ -26,6 +26,7 @@
 #include "ppc_cpu_caps.h"
 #else
 static inline void cpu_caps_detect(void){}
+static inline void apply_simd_restrictions(__unused AftenSimdInstructions *simd_instructions){}
 #endif
 
 #endif /* CPU_CAPS_H */
