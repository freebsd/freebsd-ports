--- src/lilydirectives.c.orig	2009-08-24 03:03:26.000000000 +0900
+++ src/lilydirectives.c	2009-09-28 17:25:00.000000000 +0900
@@ -1966,7 +1966,7 @@
     return ret;
   }
   GError *error = (GError*)execute_script_file(filename);
-  if(error) g_warning(error->message);
+  if(error) g_warning("%s", error->message);
   g_free(filename);
   return ret;
 }
