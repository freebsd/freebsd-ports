--- sources/rb-ipod-source.c.orig	Sun Sep 19 17:05:37 2004
+++ sources/rb-ipod-source.c	Sun Sep 19 17:05:49 2004
@@ -234,6 +234,7 @@
 		}
 
 		/* Set disc number */
+		/*
 		if (song->cd_nr != 0) {
 			GValue value = {0, };
 			g_value_init (&value, G_TYPE_ULONG);
@@ -243,6 +244,7 @@
 					    &value);
 			g_value_unset (&value);
 		}
+		*/
 		
 		/* Set bitrate */
 		if (song->bitrate != 0) {
