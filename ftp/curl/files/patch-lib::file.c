diff -urN -urN -x .svn ../../vendor/curl/lib/file.c ./lib/file.c
--- ../../vendor/curl/lib/file.c	2008-03-24 00:40:11.000000000 +0200
+++ ./lib/file.c	2008-04-02 13:17:43.000000000 +0300
@@ -344,7 +344,7 @@
 
   /* treat the negative resume offset value as the case of "-" */
   if(data->state.resume_from < 0) {
-    if(stat(file->path, &file_stat)) {
+    if(fstat(fileno(fp), &file_stat)) {
       fclose(fp);
       failf(data, "Can't get the size of %s", file->path);
       return CURLE_WRITE_ERROR;
