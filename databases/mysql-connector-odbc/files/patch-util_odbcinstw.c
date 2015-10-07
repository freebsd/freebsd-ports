--- util/odbcinstw.c.orig	2015-03-26 15:10:03.189270855 +0300
+++ util/odbcinstw.c	2015-03-26 15:10:43.503271192 +0300
@@ -105,7 +105,8 @@
   x_free(section);
   x_free(entry);
   x_free(def);
-  x_free(ret);
+  if (ret)
+    free(ret);
   x_free(filename);
 
   return rc;
