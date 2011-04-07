--- ./pinedit/polygonview.cpp.orig	2003-04-17 12:20:04.000000000 +0400
+++ ./pinedit/polygonview.cpp	2011-04-07 10:30:30.076905694 +0400
@@ -45,7 +45,7 @@
 #include "TextureUtil.h"
 
 #define INT2OBJ(a) ((void*)((a)+1))
-#define OBJ2INT(a) (((int)(a))-1)
+#define OBJ2INT(a) (((intptr_t)(a))-1)
 
 PolygonView::PolygonView(PinEditDoc * doc, QWidget * parent, const char * name, WFlags f) 
 : QWidget(parent, name, f) {
@@ -347,7 +347,7 @@
   for (; iter.current(); ++iter) {
     if (iter.current()->isSelected()) {
       if (((ListItem*)iter.current())->getObjectType() == LISTITEM_VERTEX) {
-	int vtxindex = OBJ2INT(((ListItem*)iter.current())->getObject());
+	intptr_t vtxindex = OBJ2INT(((ListItem*)iter.current())->getObject());
 	p_Polygon->moveUp(p_Polygon->includes(vtxindex));
 	this->setPolygon(p_Shape, p_Polygon);
       }
@@ -365,7 +365,7 @@
   for (; iter.current(); ++iter) {
     if (iter.current()->isSelected()) {
       if (((ListItem*)iter.current())->getObjectType() == LISTITEM_VERTEX) {
-	int vtxindex = OBJ2INT(((ListItem*)iter.current())->getObject());
+	intptr_t vtxindex = OBJ2INT(((ListItem*)iter.current())->getObject());
 	p_Polygon->moveDown(p_Polygon->includes(vtxindex));
 	this->setPolygon(p_Shape, p_Polygon);
       }
