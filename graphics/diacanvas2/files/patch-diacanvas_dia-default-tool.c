--- diacanvas/dia-default-tool.c.orig	2013-05-21 09:10:22.000000000 +0000
+++ diacanvas/dia-default-tool.c	2013-05-21 09:11:26.000000000 +0000
@@ -302,7 +302,8 @@ dia_default_tool_set_handle_tool (DiaDef
 DiaTool*
 dia_default_tool_get_handle_tool (DiaDefaultTool *tool)
 {
-	g_return_if_fail (DIA_IS_DEFAULT_TOOL (tool));
+	if (!DIA_IS_DEFAULT_TOOL (tool))
+		return NULL;
 
 	return tool->handle_tool;
 }
@@ -323,7 +324,8 @@ dia_default_tool_set_item_tool (DiaDefau
 DiaTool*
 dia_default_tool_get_item_tool (DiaDefaultTool *tool)
 {
-	g_return_if_fail (DIA_IS_DEFAULT_TOOL (tool));
+	if (!DIA_IS_DEFAULT_TOOL (tool))
+		return NULL;
 
 	return tool->item_tool;
 }
@@ -345,7 +347,8 @@ dia_default_tool_set_selection_tool (Dia
 DiaTool*
 dia_default_tool_get_selection_tool (DiaDefaultTool *tool)
 {
-	g_return_if_fail (DIA_IS_DEFAULT_TOOL (tool));
+	if (!DIA_IS_DEFAULT_TOOL (tool))
+		return NULL;
 
 	return tool->selection_tool;
 }
