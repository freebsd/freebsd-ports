--- delta/newFrontend/ximsub1.c.orig	Tue Aug  1 03:00:00 2000
+++ delta/newFrontend/ximsub1.c	Thu Jan 11 21:24:21 2001
@@ -259,10 +259,11 @@
 
 		if (&fxim_table[i].client == xim_client) {
 		    FreeRecvQueue(fxim_table[i].client.pending);
+
 #if 1/*991109*/
-		    if (xim_client->v_data) {
+		    /* if (xim_client->v_data) { */
 	 		CloseVJE (xim_client);
-		    }
+		    /* } */
 #endif
 		    fxim_table[i].client.used = False;
 		    if (xim_client->preedit->FontName) {
@@ -295,9 +296,9 @@
 	    FreeRecvQueue(fxim_table[i].client.pending);
 #if 1/*991109*/
 	    xim_client = &fxim_table[i].client;
-	    if (xim_client->v_data) {
+	    /* if (xim_client->v_data) { */
 	 		CloseVJE (xim_client);
-	    }
+	    /* } */
 #endif
 	    fxim_table[i].client.used = False;
 
