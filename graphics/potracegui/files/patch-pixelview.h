--- src/pixelview.h.orig	Tue Jan 10 02:16:14 2006
+++ src/pixelview.h	Tue Jan 10 02:16:41 2006
@@ -34,7 +34,7 @@
 /**
 @author Tim Fechtner
 */
-class PixelView : protected QScrollView
+class PixelView : public QScrollView
 {
 Q_OBJECT
 public:
