--- src/gl/rectangle.c.orig	Sat Oct 19 21:33:51 2002
+++ src/gl/rectangle.c	Sat Oct 19 21:34:21 2002
@@ -26,12 +26,12 @@
 bool Rectangle::Inside(int a, int b) const
                 {return (a>x && b>y && a<(x+width) && b<(y+height));}
  
-ostream &operator<<(ostream &s, const Rectangle r)
+std::ostream &operator<<(std::ostream &s, const Rectangle r)
 	{s << r.x << " "; s << r.y << " ";
 	 s << r.width << " "; s << r.height << " ";
 	 return s;}
  
-istream &operator>>(istream &s, Rectangle &r)
+std::istream &operator>>(std::istream &s, Rectangle &r)
 	{s >> r.x; s >> r.y;
 	 s >> r.width; s >> r.height;
 	 return s;}
