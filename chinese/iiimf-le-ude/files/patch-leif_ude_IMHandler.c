--- leif/ude/IMHandler.c.orig	Wed May 18 03:17:57 2005
+++ leif/ude/IMHandler.c	Wed May 18 03:18:24 2005
@@ -71,7 +71,7 @@
 	if(ct_list == NULL) {
 
 #ifndef WIN32
-		strcat(ct_path, "/../locale/zh_CN/ude/data");
+		strcat(ct_path, "data");
 #else
 		strcat(ct_path, "\\..\\locale\\zh_CN\\ude\\data");
 #endif
