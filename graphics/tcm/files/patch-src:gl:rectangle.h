--- src/gl/rectangle.h.orig	Sat Oct 19 21:33:45 2002
+++ src/gl/rectangle.h	Sat Oct 19 21:34:44 2002
@@ -80,10 +80,10 @@
 	friend bool operator!=(const Rectangle &x, const Rectangle &y);
 
 	/// Write string representation to ostream.
-	friend ostream &operator<<(ostream &s, const Rectangle r);
+	friend std::ostream &operator<<(std::ostream &s, const Rectangle r);
 
 	/// Read string representation from istream.
-	friend istream &operator>>(istream &s, Rectangle &r);
+	friend std::istream &operator>>(std::istream &s, Rectangle &r);
 
 	/// the left x-coordinate of the rectangle
 	int x;
