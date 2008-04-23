diff -urN -urN -x .svn ../../vendor/curl/docs/examples/fileupload.c ./docs/examples/fileupload.c
--- ../../vendor/curl/docs/examples/fileupload.c	2008-03-19 12:29:25.000000000 +0200
+++ ./docs/examples/fileupload.c	2008-04-02 13:42:22.000000000 +0300
@@ -27,7 +27,11 @@
     return 1; /* can't continue */
   }
 
-  stat("debugit", &file_info); /* to get the file size */
+  /* to get the file size */
+  if(fstat(fileno(fd), &file_info) != 0) {
+
+    return 1; /* can't continue */
+  }
 
   curl = curl_easy_init();
   if(curl) {
