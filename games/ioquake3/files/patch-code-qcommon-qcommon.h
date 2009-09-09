--- code/qcommon/qcommon.h.orig	2009-08-30 23:12:19.000000000 +0200
+++ code/qcommon/qcommon.h	2009-08-30 23:26:12.000000000 +0200
@@ -1068,6 +1068,10 @@
 #ifdef MACOS_X
 char    *Sys_DefaultAppPath(void);
 #endif
+#ifdef __FreeBSD__
+void	Sys_SetDefaultLibPath(const char *path);
+char	*Sys_DefaultLibPath(void);
+#endif
 
 void  Sys_SetDefaultHomePath(const char *path);
 char	*Sys_DefaultHomePath(void);
