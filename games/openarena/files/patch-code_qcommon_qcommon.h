--- code/qcommon/qcommon.h.orig	2011-12-24 12:29:32 UTC
+++ code/qcommon/qcommon.h
@@ -1099,6 +1099,9 @@ char	*Sys_DefaultInstallPath(void);
 char    *Sys_DefaultAppPath(void);
 #endif
 
+void	Sys_SetDefaultLibPath(const char *path);
+char	*Sys_DefaultLibPath(void);
+
 void  Sys_SetDefaultHomePath(const char *path);
 char	*Sys_DefaultHomePath(void);
 const char	*Sys_TempPath(void);
