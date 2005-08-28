--- gedit/gedit-plugins-engine.c.orig	Fri Aug  5 22:00:45 2005
+++ gedit/gedit-plugins-engine.c	Fri Aug  5 22:01:03 2005
@@ -314,8 +314,8 @@ gedit_plugins_engine_shutdown (void)
 			}
 		}
 
-		if (info->plugin->handle != NULL)
-			g_module_close (info->plugin->handle);
+		/*if (info->plugin->handle != NULL)
+			g_module_close (info->plugin->handle);*/
 
 		g_free (info->plugin->file);
 		g_free (info->plugin->location);
