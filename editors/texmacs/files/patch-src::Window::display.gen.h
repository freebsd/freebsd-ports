--- src/Window/display.gen.h.orig	Sun Feb 10 20:37:01 2002
+++ src/Window/display.gen.h	Sun Nov 24 22:30:06 2002
@@ -19,7 +19,10 @@
 
 #ifndef _TIME_T
 #define _TIME_T
-typedef long time_t;
+#ifndef	_BSD_TIME_T_    
+#define	_BSD_TIME_T_	int
+#endif
+typedef _BSD_TIME_T_ time_t;
 #endif
 
 class font;
