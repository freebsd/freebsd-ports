--- prototyp.h.orig	Tue Sep  7 00:38:10 1999
+++ prototyp.h	Sun Dec  7 11:36:26 2003
@@ -372,13 +372,8 @@
 
 extern void calcfracinit(void);
 extern void adjust_corner(void);
-#ifndef XFRACT
 extern int put_resume(int ,... );
 extern int get_resume(int ,... );
-#else
-extern int put_resume();
-extern int get_resume();
-#endif
 extern int alloc_resume(int ,int );
 extern int start_resume(void);
 extern void end_resume(void);
@@ -604,11 +599,10 @@
 extern int pot_line(BYTE *,int );
 extern int sound_line(BYTE *,int );
 extern int sound_line(unsigned char *pixels,int linelen);
-#ifndef XFRACT
 extern int timer(int,int (*subrtn)(),...);
+#ifndef XFRACT
 extern int _cdecl _matherr(struct exception *);
 #else
-extern int timer();
 extern int XZoomWaiting;
 #endif
 
