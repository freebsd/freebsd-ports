--- src/main.c.orig	2010-04-13 08:46:10.000000000 -0300
+++ src/main.c	2010-04-13 08:46:45.000000000 -0300
@@ -164,7 +164,7 @@
 		     GNOME_PARAM_POPT_TABLE,options,
 		     GNOME_PROGRAM_STANDARD_PROPERTIES,NULL);
 
-  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF8");
+  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
   setenv("CHARSET","UTF-8",1);
 
   /* Session Management */
