--- ui/zenoui/comctrl/zenocheckbutton.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/comctrl/zenocheckbutton.h
@@ -19,7 +19,7 @@ public:
 	QSize sizeHint() const override;
 
 protected:
-	void enterEvent(QEvent* event) override;
+	void enterEvent(QEnterEvent* event) override;
 	void leaveEvent(QEvent* event) override;
 	void mousePressEvent(QMouseEvent* event) override;
 	void mouseReleaseEvent(QMouseEvent* event) override;
