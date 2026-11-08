--- ui/zenoui/comctrl/ztoolbutton.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/ztoolbutton.h
@@ -92,7 +92,7 @@ signals:
 
 protected:
     virtual bool event(QEvent* e) override;
-    virtual void enterEvent(QEvent* e) override;
+    virtual void enterEvent(QEnterEvent* e) override;
     virtual void leaveEvent(QEvent* e) override;
     virtual void paintEvent(QPaintEvent* event) override;
     virtual void initStyleOption(ZStyleOptionToolButton* option) const;
