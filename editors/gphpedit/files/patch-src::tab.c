--- src/tab.c.orig	Sat Dec 18 14:32:38 2004
+++ src/tab.c	Sat Dec 18 14:46:22 2004
@@ -407,46 +407,81 @@
 GString *tab_help_find_helpfile(gchar *command)
 {
 	GString *long_filename = NULL;
-	
-	// For Redhat/Fedora Core and sensible distrubutions...
-	long_filename = tab_help_try_filename("/usr/share/doc/phpmanual/function.", command, ".html");
+
+	/* br (Brazillian) */
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-br/function.", command, ".html");
+	if (long_filename)
+		return long_filename;
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-br/ref.", command, ".html");
+	if (long_filename)
+		return long_filename;
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-br/", command, NULL);
+	if (long_filename)
+		return long_filename;
+
+	/* de (German) */
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-de/function.", command, ".html");
+	if (long_filename)
+		return long_filename;
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-de/ref.", command, ".html");
+	if (long_filename)
+		return long_filename;
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-de/", command, NULL);
+	if (long_filename)
+		return long_filename;
+
+	/* en (English) */
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-en/function.", command, ".html");
+	if (long_filename)
+		return long_filename;
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-en/ref.", command, ".html");
+	if (long_filename)
+		return long_filename;
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-en/", command, NULL);
+	if (long_filename)
+		return long_filename;
+
+	/* es (Spanish) */
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-es/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/phpmanual/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-es/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/phpmanual/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-es/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
-	// For Gentoo, as much as I love it - it's twatty to put docs in a version specific folder like this!
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-200403/html/function.", command, ".html");
+	/* fr (French) */
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-fr/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-200403/html/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-fr/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-200403/html/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-fr/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
-	long_filename = tab_help_try_filename("/usr/share/doc/php-docs-200403/html/function.", command, ".html");
+	/* ja (Japanese) */
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-ja/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/php-docs-200403/html/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-ja/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/php-docs-200403/html/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-ja/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-4.2.3/html/function.", command, ".html");
+	/* pl (Polish) */
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-pl/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-4.2.3/html/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-pl/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-4.2.3/html/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-pl/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
