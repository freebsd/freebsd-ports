--- src/syncengine.c.orig	Mon Apr 12 06:23:21 2004
+++ src/syncengine.c	Thu Apr 29 00:11:08 2004
@@ -1097,6 +1097,7 @@
     for (n = 0; n < g_list_length(remotechanges); n++) {
       changed_object *robj, *lobj;
       char *luid, *uid;
+      sync_compare_result compare;
       
       robj = g_list_nth_data(remotechanges, n);
       lobj = g_list_nth_data(localchanges, t);
@@ -1135,7 +1136,7 @@
 	  if (!uid) {*/
 	    // None of the two objects has a UID connection
 	    // If they are equal, just connect them
-	    sync_compare_result compare = 
+	    compare = 
 	      sync_compare_objects(robj->comp, lobj->comp, lobj->object_type);
 	    if (compare == SYNC_COMPARE_EQUAL) {
 	      sync_insert_idpair(lobj->uid, robj->uid, 
