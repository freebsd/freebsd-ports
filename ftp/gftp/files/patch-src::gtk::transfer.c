--- src/gtk/transfer.c.orig	Sun Jul 27 03:17:01 2003
+++ src/gtk/transfer.c	Sun Jul 27 03:18:23 2003
@@ -570,6 +570,13 @@
       transfer->current_file_number++; 
       g_static_mutex_unlock (&transfer->structmutex);
  
+	if (*(curfle->file+strlen(curfle->file)-1)=='/' ) {
+		*(curfle->file+strlen(curfle->file)-1)=(char)0;
+	}
+	if (*(curfle->destfile+strlen(curfle->destfile)-1)=='/' ) {
+		*(curfle->destfile+strlen(curfle->destfile)-1)=(char)0;
+	}
+
       if (curfle->transfer_action == GFTP_TRANS_ACTION_SKIP)
         {
           g_static_mutex_lock (&transfer->structmutex);
