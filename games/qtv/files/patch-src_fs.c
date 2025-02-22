--- src/fs.c.orig	2025-02-16 14:10:58 UTC
+++ src/fs.c
@@ -119,6 +119,7 @@ void FS_StripPathAndExtension(char *filepath)
 	size_t lastslash = (size_t) -1;
 	size_t lastdot   = (size_t) -1;
 	size_t i		 = 0;
+	char temp_filepath[MAX_QPATH];
 
 	for ( ; filepath[i]; i++)
 	{
@@ -131,7 +132,8 @@ void FS_StripPathAndExtension(char *filepath)
 	if (lastdot == (size_t) -1 || lastdot < lastslash)
 		lastdot = i;
 
-	strlcpy(filepath, filepath + lastslash + 1, lastdot - lastslash);
+	strlcpy(temp_filepath, filepath + lastslash + 1, lastdot - lastslash);
+	strlcpy(filepath, temp_filepath, sizeof(temp_filepath));
 }
 
 // return file extension with dot, or empty string if dot not found at all
