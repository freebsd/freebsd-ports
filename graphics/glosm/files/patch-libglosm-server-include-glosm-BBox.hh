--- libglosm-server/include/glosm/BBox.hh.orig	2011-02-27 18:05:45.000000000 +0300
+++ libglosm-server/include/glosm/BBox.hh	2013-08-22 15:50:54.227227655 +0400
@@ -48,7 +48,7 @@
 	/**
 	 * Constructs empty bounding box
 	 */
-	BBox(): BBox<T>::Empty() {
+	BBox(): left(std::numeric_limits<T>::max()), bottom(std::numeric_limits<T>::max()), right(std::numeric_limits<T>::min()), top(std::numeric_limits<T>::min()) {
 	}
 
 	/**
