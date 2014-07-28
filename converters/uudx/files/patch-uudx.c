--- uudx.c.orig	Sun Jan 29 16:44:42 1995
+++ uudx.c	Sat Feb 12 19:31:31 2000
@@ -89,7 +89,11 @@
 #else
 #define strchr		index
 extern char	*strchr();
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 extern char	*sprintf();
+#else
+extern int	sprintf();
+#endif
 extern char	*strcpy();
 #endif /* BSD */
 
@@ -346,7 +350,7 @@
 		norm_dir(work_file_name, p);
 	}
 	strcat(work_file_name, "udXXXXXX");
-	if (mktemp(work_file_name) == NULL) {
+	if (mkstemp(work_file_name) == NULL) {
 		cant("make", "work_file_name", 1);
 		/* NOTREACHED */
 	}
