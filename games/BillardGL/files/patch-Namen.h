--- Namen.h.orig	Sat Jan  3 16:33:42 2004
+++ Namen.h	Sat Jan  3 16:34:03 2004
@@ -23,7 +23,7 @@
 #define TUTORIAL 105
 
 #ifndef _WIN32
-#define PFAD "/usr/share/BillardGL/"
+#define PFAD "%%X11BASE%%/share/%%PORTNAME%%/"
 #endif
 
 #ifndef PFAD
