Missing include:
	userlistwidget.h:64:30: error: unknown type name 'QItemSelection'

--- src/desktop/widgets/userlistwidget.h.orig	2018-03-17 15:25:30 UTC
+++ src/desktop/widgets/userlistwidget.h
@@ -23,6 +23,7 @@
 
 #include <QWidget>
 #include <QItemDelegate>
+#include <QItemSelection>
 
 class Ui_UserBox;
 
