--- ./mousepad/main.c.orig	2012-12-30 11:04:01.000000000 +0000
+++ ./mousepad/main.c	2012-12-30 15:35:18.000000000 +0000
@@ -72,6 +72,7 @@
 
   /* bind the text domain to the locale directory */
   bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
+  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
 
   /* set the package textdomain */
   textdomain (GETTEXT_PACKAGE);
