--- src/display/vga.c.orig	1997-01-26 18:05:00.000000000 +0900
+++ src/display/vga.c	2012-05-10 00:14:28.911551261 +0900
@@ -47,10 +47,15 @@
 #elif defined(__FreeBSD__)
 #include      <vm/vm_param.h>
 #include      <sys/ioctl.h>
-#include      <machine/console.h>
+#include      <osreldate.h>
+#if __FreeBSD_version >= 410000
+#  include    <sys/consio.h>
+#  include    <sys/kbio.h>
+#else
+#  include    <machine/console.h>
+#endif
 vm_size_t page_size;
 #endif
-#undef free
 #include	<stdlib.h>
 
 #include	<mem.h>
@@ -382,7 +387,7 @@
 /*    if (!code) return;*/
     VgaSetColor(fc);
     if (bc & 0x8) *(vcls - dInfo.glineByte) = 0;
-    for (x = 0;x < sbFReg->high;x ++, code ++, fm >>= 1) {
+    if (code) for (x = 0;x < sbFReg->high;x ++, code ++, fm >>= 1) {
 	if (*code) {
 	    VgaOutByte(*code);
 	    *gram = *gram;
@@ -620,7 +625,11 @@
 	Perror("ioctl CONSOLE_IO_ENABLE");
 	return FAILURE;
     }
+#if (__FreeBSD__ <= 3)
     if ((devMem = open("/dev/vga", O_RDWR|O_NDELAY) ) < 0) {
+#else
+    if ((devMem = open("/dev/mem", O_RDWR|O_NDELAY) ) < 0) {
+#endif
 	Perror("/dev/mem");
 	return FAILURE;
     }
@@ -681,10 +690,9 @@
 
     munmap(gramMem, dInfo.gsize);
     
-    SafeFree((void **)&gramMem);
-    SafeFree((void **)&fontBuff1);
+    SafeFree(fontBuff1);
     if (savePlane3)
-	SafeFree((void **)&fontBuff2);
+	SafeFree(fontBuff2);
 }
 
 /* Configure */
