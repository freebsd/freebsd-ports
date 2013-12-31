--- ./src/main.c.orig	2013-10-15 19:39:04.000000000 +0200
+++ ./src/main.c	2013-12-31 15:12:54.000000000 +0100
@@ -2097,6 +2097,7 @@
 	}
 	clip_lock= g_mutex_new();
 	hist_lock= g_mutex_new();
+	g_mutex_trylock(clip_lock);
 	g_mutex_unlock(clip_lock);
 
   show_icon=!get_pref_int32("no_icon");
