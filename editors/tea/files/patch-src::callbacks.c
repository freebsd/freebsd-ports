--- src/callbacks.c.orig	Tue Jul 13 17:01:57 2004
+++ src/callbacks.c	Tue Jul 13 17:05:25 2004
@@ -24,6 +24,7 @@
 #include <gdk/gdk.h>
 #include <gdk/gdkkeysyms.h>
 
+#include <sys/param.h>
 #include <errno.h>
 #include <sys/stat.h>
 #include <glib.h>
@@ -1065,9 +1066,10 @@
   
   if (get_page_fnav ())
      {
+      char buf[MAXPATHLEN];
       gchar *fn = (gchar*) g_malloc (2048); 
       
-      if (realpath ((gchar *) get_current_dir_name (), fn))
+      if (getcwd(buf, sizeof(buf)) && realpath (buf, fn))
          set_fam_text (fn);
       else 
           set_fam_text ("/"); 
@@ -3005,9 +3007,10 @@
   
   if (get_page_fnav ())
      {
+      char buf[MAXPATHLEN];
       gchar *fn = (gchar*) g_malloc (2048); 
       
-      if (realpath ((gchar *) get_current_dir_name (), fn))
+      if (getcwd(buf, sizeof(buf)) && realpath (buf, fn))
          set_fam_text (fn);
       else 
           set_fam_text ("/"); 
