--- src/gtk_s9x.cpp.orig	2013-10-25 03:47:08.000000000 -0700
+++ src/gtk_s9x.cpp	2013-10-25 03:47:32.000000000 -0700
@@ -44,6 +44,7 @@
 
     g_thread_init (NULL);
     gdk_threads_init ();
+    gdk_threads_enter();
 
     gtk_init (&argc, &argv);
 
@@ -127,6 +128,8 @@
 
     gtk_main ();
 
+    gdk_threads_leave();
+    
     return 0;
 }
 
