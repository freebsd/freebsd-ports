--- src/Window/event.gen.h.orig	Mon Dec 10 19:47:09 2001
+++ src/Window/event.gen.h	Sun Nov 24 22:30:56 2002
@@ -19,7 +19,10 @@
 
 #ifndef _TIME_T
 #define _TIME_T
-typedef long time_t;
+#ifndef	_BSD_TIME_T_    
+#define	_BSD_TIME_T_	int
+#endif
+typedef _BSD_TIME_T_ time_t;
 #endif
 
 class window_rep;
