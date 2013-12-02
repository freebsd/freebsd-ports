--- ./x11amp/playlist.c.orig	1999-04-13 20:26:35.000000000 +0000
+++ ./x11amp/playlist.c	2013-12-02 19:12:21.000000000 +0000
@@ -224,7 +224,7 @@
 		}
 		g_list_free(list);
 		playlist_generate_shuffle_list();
-		return;
+		return 0;
 	}
 	g_free(temp);
 	if(dir=opendir(path))
