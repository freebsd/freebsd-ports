--- src/bsd/bsd_ioports.c.orig	Thu Apr 29 20:25:16 2004
+++ src/bsd/bsd_ioports.c	Wed Jun 29 23:29:42 2005
@@ -34,8 +34,10 @@
 #include <sys/ioctl.h>
 #include <fcntl.h>
 
+#ifdef __I386__
 #include <machine/sysarch.h>
 #include <machine/cpufunc.h>
+#endif
 
 #include "gettext.h"
 
@@ -55,6 +57,7 @@
 
 /* I/O thru assembly code */
 
+#ifdef __I386__
 static int bsd_asm_read_io(unsigned int addr)
 {
 	return inb(addr);
@@ -64,6 +67,7 @@
 {
 	outb(addr, data);
 }
+#endif
 
 
 /* I/O thru ioctl() calls */
