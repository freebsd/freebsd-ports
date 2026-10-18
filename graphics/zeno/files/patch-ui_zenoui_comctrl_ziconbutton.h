--- ui/zenoui/comctrl/ziconbutton.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/ziconbutton.h
@@ -20,7 +20,7 @@ public:
     QSize sizeHint() const override;
 
 protected:
-    void enterEvent(QEvent* event) override;
+    void enterEvent(QEnterEvent* event) override;
     void leaveEvent(QEvent* event) override;
     void mousePressEvent(QMouseEvent* event) override;
     void mouseReleaseEvent(QMouseEvent *event) override;
