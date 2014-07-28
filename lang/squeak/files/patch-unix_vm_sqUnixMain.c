--- unix/vm/sqUnixMain.c.bak	2013-12-05 13:49:51 -0800
+++ unix/vm/sqUnixMain.c
@@ -1334,8 +1334,8 @@
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
