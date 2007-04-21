--- ./engine/qcommon/vm_x86.c.orig	Sat Dec 16 17:45:12 2006
+++ ./engine/qcommon/vm_x86.c	Tue Apr 17 00:09:12 2007
@@ -62,7 +62,9 @@
 
 static	int		*instructionPointers = NULL;
 
+#ifndef __FreeBSD__
 #define FTOL_PTR
+#endif
 
 #ifdef _MSC_VER
 
