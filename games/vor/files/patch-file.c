--- file.c.orig	Sun Mar 26 06:52:35 2006
+++ file.c	Mon Mar 27 02:30:51 2006
@@ -101,9 +101,9 @@
 {
 	int i;
 	char *data_options[3] = {
+		DATA_PREFIX,
 		getenv("VOR_DATA"),
 		"data",
-		DATA_PREFIX
 	};
 
 	for(i=0; i<3; i++) {
