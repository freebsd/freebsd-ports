--- lineedit.cpp.orig	2013-10-15 07:01:22 UTC
+++ lineedit.cpp
@@ -14,6 +14,7 @@
 #include "lineedit.hpp"
 #include <QDragEnterEvent>
 #include <QDragEnterEvent>
+#include <QMimeData>
 
 
 LineEdit::LineEdit(QWidget *parent) : QLineEdit(parent)
