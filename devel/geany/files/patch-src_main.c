--- src/main.c.orig	Tue Apr  4 14:21:13 2006
+++ src/main.c	Tue Apr  4 14:21:16 2006
@@ -241,7 +241,10 @@
 	gtk_init(&argc, &argv);
 
 	// inits
-	app = g_new(MyApp, 1);
+	// use g_new0() to make sure that all members are initialized
+	// to NULL (otherwise it segfaults in destroyapp() when trying
+	// to g_free() some undefined pointers)
+	app = g_new0(MyApp, 1);
 #ifdef GEANY_DEBUG
 	geany_debug("debug mode built in (can't be disabled)");
 #endif
