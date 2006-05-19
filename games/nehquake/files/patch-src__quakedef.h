--- ./src/quakedef.h.orig	Tue Sep 27 13:41:52 2005
+++ ./src/quakedef.h	Tue May 16 17:48:38 2006
@@ -337,7 +337,7 @@
 void Chase_Update (void);
 
 extern int bspversion;
-#ifdef __linux
+#ifdef __unix__
 #ifndef min
 #define min(a, b)  (((a) < (b)) ? (a) : (b))
 #endif
