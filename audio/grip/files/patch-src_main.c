--- src/main.c.orig	2005-06-25 18:00:55 UTC
+++ src/main.c
@@ -164,7 +164,7 @@ int Cmain(int argc, char* argv[])
 		     GNOME_PARAM_POPT_TABLE,options,
 		     GNOME_PROGRAM_STANDARD_PROPERTIES,NULL);
 
-  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF8");
+  bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
   setenv("CHARSET","UTF-8",1);
 
   /* Session Management */
