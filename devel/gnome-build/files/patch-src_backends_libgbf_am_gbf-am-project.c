--- src/backends/libgbf_am/gbf-am-project.c.orig	Sun Oct 26 01:24:42 2003
+++ src/backends/libgbf_am/gbf-am-project.c	Sun Oct 26 01:32:23 2003
@@ -1750,7 +1750,7 @@
 
 		switch (status) {
 		    case G_IO_STATUS_NORMAL:
-			    DEBUG (g_message ("wrote %d bytes", bytes_written));
+			    DEBUG (g_message ("wrote %uld bytes", bytes_written));
 			    
 			    if (data->input.length < data->input.size) {
 				    /* don't remove the source */
