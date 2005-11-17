--- src/level-manager.c.orig	Thu Nov 17 17:45:18 2005
+++ src/level-manager.c	Thu Nov 17 17:45:31 2005
@@ -232,10 +232,10 @@ static void search_level_in_dir (LevelMa
 	      g_free (levelname);
 	    }
 	}
+	g_free (dent);
+	closedir (dir);
     }
 
-  g_free (dent);
-  closedir (dir);
 }
 
 static gchar *lookup_level_name (gchar *filename)
