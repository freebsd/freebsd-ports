--- ext/ming/ming/util.c.orig	2003-09-28 13:30:20.000000000 +0900
+++ ext/ming/ming/util.c	2014-01-29 17:11:17.000000000 +0900
@@ -83,10 +83,10 @@
   if (fp != NULL)
 	return fp;
   
-  for(i = 0; i < RARRAY(path)->len; i++) {
-	item = RARRAY(path)->ptr[i];
-	dir = STR2CSTR(item);
-	dir_len = RSTRING(item)->len;
+  for(i = 0; i < RARRAY_LEN(path); i++) {
+	item = RARRAY_PTR(path)[i];
+	dir = StringValuePtr(item);
+	dir_len = RSTRING_LEN(item);
 
 	if(strncmp(&dir[dir_len - 1], delimiter, 1) != 0) {
 	  total_len = dir_len + len + 2;
