--- src/vga.c.orig	Sun Apr 14 16:40:40 1996
+++ src/vga.c	Tue Nov 26 11:38:34 2002
@@ -1,6 +1,7 @@
 /*
   KON - Kanji ON Linux Console -
-  Copyright (C) 1992, 1993, 1994 Takashi MANABE (manabe@tut.ac.jp)
+  Copyright (C) 1992, 1993, 1994 Takashi MANABE (manabe
+tut.ac.jp)
   
   KON is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
@@ -20,7 +21,8 @@
 /*
   This code is based on vgalib.
   
-  Thanks to frandsen@diku.dk (Tommy Frandsen).
+  Thanks to frandsen
+diku.dk (Tommy Frandsen).
   */
 
 #include	<stdio.h>
@@ -35,7 +37,14 @@
 #elif defined(__FreeBSD__)
 #include	<vm/vm_param.h>
 #include	<sys/ioctl.h>
+#include	<osreldate.h>
+#if __FreeBSD_version > 410000
+#include	<sys/consio.h>
+#include	<sys/kbio.h>
+#else
 #include	<machine/console.h>
+#endif
+
 vm_size_t page_size;
 #endif
 #undef free
@@ -205,7 +214,8 @@
 	regText.seq[i] = PortInb(VGASEQ_DATA);
     }
     regText.mis = PortInb(VGAMISC_IN);
-    
+
+    PortOutb(PortInb(VGAMISC_IN)|0x01, VGAMISC_OUT);
     VgaSetRegisters(&regGraph);
     
     /* save font data in plane 2 */
@@ -369,7 +379,7 @@
 /*    if (!code) return;*/
     VgaSetColor(fc);
     if (bc & 0x8) *(vcls - dInfo.glineByte) = 0;
-    for (x = 0;x < sbFReg->high;x ++, code ++, fm >>= 1) {
+    if (code) for (x = 0;x < sbFReg->high;x ++, code ++, fm >>= 1) {
 	if (*code) {
 	    VgaOutByte(*code);
 	    *gram = *gram;
@@ -437,7 +447,7 @@
 
 void VgaCursor(struct cursorInfo *ci)
 {
-    char	*gram;
+    volatile char	*gram;
     u_char	x;
     int	bottom = cursorBtm + 1 <= dInfo.glineChar ?
 	cursorBtm + 1 : dInfo.glineChar;
@@ -607,7 +617,11 @@
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
