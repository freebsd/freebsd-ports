--- src/wvisualwaveform.cpp.orig	Fri Jun 25 20:55:03 2004
+++ src/wvisualwaveform.cpp	Fri Jun 25 20:55:19 2004
@@ -36,7 +36,7 @@
 #ifdef __WIN__
     startTimer(15);
 #endif
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     startTimer(15);
 #endif
 
