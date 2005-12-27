--- src/globals.h.orig	Sun Nov 27 15:34:38 2005
+++ src/globals.h	Sun Nov 27 15:34:57 2005
@@ -16,7 +16,7 @@
 #elif defined(__WXMAC__)
   #define APP_PLATFORM _T("Mac OS/X")
 #elif defined(__UNIX__)
-  #define APP_PLATFORM _T("Linux")
+  #define APP_PLATFORM _T("FreeBSD")
 #else
   #define APP_PLATFORM _T("Unknown")
 #endif
