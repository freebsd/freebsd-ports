
$FreeBSD$

--- parse.c	2001/08/01 07:24:17	1.1
+++ parse.c	2001/08/01 07:25:02
@@ -952,9 +952,9 @@
     {
       char *output;
 
-      debug_spew ("Calling glib-config\n");
+      debug_spew ("Calling glib12-config\n");
       
-      pkg->version = backticks ("glib-config --version");
+      pkg->version = backticks ("glib12-config --version");
       if (pkg->version == NULL)
         {
           g_free (pkg);
@@ -965,12 +965,12 @@
       pkg->key = g_strdup ("glib");
       pkg->description = g_strdup ("C Utility Library");
 
-      output = backticks ("glib-config --libs");
-      parse_libs (pkg, output, "glib-config");
+      output = backticks ("glib12-config --libs");
+      parse_libs (pkg, output, "glib12-config");
       g_free (output);
 
-      output = backticks ("glib-config --cflags");
-      parse_cflags (pkg, output, "glib-config");
+      output = backticks ("glib12-config --cflags");
+      parse_cflags (pkg, output, "glib12-config");
       g_free (output);
 
       return pkg;
