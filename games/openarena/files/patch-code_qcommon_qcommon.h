--- code/qcommon/qcommon.h.orig	2011-12-24 12:29:32 UTC
+++ code/qcommon/qcommon.h
@@ -571,6 +571,12 @@ issues.
 ==============================================================
 */
 
+#define MAX_ZPATH			256
+#define	MAX_SEARCH_PATHS	4096
+
+extern int dangerousPaksFound;
+extern char dangerousPakNames[MAX_ZPATH][MAX_SEARCH_PATHS];
+
 // referenced flags
 // these are in loop specific order so don't change the order
 #define FS_GENERAL_REF	0x01
@@ -627,7 +633,7 @@ fileHandle_t	FS_FOpenFileAppend( const c
 
 fileHandle_t FS_SV_FOpenFileWrite( const char *filename );
 int		FS_SV_FOpenFileRead( const char *filename, fileHandle_t *fp );
-void	FS_SV_Rename( const char *from, const char *to );
+void	FS_SV_Rename( const char *from, const char *to, qboolean safe );
 int		FS_FOpenFileRead( const char *qpath, fileHandle_t *file, qboolean uniqueFILE );
 // if uniqueFILE is true, then a new FILE will be fopened even if the file
 // is found in an already open pak file.  If uniqueFILE is false, you must call
@@ -1099,6 +1105,9 @@ char	*Sys_DefaultInstallPath(void);
 char    *Sys_DefaultAppPath(void);
 #endif
 
+void	Sys_SetDefaultLibPath(const char *path);
+char	*Sys_DefaultLibPath(void);
+
 void  Sys_SetDefaultHomePath(const char *path);
 char	*Sys_DefaultHomePath(void);
 const char	*Sys_TempPath(void);
