--- ./src/SelectTools/ToolSelectBase.cpp.orig	Mon Jul 21 19:10:28 2003
+++ ./src/SelectTools/ToolSelectBase.cpp	Mon Jul 21 19:11:17 2003
@@ -146,7 +146,7 @@
 ToolSelectBase::ToolSelectBase( CadView *v,
 										  ObjPainterManager *pman,
 										  const string& funcName, const string& optTitle,
-										  int tableWidth = 1 )
+										  int tableWidth )
 				: ToolSelectModel( v, pman, funcName, optTitle, tableWidth ),
 				  CadClickAndDragEventHandler( v->getCadArea() )
 {
