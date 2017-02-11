--- src/lhdir.h.orig	2000-10-04 14:57:38 UTC
+++ src/lhdir.h
@@ -30,6 +30,6 @@ typedef struct {
 /* ------------------------------------------------------------------------ */
 /*	Functions																*/
 /* ------------------------------------------------------------------------ */
-extern DIR     		 *opendir();
-extern struct direct *readdir();
-extern int			 closedir();
+extern DIR     		 *opendir(char *name);
+extern struct direct *readdir(register DIR *dirp);
+extern int			 closedir(DIR *dirp);
