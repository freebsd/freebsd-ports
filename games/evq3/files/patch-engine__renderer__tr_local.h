--- ./engine/renderer/tr_local.h.orig	Tue Apr  3 14:30:38 2007
+++ ./engine/renderer/tr_local.h	Mon Apr 16 23:58:54 2007
@@ -33,7 +33,7 @@
 typedef unsigned int glIndex_t;
 
 // fast float to int conversion
-#if id386 && !( (defined __linux__ || defined __FreeBSD__ ) && (defined __i386__ ) )	// rb010123
+#if id386 && !( (defined __unix__ ) && (defined __i386__ ) )	// rb010123
 long            myftol(float f);
 #else
 #define	myftol(x) ((int)(x))
