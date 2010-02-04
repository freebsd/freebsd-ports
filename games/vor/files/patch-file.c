--- file.c.orig	2009-12-10 00:28:59.000000000 +0300
+++ file.c	2010-02-04 05:50:54.000000000 +0300
@@ -101,7 +101,6 @@
 	int i;
 	char *data_options[3] = {
 		getenv("VOR_DATA"),
-		"data",
 		DATA_PREFIX
 	};
 
