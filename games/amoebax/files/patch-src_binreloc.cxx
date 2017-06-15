--- src/binreloc.cxx.orig	2007-05-27 15:04:33 UTC
+++ src/binreloc.cxx
@@ -739,7 +739,8 @@ br_strndup (const char *str, size_t size
 char *
 br_dirname (const char *path)
 {
-	char *end, *result;
+	const char *end;
+	char *result;
 
 	if (path == (const char *) NULL)
 		return (char *) NULL;
