--- gnome-cd/cddb.c.orig	Sun May  9 11:19:57 2004
+++ gnome-cd/cddb.c	Sun Aug 22 16:18:18 2004
@@ -197,7 +197,6 @@
 	}
 
 	info = g_hash_table_lookup (cddb_cache, discid);
-	g_free (discid);
 
 	if (info != NULL) {
 		gcd->disc_info = info;
@@ -228,6 +227,8 @@
 				 data->nsecs, "GnomeCD", VERSION);
 	
 	gnome_cdrom_free_cddb_data (data);
+	g_free (discid);
+	g_free (offsets);
 }
 
 int
