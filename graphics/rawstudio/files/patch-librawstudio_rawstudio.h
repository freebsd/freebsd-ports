--- librawstudio/rawstudio.h.orig	2021-08-03 02:36:16 UTC
+++ librawstudio/rawstudio.h
@@ -20,10 +20,6 @@
 #ifndef RAWSTUDIO_H
 #define RAWSTUDIO_H
 
-#ifdef  __cplusplus
-extern "C" {
-#endif
-
 #include <sys/types.h>
 #include "rs-types.h"
 
@@ -77,9 +73,5 @@ extern "C" {
 #include "rs-color-space-selector.h"
 
 #include "x86-cpu.h"
-
-#ifdef  __cplusplus
-} /* extern "c" */
-#endif
 
 #endif /* RAWSTUDIO_H */
