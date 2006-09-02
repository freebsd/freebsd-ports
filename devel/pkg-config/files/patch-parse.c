--- parse.c.orig	Sun Oct 16 13:09:39 2005
+++ parse.c	Sat Sep  2 14:09:44 2006
@@ -707,6 +707,16 @@ static void _do_parse_libs (Package *pkg
           i++;
           g_free(framework);
         }
+      else if ((strcmp("-Wl,--rpath",p) == 0 || strcmp("-Wl,-rpath",p) == 0) &&
+        i+1 < argc)
+        {
+          gchar *rpath = trim_string (argv[i+1]);
+
+          pkg->other_libs = g_slist_prepend (pkg->other_libs,
+                                             g_strconcat(arg, " ", rpath, NULL));
+          i++;
+          g_free(rpath);
+        }
       else
         {
           if (*arg != '\0')
@@ -1190,9 +1200,9 @@ get_compat_package (const char *name)
     {
       char *output;
 
-      debug_spew ("Calling glib-config\n");
+      debug_spew ("Calling glib12-config\n");
       
-      pkg->version = backticks ("glib-config --version");
+      pkg->version = backticks ("glib12-config --version");
       if (pkg->version == NULL)
         {
           g_free (pkg);
@@ -1203,12 +1213,12 @@ get_compat_package (const char *name)
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
