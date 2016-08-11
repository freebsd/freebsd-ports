--- uudx.c.orig	2016-04-13 10:36:35 UTC
+++ uudx.c
@@ -87,10 +87,15 @@ struct utimbuf {
 #if !BSD
 #include <string.h>
 #else
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 #define strchr		index
 extern char	*strchr();
 extern char	*sprintf();
 extern char	*strcpy();
+#else
+#include <string.h>
+#include <unistd.h>
+#endif
 #endif /* BSD */
 
 #define	NAMLEN		256
@@ -346,7 +351,7 @@ main(int argc, char *argv[])
 		norm_dir(work_file_name, p);
 	}
 	strcat(work_file_name, "udXXXXXX");
-	if (mktemp(work_file_name) == NULL) {
+	if (mkstemp(work_file_name) == NULL) {
 		cant("make", "work_file_name", 1);
 		/* NOTREACHED */
 	}
