--- code/qcommon/qcommon.h.orig	2009-12-08 11:09:48.000000000 +0100
+++ code/qcommon/qcommon.h	2009-12-08 11:10:43.000000000 +0100
@@ -1069,6 +1069,9 @@
 char    *Sys_DefaultAppPath(void);
 #endif
 
+void	Sys_SetDefaultLibPath(const char *path);
+char	*Sys_DefaultLibPath(void);
+
 void  Sys_SetDefaultHomePath(const char *path);
 char	*Sys_DefaultHomePath(void);
 const char *Sys_Dirname( char *path );
