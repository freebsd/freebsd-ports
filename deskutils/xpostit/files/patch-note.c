--- note.c.orig	1992-12-11 13:04:16 UTC
+++ note.c
@@ -100,7 +100,7 @@ static char	*RCSid = "$Header: /home/harbor/davy/stuff
 #include <X11/Xaw/Form.h>
 #include <X11/Shell.h>
 #include <sys/param.h>
-#if defined(USG) || defined(SYSV) || defined(SVR4)
+#if defined(USG) || defined(SYSV) || defined(SVR4) || defined(BSD)
 #include <dirent.h>
 #else
 #include <sys/dir.h>
@@ -240,7 +240,7 @@ LoadSavedNotes()
 	FILE *fp;
 	char *realloc();
 	register PostItNote *pn;
-#if defined(USG) || defined(SYSV) || defined(SVR4)
+#if defined(USG) || defined(SYSV) || defined(SVR4) || defined(BSD)
 	register struct dirent *d;
 #else
 	register struct direct *d;
