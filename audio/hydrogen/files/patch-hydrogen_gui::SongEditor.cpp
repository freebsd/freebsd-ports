--- hydrogen_gui/SongEditor.cpp.orig	Sun Aug 15 19:31:41 2004
+++ hydrogen_gui/SongEditor.cpp	Sun Aug 15 19:31:55 2004
@@ -40,6 +40,8 @@
 #include "qvbox.h"
 #include "qcursor.h"
 
+#include <algo.h>
+
 SongEditorPanel::SongEditorPanel(QWidget *parent)
  : QWidget(parent)
  , Object( "SongEditPanel" )
