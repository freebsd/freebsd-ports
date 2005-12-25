--- src/tab.c.orig	Sun Oct 16 13:24:52 2005
+++ src/tab.c	Sun Dec 25 09:48:30 2005
@@ -520,56 +520,66 @@
 {
 	GString *long_filename = NULL;
 	
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-en/function.", command, ".html");
+	if (long_filename)
+		return long_filename;
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-en/ref.", command, ".html");
+	if (long_filename)
+		return long_filename;
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-en/", command, NULL);
+	if (long_filename)
+			return long_filename;
+							
 	// For Redhat/Fedora Core and other sensible distrubutions...
-	long_filename = tab_help_try_filename("/usr/share/doc/phpmanual/function.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/phpmanual/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/phpmanual/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/phpmanual/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/phpmanual/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/phpmanual/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
 	// For Debian, Ubuntu and sensible distrubutions...
-	long_filename = tab_help_try_filename("/usr/share/doc/phpdoc/html/function.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/phpdoc/html/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/phpdoc/html/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/phpdoc/html/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/phpdoc/html/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/phpdoc/html/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
 	// For Gentoo, as much as I love it - it's twatty to put docs in a version specific folder like this!
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-200403/html/function.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/doc/php-docs-200403/html/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-200403/html/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/doc/php-docs-200403/html/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-200403/html/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/doc/php-docs-200403/html/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
-	long_filename = tab_help_try_filename("/usr/share/doc/php-docs-20050822/html/function.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-docs-20050822/html/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/php-docs-20050822/html/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-docs-20050822/html/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/share/doc/php-docs-20050822/html/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/share/doc/php-docs-20050822/html/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-4.2.3/html/function.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/doc/php-docs-4.2.3/html/function.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-4.2.3/html/ref.", command, ".html");
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/doc/php-docs-4.2.3/html/ref.", command, ".html");
 	if (long_filename)
 		return long_filename;
-	long_filename = tab_help_try_filename("/usr/doc/php-docs-4.2.3/html/", command, NULL);
+	long_filename = tab_help_try_filename("%%LOCALBASE%%/doc/php-docs-4.2.3/html/", command, NULL);
 	if (long_filename)
 		return long_filename;
 
