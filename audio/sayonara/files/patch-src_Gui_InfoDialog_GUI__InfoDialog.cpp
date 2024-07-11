--- src/Gui/InfoDialog/GUI_InfoDialog.cpp.orig	2024-05-13 19:42:03 UTC
+++ src/Gui/InfoDialog/GUI_InfoDialog.cpp
@@ -47,6 +47,8 @@
 #include <QTabBar>
 #include <QTableWidgetItem>
 
+#include <unordered_map>
+
 namespace
 {
 	enum StackedWidgetTab
