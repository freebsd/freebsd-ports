Index: src/xim-handler.c
diff -u -p src/xim-handler.c.orig src/xim-handler.c
--- src/xim-handler.c.orig	Wed Dec 17 13:17:26 2003
+++ src/xim-handler.c	Wed Mar 24 21:10:11 2004
@@ -214,8 +214,9 @@ static Bool im_ja_xim_handler_destroy_ic
 static Bool im_ja_xim_handler_set_ic_values(XIMS ims, IMProtocol *call_data) {
 	IMChangeICStruct *data = (IMChangeICStruct *)call_data;
 
-	IM_JA_DEBUG("im_ja_xim_handler_set_ic_values\n");
 	IMJAContext *ic = im_ja_xim_server_get_ic(data->icid);
+
+	IM_JA_DEBUG("im_ja_xim_handler_set_ic_values\n");
 			 
 	if (ic != NULL)  im_ja_xim_ic_set_values(ic, data);
 
