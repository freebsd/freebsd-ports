--- src/editor/editorview.cpp.orig	2015-04-28 17:34:19 UTC
+++ src/editor/editorview.cpp
@@ -35,6 +35,7 @@
 #include "tracktile.hpp"
 
 #include <cassert>
+#include <cstdlib>
 
 EditorView::EditorView(EditorData & editorData, QWidget * parent)
 : QGraphicsView(parent)
