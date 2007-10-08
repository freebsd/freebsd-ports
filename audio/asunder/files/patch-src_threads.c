--- src/threads.c.orig	2007-08-26 12:53:58.000000000 +0200
+++ src/threads.c	2007-10-08 13:12:44.000000000 +0200
@@ -334,12 +334,6 @@
         gdk_threads_leave();
     }
     
-    // no more tracks to rip, safe to eject
-    if (global_prefs->eject_on_done)
-    {
-        eject_disc(global_prefs->cdrom);
-    }
-    
     return NULL;
 }
 
@@ -556,6 +550,12 @@
     
     aborted = 1; // so the tracker thread will exit
     
+    // no more tracks to rip, safe to eject
+    if (global_prefs->eject_on_done)
+    {
+        eject_disc(global_prefs->cdrom);
+    }
+    
     gdk_threads_enter();
         gtk_widget_hide(win_ripping);
         gdk_flush();
