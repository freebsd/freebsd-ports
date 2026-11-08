--- ui/zenoui/comctrl/zcheckboxbar.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zcheckboxbar.h
@@ -18,7 +18,7 @@ signals:
 
 protected:
     void paintEvent(QPaintEvent* event) override;
-    void enterEvent(QEvent *event) override;
+    void enterEvent(QEnterEvent* event) override;
     void leaveEvent(QEvent *event) override;
     void mousePressEvent(QMouseEvent *event) override;
     void mouseReleaseEvent(QMouseEvent *event) override;
