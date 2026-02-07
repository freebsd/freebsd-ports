--- src/sound.c.orig	Sun Apr 11 01:27:01 2004
+++ src/sound.c	Thu Nov 10 05:14:05 2005
@@ -47,10 +47,12 @@
 {
 	Mix_Chunk * temp = NULL;
 	char * newname = NULL;
+	int len1, len2;
 
 	assert(name);
 
-	int len1 = strlen(sg_data_path), len2 = strlen(name);
+	len1 = strlen(sg_data_path);
+	len2 = strlen(name);
 
 	if(disabled)
 		return NULL;
