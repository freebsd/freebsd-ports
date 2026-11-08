--- ui/zenoui/comctrl/zlabel.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zlabel.h
@@ -26,7 +26,7 @@ public:
 
 protected:
     void paintEvent(QPaintEvent* e) override;
-    void enterEvent(QEvent* event) override;
+    void enterEvent(QEnterEvent* event) override;
     void leaveEvent(QEvent* event) override;
     void mouseReleaseEvent(QMouseEvent* event) override;
 
@@ -62,7 +62,7 @@ public:
     void setEnterCursor(Qt::CursorShape shape);
 
 protected:
-    void enterEvent(QEvent* event) override;
+    void enterEvent(QEnterEvent* event) override;
     void leaveEvent(QEvent* event) override;
     void mouseReleaseEvent(QMouseEvent* event) override;
 
