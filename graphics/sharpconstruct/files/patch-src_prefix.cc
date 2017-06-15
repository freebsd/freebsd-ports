--- src/prefix.cc.orig	2005-08-22 01:24:14 UTC
+++ src/prefix.cc
@@ -393,7 +393,8 @@ br_strndup (char *str, size_t size)
 char *
 br_extract_dir (const char *path)
 {
-	char *end, *result;
+	const char *end;
+	char *result;
 
 	br_return_val_if_fail (path != (char *) NULL, (char *) NULL);
 
@@ -428,7 +429,8 @@ br_extract_dir (const char *path)
 char *
 br_extract_prefix (const char *path)
 {
-	char *end, *tmp, *result;
+	const char *end;
+	char *tmp, *result;
 
 	br_return_val_if_fail (path != (char *) NULL, (char *) NULL);
 
