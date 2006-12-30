--- qw/source/cl_sys_unix.c.orig	Tue Feb 11 19:48:57 2003
+++ qw/source/cl_sys_unix.c	Sat Dec 30 16:44:33 2006
@@ -56,6 +56,7 @@
 #include "QF/console.h"
 #include "QF/qargs.h"
 #include "QF/sys.h"
+#include "QF/progs.h"
 
 #include "host.h"
 #include "netchan.h"
@@ -72,6 +73,9 @@
 }
 
 int         skipframes;
+
+extern void Key_Progs_Init (progs_t *pr);
+void (*x)() = Key_Progs_Init;
 
 int
 main (int c, const char *v[])
