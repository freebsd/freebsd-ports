--- src/schematic-view.c.orig	Fri Nov 12 10:09:14 2004
+++ src/schematic-view.c	Fri Nov 26 18:08:32 2004
@@ -1840,6 +1840,7 @@
 				int i=0;
 				while (files[i]) {
 					Schematic *new_sm = NULL;
+					gchar *fname = files[i];
 					int l = strlen(files[i]);
 					/* Algo queda mal al final luego del split, agrego un \0 */
 					files[i][l-1] = '\0';
@@ -1849,8 +1850,6 @@
 						i++;
 						continue;
 					}
-
-					gchar *fname = files[i];
 
 					new_sm = schematic_read (fname);
 					if (new_sm) {
