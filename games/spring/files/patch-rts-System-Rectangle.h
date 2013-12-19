--- ./rts/System/Rectangle.h.orig	2013-03-26 03:58:36.000000000 +0400
+++ ./rts/System/Rectangle.h	2013-11-11 00:22:51.737774094 +0400
@@ -45,7 +45,7 @@
 			y1 < rect.y2 && y2 > rect.y1;
 	}
 
-	bool operator< (const SRectangle& other) {
+	bool operator< (const SRectangle& other) const {
 		if (x1 == other.x1) {
 			return (z1 < other.z1);
 		} else {
