--- main.c.orig	1993-01-12 18:59:36 UTC
+++ main.c
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
 
@@ -66,7 +69,7 @@ chk_debug(argc, argv)
 	/* ugly hack */
 	for (i = 1; i < argc; i++) {
 		if (strcmp(argv[i], "-debug") == 0) {
-			debug = True;
+			app_data.debug = True;
 			break;
 		}
 	}
