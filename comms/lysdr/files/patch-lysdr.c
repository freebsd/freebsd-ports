--- lysdr.c.orig	2014-06-02 01:02:06.000000000 -0700
+++ lysdr.c	2014-06-02 01:02:18.000000000 -0700
@@ -103,10 +103,6 @@
 
 	printf("lysdr starting\n");
 	
-	// get the Gtk threads support going
-	if(!g_thread_supported())
-		g_thread_init(NULL);
-
 	gdk_threads_init();
 	gdk_threads_enter();
 
