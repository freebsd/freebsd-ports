--- lib/graphic16.h	Fri May 25 15:04:22 2007
+++ lib2/graphic16.h	Fri May 25 15:05:53 2007
@@ -24,7 +24,7 @@
 
 class GraphicDevice16: public GraphicDevice {
 private:
-	long GraphicDevice16::allocColor(Color color);
+	long allocColor(Color color);
 
 public:
 	GraphicDevice16(FlashDisplay *fd);
