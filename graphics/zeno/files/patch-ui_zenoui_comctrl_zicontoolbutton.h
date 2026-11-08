--- ui/zenoui/comctrl/zicontoolbutton.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zicontoolbutton.h
@@ -12,7 +12,7 @@ public:
     QSize sizeHint() const override;
 
 protected:
-    void enterEvent(QEvent* event) override;
+    void enterEvent(QEnterEvent* event) override;
     void leaveEvent(QEvent* event) override;
     void paintEvent(QPaintEvent* event) override;
 
