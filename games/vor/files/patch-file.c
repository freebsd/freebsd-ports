--- file.c.orig	2016-05-22 21:14:48 UTC
+++ file.c
@@ -113,7 +113,6 @@ find_data_dir(void)
 	int i;
 	char *data_options[3] = {
 		getenv("VOR_DATA"),
-		"data",
 		DATA_PREFIX
 	};
 
