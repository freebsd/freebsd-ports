--- zlibrary/ui/src/qt4/view/ZLQtPaintContext.cpp.orig	2024-12-20 19:22:52 UTC
+++ zlibrary/ui/src/qt4/view/ZLQtPaintContext.cpp
@@ -144,12 +144,12 @@ int ZLQtPaintContext::stringWidth(const char *str, int
 }
 
 int ZLQtPaintContext::stringWidth(const char *str, int len, bool) const {
-	return myPainter->fontMetrics().width(QString::fromUtf8(str, len));
+	return myPainter->fontMetrics().horizontalAdvance(QString::fromUtf8(str, len));
 }
 
 int ZLQtPaintContext::spaceWidth() const {
 	if (mySpaceWidth == -1) {
-		mySpaceWidth = myPainter->fontMetrics().width(' ');
+		mySpaceWidth = myPainter->fontMetrics().horizontalAdvance(' ');
 	}
 	return mySpaceWidth;
 }
