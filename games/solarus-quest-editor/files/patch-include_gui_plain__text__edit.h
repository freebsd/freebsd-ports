--- include/gui/plain_text_edit.h.orig	2015-08-20 11:15:41 UTC
+++ include/gui/plain_text_edit.h
@@ -19,6 +19,7 @@
 
 #include <QPlainTextEdit>
 #include <QPainter>
+#include <cmath>
 
 /**
  * @brief A plain text editor that sends editing_finished() signal when the text
