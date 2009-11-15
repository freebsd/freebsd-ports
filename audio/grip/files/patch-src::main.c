--- src/main.c.orig
+++ src/main.c
@@ -163,7 +163,7 @@
 		     GNOME_PARAM_POPT_TABLE,options,
 		     GNOME_PROGRAM_STANDARD_PROPERTIES,NULL);
 
-  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF8");
+  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
 
   /* Session Management */
   
