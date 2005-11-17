--- src/sound.c.orig	Wed Mar  3 04:03:54 2004
+++ src/sound.c	Thu Nov 10 05:29:19 2005
@@ -46,12 +46,13 @@
 Mix_Chunk * loadSound(const char * name)
 {
 	Mix_Chunk * temp;
+	char * newname;
 	int len1 = strlen(sg_data_path), len2 = strlen(name);
 
 	if(disabled)
 		return NULL;
 
-	char * newname = (char*)malloc(len1 + len2 + 1);
+	newname = (char*)malloc(len1 + len2 + 1);
 	if(newname == NULL) {
 		fprintf(stderr, "Out of memory!\n");
 		exit(1);
