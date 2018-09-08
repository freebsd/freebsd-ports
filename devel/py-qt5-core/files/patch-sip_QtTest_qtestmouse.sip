Fix build with Qt 5.11 (fixed upstream)

--- sip/QtTest/qtestmouse.sip.orig	2018-09-04 08:52:38 UTC
+++ sip/QtTest/qtestmouse.sip
@@ -41,7 +41,6 @@ namespace QTest
     void mousePress(QWidget *widget, Qt::MouseButton button, Qt::KeyboardModifiers modifier = 0, QPoint pos = QPoint(), int delay = -1);
     void mouseRelease(QWidget *widget, Qt::MouseButton button, Qt::KeyboardModifiers modifier = 0, QPoint pos = QPoint(), int delay = -1);
     void mouseEvent(QTest::MouseAction action, QWidget *widget, Qt::MouseButton button, Qt::KeyboardModifiers modifier, QPoint pos, int delay = -1);
-    void waitForEvents() /ReleaseGIL/;
     void mouseEvent(QTest::MouseAction action, QWindow *window, Qt::MouseButton button, Qt::KeyboardModifiers modifier, QPoint pos, int delay = -1);
     void mousePress(QWindow *window, Qt::MouseButton button, Qt::KeyboardModifiers modifier = Qt::KeyboardModifiers(), QPoint pos = QPoint(), int delay = -1);
     void mouseRelease(QWindow *window, Qt::MouseButton button, Qt::KeyboardModifiers modifier = Qt::KeyboardModifiers(), QPoint pos = QPoint(), int delay = -1);
