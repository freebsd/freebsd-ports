--- src/md5sum/md5file.h.orig	Sun May 21 17:45:47 2006
+++ src/md5sum/md5file.h	Sun May 21 17:46:02 2006
@@ -2,6 +2,7 @@
 #define MD5FILE
 
 #include <string>
+#include <stdio.h>
 
 std::string md5file(std::string p_filename);
 
