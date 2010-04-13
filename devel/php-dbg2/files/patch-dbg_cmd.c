--- ./dbg_cmd.c.orig	2010-04-13 09:41:26.000000000 -0400
+++ ./dbg_cmd.c	2010-04-13 09:41:53.000000000 -0400
@@ -601,7 +601,7 @@
 	
 	memset(&data, 0, sizeof(data));
 	Z_TYPE_P(&data) = IS_STRING;
-	data.refcount++;
+	Z_ADDREF(data);
 
 	if (DBG(eval_error)) {
 		efree(DBG(eval_error));
@@ -627,7 +627,7 @@
 
 	memset(&buf, 0, sizeof(buf));
 	Z_TYPE_P(&buf) = IS_STRING;
-	buf.refcount++;
+	Z_ADDREF(buf);
 
 	if (req->istr!=0 && (!dbg_packet_findstring(inpack, req->istr, &str, &sz) || sz<=0)) return 0;
 	if (str && strlen(str)==0) str = NULL;
