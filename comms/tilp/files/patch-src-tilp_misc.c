--- src/tilp_misc.c.orig	Mon Apr 21 14:30:31 2003
+++ src/tilp_misc.c	Mon Apr 21 12:44:08 2003
@@ -78,7 +78,7 @@
 	options.web_options = g_strdup("");
 	strcpy(options.left_font_name, "");
 	strcpy(options.right_font_name,
-	       "-adobe-courier-medium-r-*-*-*-125-*-*-*-*-*-*");
+	       "-adobe-courier-medium-r-*-*-*-120-*-*-*-*-*-*");
 	options.console_mode = !0;
 	locale = setlocale(LC_ALL, NULL);
 	strcpy(options.locale, locale);
