--- include/fp16.h.orig	2019-08-17 20:08:49 UTC
+++ include/fp16.h
@@ -5,7 +5,7 @@
 #include <fp16/fp16.h>
 
 #if defined(PSIMD_H)
-#include <fp16/psimd.h>
+#include <psimd.h>
 #endif
 
 #endif /* FP16_H */
