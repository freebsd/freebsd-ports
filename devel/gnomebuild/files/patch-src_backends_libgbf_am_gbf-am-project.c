--- src/backends/libgbf_am/gbf-am-project.c.orig	Fri May  2 06:12:51 2003
+++ src/backends/libgbf_am/gbf-am-project.c	Sat Jan 31 13:22:04 2004
@@ -1750,7 +1750,7 @@
 
 		switch (status) {
 		    case G_IO_STATUS_NORMAL:
-			    DEBUG (g_message ("wrote %d bytes", bytes_written));
+			    DEBUG (g_message ("wrote %lu bytes", bytes_written));
 			    
 			    if (data->input.length < data->input.size) {
 				    /* don't remove the source */
