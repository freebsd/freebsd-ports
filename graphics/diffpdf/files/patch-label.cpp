--- label.cpp.orig	2013-10-15 07:01:22 UTC
+++ label.cpp
@@ -15,6 +15,7 @@
 #include <QDragEnterEvent>
 #include <QDragEnterEvent>
 #include <QMouseEvent>
+#include <QMimeData>
 
 Label::Label(QWidget *parent) : QLabel(parent)
 {
