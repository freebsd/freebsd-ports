--- qvge/CNodeEditorScene.cpp.orig	2020-06-22 11:24:05 UTC
+++ qvge/CNodeEditorScene.cpp
@@ -189,7 +189,10 @@ bool CNodeEditorScene::toGraph(Graph& g)
 
 
 	// visibility
-	static AttrInfo _vis_({ attr_labels_visIds , "Visible Labels", QVariant::StringList});
+	static AttrInfo _vis_;
+	_vis_.id = attr_labels_visIds;
+	_vis_.name = "Visible Labels";
+	_vis_.defaultValue = QVariant::StringList;
 
 	auto nodeVis = getVisibleClassAttributes("node", false);
 	if (nodeVis.size())
