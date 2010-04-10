--- ./libaften/cpu_caps.h.orig	2007-08-11 18:13:25.000000000 +0200
+++ ./libaften/cpu_caps.h	2010-04-03 00:31:40.000000000 +0200
@@ -26,6 +26,7 @@
 #include "ppc_cpu_caps.h"
 #else
 static inline void cpu_caps_detect(void){}
+static inline void apply_simd_restrictions(__unused AftenSimdInstructions *simd_instructions){}
 #endif
 
 #endif /* CPU_CAPS_H */
