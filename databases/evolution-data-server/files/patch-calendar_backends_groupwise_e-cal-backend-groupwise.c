--- calendar/backends/groupwise/e-cal-backend-groupwise.c.orig	Mon Oct  3 11:05:43 2005
+++ calendar/backends/groupwise/e-cal-backend-groupwise.c	Thu Nov 10 10:09:35 2005
@@ -322,11 +322,12 @@
 
 	for (; item_list != NULL; item_list = g_list_next(item_list)) {
 		EGwItem *item = NULL;
-		item = E_GW_ITEM(item_list->data);
 		ECalComponent *modified_comp = NULL, *cache_comp = NULL;
 		char *cache_comp_str = NULL;
 		const char *uid, *rid = NULL;
 		int r_key;
+
+		item = E_GW_ITEM(item_list->data);
 
 		modified_comp = e_gw_item_to_cal_component (item, cbgw);
 		if (!modified_comp) {
