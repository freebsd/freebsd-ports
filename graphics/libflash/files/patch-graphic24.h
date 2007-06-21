--- lib/graphic24.h	Fri May 25 15:04:22 2007
+++ lib2/graphic24.h	Fri May 25 15:06:00 2007
@@ -24,7 +24,7 @@
 
 class GraphicDevice24: public GraphicDevice {
 private:
-	long GraphicDevice24::allocColor(Color color);
+	long allocColor(Color color);
 
 public:
 	GraphicDevice24(FlashDisplay *fd);
