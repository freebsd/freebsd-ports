--- src/gl/point.c.orig	Sat Oct 19 21:32:33 2002
+++ src/gl/point.c	Sat Oct 19 21:33:30 2002
@@ -41,8 +41,8 @@
 bool operator!=(const Point &p1, const Point &p2) {
 	return (p1.x != p2.x || p1.y != p2.y); }
 
-ostream &operator<<(ostream &o, const Point p)
+std::ostream &operator<<(std::ostream &o, const Point p)
 	{o << p.x << " "; o << p.y; return o;}
  
-istream &operator>>(istream &i, Point &p)
+std::istream &operator>>(std::istream &i, Point &p)
 	{i >> p.x; i >> p.y; return i;}
