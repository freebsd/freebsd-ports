--- src/prefix.cpp.orig	Sun Nov 27 14:16:01 2005
+++ src/prefix.cpp	Sun Nov 27 14:17:14 2005
@@ -32,7 +32,7 @@
 
 #ifndef BR_PTHREADS
 	/* Change 1 to 0 if you don't want pthread support */
-	#define BR_PTHREADS 1
+	#define BR_PTHREADS 0
 #endif /* BR_PTHREADS */
 
 #include <stdlib.h>
@@ -101,11 +101,11 @@
 	FILE *f;
 	char *path;
 
-	br_return_val_if_fail (symbol != NULL, NULL);
+	br_return_val_if_fail (symbol != NULL, (char*)NULL);
 
 	f = fopen ("/proc/self/maps", "r");
 	if (!f)
-		return NULL;
+		return (char*)NULL;
 
 	while (!feof (f))
 	{
@@ -143,7 +143,7 @@
 	}
 
 	fclose (f);
-	return NULL;
+	return (char*)NULL;
 }
 
 
@@ -165,10 +165,10 @@
 {
 	char *path, *prefix;
 
-	br_return_val_if_fail (symbol != NULL, NULL);
+	br_return_val_if_fail (symbol != NULL, (char*)NULL);
 
 	path = br_locate (symbol);
-	if (!path) return NULL;
+	if (!path) return (char*)NULL;
 
 	prefix = br_extract_prefix (path);
 	free (path);
@@ -195,11 +195,11 @@
 {
 	char *tmp, *newpath;
 
-	br_return_val_if_fail (symbol != NULL, NULL);
-	br_return_val_if_fail (path != NULL, NULL);
+	br_return_val_if_fail (symbol != NULL, (char*)NULL);
+	br_return_val_if_fail (path != NULL, (char*)NULL);
 
 	tmp = br_locate_prefix (symbol);
-	if (!tmp) return NULL;
+	if (!tmp) return (char*)NULL;
 
 	if (strcmp (tmp, "/") == 0)
 		newpath = strdup (path);
@@ -207,7 +207,7 @@
 		newpath = br_strcat (tmp, path);
 
 	/* Get rid of compiler warning ("br_prepend_prefix never used") */
-	if (0) br_prepend_prefix (NULL, NULL);
+	if (0) br_prepend_prefix (NULL, (char*)NULL);
 
 	free (tmp);
 	return newpath;
