--- hydrogen_gui/PatternEditor.cpp.orig	Sun Aug 15 19:17:40 2004
+++ hydrogen_gui/PatternEditor.cpp	Sun Aug 15 19:30:40 2004
@@ -36,6 +36,7 @@
 #include <assert.h>
 #include "qcursor.h"
 
+#include <algo.h>
 
 PatternEditor::PatternEditor(QWidget* parent, PatternEditorPanel *pPanel)
  : QWidget(parent, "", WNoAutoErase )
