--- hwaredriver.c.orig	Tue May 18 09:43:30 2004
+++ hwaredriver.c	Fri Jul  9 11:26:15 2004
@@ -1,6 +1,6 @@
 
 #include <vga.h>
-#include <sys/io.h>
+#include <machine/cpufunc.h>
 #include <ctype.h>
 #include "conf.h"
 #include "globdef.h"
@@ -169,7 +169,7 @@
 void users_open_devices(void)
 {
 // Get permission to write to the parallel port
-ioperm(HWARE_PORT,4,1);
+i386_set_ioperm(HWARE_PORT,4,1);
 allow_parport=1;
 }
 
