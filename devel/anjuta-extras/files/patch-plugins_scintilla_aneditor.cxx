From 959807c25e3547b019448b0877bae54dd6c04a9d Mon Sep 17 00:00:00 2001
From: =?UTF-8?q?S=C3=A9bastien=20Granjoux?= <seb.sfo@free.fr>
Date: Mon, 11 Nov 2013 10:51:05 +0100
Subject: bgo #711771 - The edge-column variable is not taken into account by
 anjuta for scintilla editor


diff --git a/plugins/scintilla/aneditor.cxx b/plugins/scintilla/aneditor.cxx
index 0fa9acc..d61e4e1 100644
--- plugins/scintilla/aneditor.cxx
+++ plugins/scintilla/aneditor.cxx
@@ -2656,7 +2656,6 @@ void AnEditor::ReadProperties(const char *fileForExt, char **typedef_hl) {
 	int visibleLines = props->GetInt("visible.policy.lines");
 	SendEditor(SCI_SETVISIBLEPOLICY, visibleStrict | visibleSlop, visibleLines);
 
-	SendEditor(SCI_SETEDGECOLUMN, props->GetInt("edge.column", 0));
 	SendEditor(SCI_SETEDGEMODE, props->GetInt("edge.mode", EDGE_NONE));
 	SendEditor(SCI_SETEDGECOLOUR,
 	           ColourOfProperty(props, "edge.colour", ColourDesired(0xff, 0xda, 0xda)));
-- 
cgit v0.10.1

