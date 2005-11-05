--- libeog/eog-image-list.c.orig	Thu Aug 25 14:57:02 2005
+++ libeog/eog-image-list.c	Thu Aug 25 14:57:46 2005
@@ -450,12 +450,13 @@
 		case GNOME_VFS_MONITOR_EVENT_CREATED:
 		
 			if (list && list->priv) {
+				gchar *str;
 				node = list->priv->store;
 				
 				while (node != NULL && !found) {
 			
 					uri = eog_image_get_uri(node->data);
-					gchar *str = gnome_vfs_uri_to_string 
+					str = gnome_vfs_uri_to_string 
 						(uri, GNOME_VFS_URI_HIDE_NONE);
 					found = (strcmp (str, info_uri)==0)?TRUE:FALSE;
 					g_free (str);
