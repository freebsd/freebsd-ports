--- krss/schemeeditor.cpp.orig	Mon Nov 26 10:08:12 2001
+++ krss/schemeeditor.cpp	Wed May 21 10:27:55 2003
@@ -43,6 +43,8 @@
 #include "schemeparser.h"
 #include "colourconverter.h"
 
+using namespace std;
+
 SchemeEditor::SchemeEditor(QWidget *parent, const char *name )
 : QWidget(parent,name)
 {
