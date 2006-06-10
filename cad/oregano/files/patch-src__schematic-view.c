--- src/schematic-view.c.orig	Wed May 24 14:16:30 2006
+++ src/schematic-view.c	Wed May 24 21:39:29 2006
@@ -1849,6 +1849,7 @@
 				int i=0;
 				while (files[i]) {
 					Schematic *new_sm = NULL;
+					gchar *fname = files[i];
 					int l = strlen(files[i]);
 					/* Algo queda mal al final luego del split, agrego un \0 */
 					files[i][l-1] = '\0';
@@ -1858,8 +1859,6 @@
 						i++;
 						continue;
 					}
-
-					gchar *fname = files[i];
 
 					new_sm = schematic_read (fname, &error);
 					if (new_sm) {
