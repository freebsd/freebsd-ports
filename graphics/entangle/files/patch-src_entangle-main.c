--- src/entangle-main.c.orig	2017-10-10 21:07:59 UTC
+++ src/entangle-main.c
@@ -23,7 +23,7 @@
 
 #include <gst/gst.h>
 #include <gtk/gtk.h>
-#include <girepository.h>
+#include <girepository/girepository.h>
 #include <glib/gi18n.h>
 
 #include "entangle-debug.h"
@@ -76,8 +76,10 @@ int main(int argc, char **argv)
 
     gst_init(NULL, NULL);
 
-    if (ins) {
-        g_irepository_dump(ins, NULL);
+    char **args;
+    if (ins && (args = g_strsplit(ins, ",", 2))) {
+        gi_repository_dump(args[0], args[1], NULL);
+        g_strfreev(args);
         return 0;
     }
 
