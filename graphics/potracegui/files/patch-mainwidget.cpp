--- src/mainwidget.cpp.orig	Tue Jun 22 11:30:43 2004
+++ src/mainwidget.cpp	Tue Jun 22 11:31:10 2004
@@ -52,6 +52,7 @@
 #include <fstream>
 #include <vector>
 #include <utility>
+#include <unistd.h>
 using namespace std;
 
 MainWidget::MainWidget(QWidget* parent, const char* name, WFlags fl)
