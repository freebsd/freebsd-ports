--- delta/newFrontend/ximsub1.c.orig	Tue Aug  1 03:00:00 2000
+++ delta/newFrontend/ximsub1.c	Tue Apr 23 06:24:39 2002
@@ -260,7 +260,7 @@
 		if (&fxim_table[i].client == xim_client) {
 		    FreeRecvQueue(fxim_table[i].client.pending);
 #if 1/*991109*/
-		    if (xim_client->v_data) {
+		    if (1) { /* (xim_client->v_data) { */
 	 		CloseVJE (xim_client);
 		    }
 #endif
@@ -295,7 +295,7 @@
 	    FreeRecvQueue(fxim_table[i].client.pending);
 #if 1/*991109*/
 	    xim_client = &fxim_table[i].client;
-	    if (xim_client->v_data) {
+	    if (1) { /* (xim_client->v_data) { */
 	 		CloseVJE (xim_client);
 	    }
 #endif
