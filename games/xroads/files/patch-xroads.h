--- xroads.h.orig	Sat Nov 20 09:50:11 2004
+++ xroads.h	Sat Nov 20 09:49:42 2004
@@ -33,7 +33,7 @@
 void killme( char * );
 void xconnect( int, char *[] );
 int ntrunc( float );
-int round( float );
+int xrround( float );
 #ifdef SIGHANDLE
 void sigcatch( int );
 #endif
