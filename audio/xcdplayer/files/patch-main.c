--- main.c.orig	Tue Jan 12 19:59:36 1993
+++ main.c	Wed May 30 19:19:53 2007
@@ -23,12 +23,15 @@
 
 Widget		top_form;
 
-void
+extern AppData app_data;
+
+static void	chk_debug();
+
+int
 main(argc, argv)
 	int		argc;
 	char		**argv;
 {
-	static void	chk_debug();
 
 	chk_debug(argc, argv);
 
@@ -66,7 +69,7 @@
 	/* ugly hack */
 	for (i = 1; i < argc; i++) {
 		if (strcmp(argv[i], "-debug") == 0) {
-			debug = True;
+			app_data.debug = True;
 			break;
 		}
 	}
