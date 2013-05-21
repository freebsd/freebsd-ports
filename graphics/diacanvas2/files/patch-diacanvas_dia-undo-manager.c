--- diacanvas/dia-undo-manager.c.orig	2013-05-21 09:01:02.000000000 +0000
+++ diacanvas/dia-undo-manager.c	2013-05-21 09:03:46.000000000 +0000
@@ -195,7 +195,8 @@ dia_undo_manager_base_init (gpointer ifa
 gboolean
 dia_undo_manager_in_transaction (DiaUndoManager *undo_manager)
 {
-	g_return_if_fail (DIA_IS_UNDO_MANAGER (undo_manager));
+	if (!DIA_IS_UNDO_MANAGER (undo_manager))
+		return FALSE;
 	
 	if (!DIA_UNDO_MANAGER_GET_IFACE (undo_manager)->in_transaction)
 		return FALSE;
@@ -214,7 +215,8 @@ dia_undo_manager_in_transaction (DiaUndo
 gboolean
 dia_undo_manager_can_undo (DiaUndoManager *undo_manager)
 {
-	g_return_if_fail (DIA_IS_UNDO_MANAGER (undo_manager));
+	if (!DIA_IS_UNDO_MANAGER (undo_manager))
+		return FALSE;
 	
 	if (!DIA_UNDO_MANAGER_GET_IFACE (undo_manager)->can_undo)
 		return FALSE;
@@ -233,7 +235,8 @@ dia_undo_manager_can_undo (DiaUndoManage
 gboolean
 dia_undo_manager_can_redo (DiaUndoManager *undo_manager)
 {
-	g_return_if_fail (DIA_IS_UNDO_MANAGER (undo_manager));
+	if (!DIA_IS_UNDO_MANAGER (undo_manager))
+		return FALSE;
 	
 	if (!DIA_UNDO_MANAGER_GET_IFACE (undo_manager)->can_redo)
 		return FALSE;
