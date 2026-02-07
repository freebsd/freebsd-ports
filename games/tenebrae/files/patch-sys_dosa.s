--- sys_dosa.s.orig	2020-09-30 11:25:10 UTC
+++ sys_dosa.s
@@ -5,6 +5,7 @@
 #include "asm_i386.h"
 #include "quakeasm.h"
 
+#if id386
 
 	.data
 
@@ -93,3 +94,4 @@ C(Sys_SetFPCW):
 
 	ret
 
+#endif
