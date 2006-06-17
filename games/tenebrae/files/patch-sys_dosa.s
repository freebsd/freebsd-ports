--- ./sys_dosa.s.orig	Sat Jun 10 12:08:13 2006
+++ ./sys_dosa.s	Sat Jun 10 12:08:13 2006
@@ -5,6 +5,7 @@
 #include "asm_i386.h"
 #include "quakeasm.h"
 
+#if id386
 
 	.data
 
@@ -93,3 +94,4 @@
 
 	ret
 
+#endif
