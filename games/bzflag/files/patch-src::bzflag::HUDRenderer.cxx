--- src/bzflag/HUDRenderer.cxx.orig	Tue Dec  9 16:38:59 2003
+++ src/bzflag/HUDRenderer.cxx	Thu Dec 11 00:58:54 2003
@@ -11,7 +11,7 @@
  */
 
 // system headers
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #endif
 #include <stdio.h>
