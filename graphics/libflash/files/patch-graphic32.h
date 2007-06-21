--- lib/graphic32.h	Fri May 25 15:04:22 2007
+++ lib2/graphic32.h	Fri May 25 15:06:05 2007
@@ -24,7 +24,7 @@
 
 class GraphicDevice32: public GraphicDevice {
 private:
-	long GraphicDevice32::allocColor(Color color);
+	long allocColor(Color color);
 
 public:
 	GraphicDevice32(FlashDisplay *fd);
