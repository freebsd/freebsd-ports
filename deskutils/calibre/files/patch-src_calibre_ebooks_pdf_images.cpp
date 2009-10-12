--- src/calibre/ebooks/pdf/images.cpp.orig	2009-10-11 23:25:44.000000000 +0400
+++ src/calibre/ebooks/pdf/images.cpp	2009-10-11 23:25:51.000000000 +0400
@@ -157,7 +157,7 @@
         delete writer;
 
         free(row);
-        imgStr->close();
+//        imgStr->close();
         delete imgStr;
 
     }
