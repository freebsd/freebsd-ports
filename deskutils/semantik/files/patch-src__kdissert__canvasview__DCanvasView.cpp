--- src/kdissert/canvasview/DCanvasView.cpp.orig	Sat Oct 15 22:22:33 2005
+++ src/kdissert/canvasview/DCanvasView.cpp	Tue Oct 18 20:47:13 2005
@@ -1466,6 +1466,7 @@
 	if (x2>canvas()->width()-limit) dx += extend+x2-limit;
 	if (y2>canvas()->height()-limit) dy += extend+y2-limit;
 
+#if !(defined(__GNUC__) && (__GNUC__ < 3))
 	// just for security: check for hard system limits
 	if (((double)canvas()->width()+dx) > (double)std::numeric_limits<typeof(canvas()->width())>::max() || ((double)canvas()->height()+dy) > (double)std::numeric_limits<typeof(canvas()->height())>::max()) {
 		static bool told(false); // should never happen, but say it once...
@@ -1473,6 +1474,7 @@
 		told = true;
 		return;
 	}
+#endif
 
 	// expand if necessary
 	if (dx>0 || dy>0) {
