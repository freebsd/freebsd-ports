--- plugins/dfbinimage2/defines.h.orig	2010-04-20 06:30:12.862325658 +0000
+++ plugins/dfbinimage2/defines.h	2010-04-20 06:30:50.977164904 +0000
@@ -126,7 +126,9 @@
     HWND          HWnd;        // Window handle
     HINSTANCE     HInstance;
 } FPSEWin32;
+#endif
 
+#if defined _WINDOWS || defined __CYGWIN32__ || defined __FreeBSD__
 // cdr stat struct
 struct CdrStat
 {
@@ -134,7 +136,6 @@
  unsigned long Status;
  unsigned char Time[3]; // current playing time
 };
-
 #endif
 
 // Main Struct for initialization
