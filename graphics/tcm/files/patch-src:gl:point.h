--- src/gl/point.h.orig	Sat Oct 19 21:32:28 2002
+++ src/gl/point.h	Sat Oct 19 21:33:12 2002
@@ -74,10 +74,10 @@
 	void operator*(double c) {x = int(x*c); y = int(y*c);}
 
 	/// Write string representation to ostream.
-	friend ostream &operator<<(ostream &o, const Point p);
+	friend std::ostream &operator<<(std::ostream &o, const Point p);
 
 	/// Read string representation from istream.
-	friend istream &operator>>(istream &i, Point &p);
+	friend std::istream &operator>>(std::istream &i, Point &p);
 
 	/// the x-coordinate.
 	int x;
