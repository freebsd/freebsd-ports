--- src/vc.c.orig	Mon Apr 15 09:46:27 1996
+++ src/vc.c	Tue Nov 26 12:02:07 2002
@@ -1,8 +1,10 @@
 /*
 	KON - Kanji ON Linux Console -
 	Copyright (C) 1992, 1993
-		MAEDA Atusi (mad@math.keio.ac.jp)
-		Takashi MANABE (manabe@tut.ac.jp)
+		MAEDA Atusi (mad
+math.keio.ac.jp)
+		Takashi MANABE (manabe
+tut.ac.jp)
 
 	KON is free software; you can redistribute it and/or modify it
 	under the terms of the GNU General Public License as published by
@@ -19,7 +21,8 @@
 	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 /*
-	modified for Big5Con by Hung-Chi Chu <hcchu@r350.ee.ntu.edu.tw>
+	modified for Big5Con by Hung-Chi Chu <hcchu
+r350.ee.ntu.edu.tw>
  */
 
 #include	<stdio.h>
@@ -35,7 +38,16 @@
 #include	<termio.h>
 #elif defined(__FreeBSD__)
 #include	<termios.h>
-#include	<machine/console.h>
+#include	<osreldate.h>
+#if __FreeBSD_version >= 410000
+#include	<sys/consio.h>
+#include	<sys/kbio.h>
+#else
+#include	<sys/consio.h>
+#include <sys/kbio.h>
+
+#endif
+
 #endif
 #include	<sys/ioctl.h>
 #ifdef linux
@@ -92,28 +104,26 @@
 inline	void	blatch(void *head, int n)
 {
 
-    __asm__("\t clc\n"
+    __asm__ volatile("\t clc\n"
 	    "1:\n"
 	    "\t andb %%bl, (%%eax)\n"
 	    "\t incl %%eax\n"
 	    "\t loop 1b\n"
-	    :
-	    : "eax" ((long)head), "bl" (0x7F), "c" (n)
-	    : "bl", "cx" );
+	    : "=bl" (head), "=c" (n)
+	    : "eax" ((long)head), "0" (0x7F), "1" (n));
 }
 
 static
 inline	void	llatch(void *head, int n)
 {
 
-    __asm__("\t clc\n"
+    __asm__ volatile ("\t clc\n"
 	    "1:\n"
 	    "\t andl %%ebx, (%%eax)\n"
 	    "\t addl $4, %%eax\n"
 	    "\t loop 1b\n"
-	    :
-	    : "eax" ((long)head), "ebx" (0x7F7F7F7F), "c" (n>>2)
-	    : "ebx", "cx" );
+	    : "=ebx" (head), "=c" (n)
+	    : "eax" ((long)head), "0" (0x7F7F7F7F), "1" (n>>2));
 }
 
 static inline u_int	TextAddress(u_int x, u_int y)
@@ -254,13 +264,23 @@
     struct vt_mode vtm;
 
     ioctl(0,KDSKBMODE,K_XLATE);
+#if defined(__FreeBSD__)
+    signal(SIGUSR1, SIG_IGN);
+    signal(SIGUSR2, SIG_IGN);
+#else	/* linux */
     signal(SIGUSR1, SIG_DFL);
     signal(SIGUSR2, SIG_DFL);
+#endif
     vtm.mode = VT_AUTO;
     vtm.waitv = 0;
+#if defined(__FreeBSD__)
+    vtm.relsig = SIGUSR1;
+    vtm.acqsig = SIGUSR2;
+    vtm.frsig = SIGUSR1;
+#else	/* linux */
     vtm.relsig = 0;
     vtm.acqsig = 0;
-    vtm.frsig = 0;
+#endif
     ioctl(0, VT_SETMODE, &vtm);
 #if defined(__FreeBSD__)
     ioctl(0, VT_RELDISP, 1);
@@ -287,13 +307,15 @@
     vtm.waitv = 0;
     vtm.relsig = SIGUSR1;
     vtm.acqsig = SIGUSR2;
-    vtm.frsig = SIGUSR1; /* not implemented, just a hack */
+#if defined(__FreeBSD__)
+    vtm.frsig = SIGUSR1;
+#endif
     ioctl(0, VT_SETMODE, &vtm);
     vInfo.graph_mode();
     if (useHardScroll)
 	vInfo.set_start_address();
     
-    win.ws_row = dInfo.tymax;	 /* Note: con.ymax may be changed by application */
+    win.ws_row = dInfo.tymax + 1;	 /* Note: con.ymax may be changed by application */
     win.ws_col = dInfo.txmax + 1;
     win.ws_xpixel = win.ws_ypixel = 0;
     ioctl(masterPty, TIOCSWINSZ, &win);
@@ -821,44 +843,30 @@
 
 static int	ConfigBeep(const char *confstr)
 {
-    beepCount = atoi(confstr) * 10000;
 #if defined(linux)
+    beepCount = atoi(confstr) * 10000;
     ioperm(COUNTER_ADDR, 1, TRUE);
 #endif
+#if defined(__FreeBSD__)
+    beepCount = atoi(confstr) * 10;
+#endif
     return SUCCESS;
 }
 
-/*
- * Sound() added by woju.bbs@freebsd.ee.ntu.edu.tw
- */
-static void Sound(int freq, int ms)
-{
-  PortOutb(182, 0x43);
-  PortOutb((100000 / freq) & 0xff, 0x42);
-  PortOutb((100000 / freq) >> 8, 0x42);
-  PortOutb(PortInb(0x61) | 3, 0x61);
-  usleep(ms * 1000);
-  PortOutb(PortInb(0x61) &0xfc, 0x61);
-}
-
-static void Bell()
-{
-   int i;
-
-   for (i = 1; i <= 5; i++)
-	Sound(i * 100, 10);
-}
+#define BELL_PITCH 800
 
 void	Beep(void)
 {
-    if (!con.active) return;
 #ifdef linux
+    if (!con.active) return;
     PortOutb(PortInb(COUNTER_ADDR)|3, COUNTER_ADDR);
     usleep(beepCount);
     PortOutb(PortInb(COUNTER_ADDR)&0xFC, COUNTER_ADDR);
 #endif
 #ifdef __FreeBSD__
-    Bell();
+    if(beepCount <= 0) return;
+    ioctl(fileno(stdout), KDMKTONE, (BELL_PITCH & 0xffff) |
+	((beepCount & 0xffff) << 16));
 #endif
 }
 
