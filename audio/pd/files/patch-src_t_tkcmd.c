--- src/t_tkcmd.c.orig	Sat Dec 31 21:08:37 2005
+++ src/t_tkcmd.c	Sun Mar 25 12:12:15 2007
@@ -50,6 +50,10 @@
 #define STARTGUI
 #endif
 
+#ifdef __FreeBSD__
+#define STARTGUI
+#endif
+
 #define FIRSTPORTNUM 5600
 
 void tcl_mess(char *s);
