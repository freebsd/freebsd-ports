--- ./src/XformTools/ToolTransformModel.cpp.orig	Mon Jul 21 19:05:58 2003
+++ ./src/XformTools/ToolTransformModel.cpp	Mon Jul 21 19:06:20 2003
@@ -15,7 +15,7 @@
 													ObjPainterManager *pman,
 													const string& funcName,
 													const string& optTitle,
-													int tableWidth = 1)
+													int tableWidth)
 					: ToolModifyModel(v, pman, funcName, optTitle, tableWidth)
 {
 }
