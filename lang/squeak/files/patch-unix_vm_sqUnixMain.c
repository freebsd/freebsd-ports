--- unix/vm/sqUnixMain.c.orig	2012-09-17 01:03:14 UTC
+++ unix/vm/sqUnixMain.c
@@ -1334,8 +1334,8 @@ void imgInit(void)
 			|| defined(POWERPC) || defined(__POWERPC) || defined (__POWERPC__) )
   void mtfsfi(unsigned long long fpscr)
   {
-    __asm__("lfd   f0, %0" :: "m"(fpscr));
-    __asm__("mtfsf 0xff, f0");
+    __asm__("lfd   0, %0" :: "m"(fpscr));
+    __asm__("mtfsf 0xff, 0");
   }
 #else
 # define mtfsfi(fpscr)
