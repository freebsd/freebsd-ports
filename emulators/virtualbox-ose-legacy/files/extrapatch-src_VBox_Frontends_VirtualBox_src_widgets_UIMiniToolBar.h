--- src/VBox/Frontends/VirtualBox/src/widgets/UIMiniToolBar.h.orig	2017-04-18 09:53:23 UTC
+++ src/VBox/Frontends/VirtualBox/src/widgets/UIMiniToolBar.h
@@ -121,8 +121,10 @@ private slots:
     void sltShow();
     /** Adjusts window according to parent. */
     void sltAdjust();
+#if QT_VERSION >= 0x050000
     /** Adjusts window transience according to parent. */
     void sltAdjustTransience();
+#endif
 
 private:
 
