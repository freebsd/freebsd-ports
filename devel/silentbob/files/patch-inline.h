--- include/inline.h.orig	2008-08-28 18:31:51.000000000 +0900
+++ include/inline.h	2008-11-13 15:53:51.000000000 +0900
@@ -109,7 +109,7 @@
 	return count;
 }
 
-#define find_one_ext(ext) sblib_find ((char *) "./", (char *) ext, ENV->tmp_files)
+#define find_one_ext(ext) sblib_find ((char *) ".", (char *) ext, ENV->tmp_files)
 
 #endif
 
