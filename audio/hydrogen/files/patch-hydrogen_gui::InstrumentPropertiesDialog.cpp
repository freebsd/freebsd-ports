--- hydrogen_gui/InstrumentPropertiesDialog.cpp.orig	Sun Aug 15 19:06:50 2004
+++ hydrogen_gui/InstrumentPropertiesDialog.cpp	Sun Aug 15 19:07:17 2004
@@ -42,6 +42,12 @@
 #include "Mixer.h"
 #include "PatternEditorPanel.h"
 
+// workaround
+
+inline int round(double x) { return x > 0 ? (int) (x+0.5) :
+-(int)(-x+0.5); }
+
+
 InstrumentPropertiesDialog::InstrumentPropertiesDialog( QWidget* parent )
  : InstrumentPropertiesDialog_UI(parent)
  , Object( "InstrPropDialog" )
