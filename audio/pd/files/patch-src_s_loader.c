--- src/s_loader.c.orig	Wed Mar  6 18:58:30 2002
+++ src/s_loader.c	Fri May 24 23:12:25 2002
@@ -23,6 +23,9 @@
 typedef void (*t_xxx)(void);
 
 static char sys_dllextent[] = 
+#ifdef __FreeBSD__
+    ".pd_freebsd";
+#endif
 #ifdef IRIX
 #ifdef N32
     ".pd_irix6";
