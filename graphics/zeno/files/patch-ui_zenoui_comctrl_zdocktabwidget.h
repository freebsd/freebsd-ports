--- ui/zenoui/comctrl/zdocktabwidget.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zdocktabwidget.h
@@ -12,7 +12,7 @@ public:
 
 protected:
     void paintEvent(QPaintEvent* e) override;
-    void enterEvent(QEvent* event) override;
+    void enterEvent(QEnterEvent* event) override;
     void leaveEvent(QEvent* event) override;
     void mousePressEvent(QMouseEvent* event) override;
     void mouseMoveEvent(QMouseEvent* event) override;
