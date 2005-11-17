--- src/theme-manager.c.orig	Thu Nov 17 17:43:33 2005
+++ src/theme-manager.c	Thu Nov 17 17:43:58 2005
@@ -168,10 +168,10 @@ static void search_themes_in_dir (ThemeM
 	      g_free (subdirpath);
 	    }
 	}
+	g_free (dent);
+	closedir (dir);
     }
 
-  g_free (dent);
-  closedir (dir);
 }
 
 static void add_theme (ThemeManager *tm, gchar *themename, gchar *dirpath)
