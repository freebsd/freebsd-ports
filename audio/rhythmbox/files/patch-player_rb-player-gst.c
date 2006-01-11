===================================================================
RCS file: /cvs/gnome/rhythmbox/player/rb-player-gst.c,v
retrieving revision 1.51
retrieving revision 1.52
diff -u -r1.51 -r1.52
--- player/rb-player-gst.c	2005/11/30 08:47:21	1.51
+++ player/rb-player-gst.c	2005/12/03 10:56:42	1.52
@@ -782,7 +782,7 @@
 
 	if (mp->priv->playbin != NULL) {
 		GParamSpec *volume_pspec;
-		GValue val;
+		GValue val = {0,};
 		
 		volume_pspec = g_object_class_find_property (G_OBJECT_GET_CLASS (mp->priv->playbin),
 							     "volume");
