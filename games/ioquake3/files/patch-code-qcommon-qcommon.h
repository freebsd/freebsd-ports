--- code/qcommon/qcommon.h.orig	2009-01-17 23:09:58 UTC
+++ code/qcommon/qcommon.h
@@ -1069,6 +1069,9 @@ char	*Sys_DefaultInstallPath(void);
 char    *Sys_DefaultAppPath(void);
 #endif
 
+void	Sys_SetDefaultLibPath(const char *path);
+char	*Sys_DefaultLibPath(void);
+
 void  Sys_SetDefaultHomePath(const char *path);
 char	*Sys_DefaultHomePath(void);
 const char *Sys_Dirname( char *path );
