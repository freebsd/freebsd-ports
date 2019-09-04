 Fix graphics/dspdfviewer build w/ Qt 5.13

 - adjust to deprecated methods
 - QApplication::flush() hasn't really been a thing since Qt4,
   just comment it out.

The application looks abandoned upstream.

Patched by adridg@freebsd.org
--- pdfviewerwindow.cpp.orig	2016-09-13 13:18:47 UTC
+++ pdfviewerwindow.cpp
@@ -24,6 +24,7 @@
 #include <QHBoxLayout>
 #include <QLabel>
 #include <QMouseEvent>
+#include <QScreen>
 #if defined(POPPLER_QT5) && defined(_WIN32)
 #include <QWindow>
 #endif
@@ -116,7 +117,12 @@ void PDFViewerWindow::reposition()
     this->windowHandle()->setScreen(0);
   this->showFullScreen();
 #else
-  QRect rect = QApplication::desktop()->screenGeometry( numeric_cast<int>(getMonitor()) );
+  auto screens = QGuiApplication::screens();
+  int screen_number = numeric_cast<int>(getMonitor());
+  if ((screen_number < 0) || (screen_number >= screens.length())) {
+    screen_number = 0;
+  }
+  QRect rect = screens.at(screen_number)->geometry();
   move(rect.topLeft());
   resize( rect.size() );
   this->showFullScreen();
@@ -381,7 +387,7 @@ void PDFViewerWindow::resizeEvent(QResizeEvent* resize
 		! i3shellcode_executed
 		// Make sure to do this only once
 		) {
-		QApplication::flush(); // Make sure the window has been painted
+		// QApplication::flush(); // Make sure the window has been painted
 		// This is the second screen. It has now been created.
 		// so we should call the i3 shellcode now
 		const std::string shellcode = runtimeConfiguration.i3workaround_shellcode();
