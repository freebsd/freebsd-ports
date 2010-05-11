--- utilities/fuzzysearch/fuzzysearchview.cpp.orig	2010-03-29 01:20:16.000000000 +0300
+++ utilities/fuzzysearch/fuzzysearchview.cpp	2010-03-30 10:02:03.000000000 +0300
@@ -26,7 +26,7 @@
 
 // Qt includes
 
-#include <qevent.h>
+#include <QEvent>
 #include <QFrame>
 #include <QImage>
 #include <QLabel>
@@ -36,6 +36,8 @@
 #include <QTime>
 #include <QTimer>
 #include <QToolButton>
+#include <QDragEnterEvent>
+#include <QDropEvent>
 
 // KDE includes
 
