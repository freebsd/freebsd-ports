--- ccmain/applybox.cpp.orig	2009-04-14 09:59:39.000000000 +0000
+++ ccmain/applybox.cpp	2009-04-14 10:06:23.000000000 +0000
@@ -195,6 +195,7 @@
     bad_blobs);
   tprintf ("				Final labelled words:     %6d\n",
     final_labelled_blob_count);
+  fclose(box_file);
 }
 
 
