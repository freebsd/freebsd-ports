
$FreeBSD$

--- main.c.orig	Tue Jan 12 19:59:36 1993
+++ main.c	Mon Aug 25 00:38:35 2003
@@ -23,7 +23,9 @@
 
 Widget		top_form;
 
-void
+extern AppData app_data;
+
+int
 main(argc, argv)
 	int		argc;
 	char		**argv;
@@ -66,7 +68,7 @@
 	/* ugly hack */
 	for (i = 1; i < argc; i++) {
 		if (strcmp(argv[i], "-debug") == 0) {
-			debug = True;
+			app_data.debug = True;
 			break;
 		}
 	}
