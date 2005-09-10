--- file.c.orig	Wed Sep  7 05:00:47 2005
+++ file.c	Wed Sep  7 05:01:01 2005
@@ -58,20 +58,19 @@
 find_data_dir(void)
 {
 	int i;
-	char *data_options[3] = {
-		"./data",
+	char *data_options[2] = {
 		getenv("VOR_DATA"),
 		DATA_PREFIX
 	};
 
-	for(i=0; i<3; i++) {
+	for(i=0; i<2; i++) {
 		if(!data_options[i]) continue;
 		g_data_dir = strdup(data_options[i]);
 		if(is_dir(g_data_dir)) return true;
 	}
 
 	fprintf(stderr, "Can't find VoR data! Tried:\n");
-	for(i=0; i<3; i++) {
+	for(i=0; i<2; i++) {
 		fprintf(stderr, "\t%s\n", data_options[i]);
 	}
 	return false;
