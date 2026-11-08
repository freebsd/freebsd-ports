--- ui/zenoedit/nodesview/zenowelcomepage.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/nodesview/zenowelcomepage.cpp
@@ -6,7 +6,7 @@
 #include "zenomainwindow.h"
 #include "settings/zsettings.h"
 #include <zenoui/style/zenostyle.h>
-#include <QtSvg/QSvgWidget>
+#include <QtSvgWidgets/QSvgWidget>
 #include "startup/zstartup.h"
 
 
@@ -16,7 +16,7 @@ ZenoWelcomePage::ZenoWelcomePage(QWidget
 	m_ui = new Ui::WelcomePage;
 	m_ui->setupUi(this);
     QPalette palette = this->palette();
-    palette.setColor(QPalette::Background, QColor("#2d3239"));
+    palette.setColor(QPalette::Window, QColor("#2d3239"));
     setPalette(palette);
 
     QSize iconSize(ZenoStyle::dpiScaled(24), ZenoStyle::dpiScaled(24));
