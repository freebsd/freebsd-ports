--- common/interface__QT/audio/sample_editor_format.cpp.orig	Fri Oct 24 06:29:26 2003
+++ common/interface__QT/audio/sample_editor_format.cpp	Thu Oct 30 12:05:50 2003
@@ -36,6 +36,11 @@
 #include "interface__QT/icons/transp_semitone_up.xpm"
 #include <qpushbutton.h>
 #include <qhbox.h>
+#include <math.h>
+
+#if defined(__FreeBSD__)
+  #define round(c) rint(c)
+#endif
 
 void Sample_Editor_Format::transpose_up_1_4_cbk() {
 
