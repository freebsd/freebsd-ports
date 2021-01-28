- fix for https://github.com/xournalpp/xournalpp/issues/2222 that the upstream didn't fix for a while now

--- src/gui/dialog/toolbarCustomize/ToolbarAdapter.cpp.orig	2021-01-17 23:11:38 UTC
+++ src/gui/dialog/toolbarCustomize/ToolbarAdapter.cpp
@@ -271,7 +271,7 @@ bool ToolbarAdapter::toolbarDragMotionCb(GtkToolbar* t
 
 	ToolItemDragDropData* d = ToolItemDragCurrentData::getData();
 
-	g_return_val_if_fail(d != NULL, NULL);
+	g_return_val_if_fail(d != NULL, false);
 
 	if (d->type == TOOL_ITEM_ITEM)
 	{
