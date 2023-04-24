--- arcmisc.c.orig	2013-06-27 02:00:19 UTC
+++ arcmisc.c
@@ -6,7 +6,9 @@
  */
 
 #include <stdio.h>
+#include <stdarg.h>
 #include <ctype.h>
+#include <unistd.h>
 #include "arc.h"
 
 #include <string.h>
@@ -68,7 +70,6 @@ chdir(dirname)
 #define DIRECT direct
 #endif
 #include <sys/stat.h>
-	int	rename(), unlink();
 #include <fcntl.h>
 #endif
 
@@ -110,7 +111,7 @@ move(oldnam, newnam)
 move(oldnam, newnam)
 	char           *oldnam, *newnam;
 {
-	FILE           *fopen(), *old, *new;
+	FILE           *old, *new;
 #if	!_MTS
 	struct stat     oldstat;
 #endif
@@ -225,11 +226,13 @@ VOID
 }
 /* VARARGS1 */
 VOID
-arcdie(s, arg1, arg2, arg3)
-	char           *s;
+arcdie(const char *s, ...)
 {
+	va_list args;
 	fprintf(stderr, "ARC: ");
-	fprintf(stderr, s, arg1, arg2, arg3);
+	va_start(args, s);
+	vfprintf(stderr, s, args);
+	va_end(args);
 	fprintf(stderr, "\n");
 #if	UNIX
 	perror("UNIX");
@@ -247,7 +250,6 @@ gcdir(dirname)
 	char           *dirname;
 
 {
-	char           *getcwd();
 #if	GEMDOS
 	int             drv;
 	char           *buf;
@@ -310,11 +312,7 @@ dir(filename)		/* get files, one by one */
 	static struct DIRECT **namelist;
 	static char   **NameList;
 	static char	namecopy[STRLEN], *dirname;
-#if	UNIX
-	int             alphasort();
-	int             scandir();
-#endif				/* UNIX */
-	int             fmatch();
+	int fmatch(const struct DIRECT *);
 	static int      Nnum = 0, ii;
 
 
@@ -354,10 +352,9 @@ int
  */
 
 int
-fmatch(direntry)
-	struct DIRECT  *direntry;
+fmatch(const struct DIRECT  *direntry)
 {
-	char           *string;
+	const char           *string;
 
 	string = direntry->d_name;
 
