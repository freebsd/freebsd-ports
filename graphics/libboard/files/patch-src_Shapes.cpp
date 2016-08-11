--- src/Shapes.cpp.orig	2016-06-09 17:30:46 UTC
+++ src/Shapes.cpp
@@ -1908,7 +1908,7 @@ Text::Text( double x, double y,
 }
 
 Text::Text(Point p,
-           const std::__cxx11::string & text,
+           const std::string & text,
            const Fonts::Font font,
            double size,
            Color color,
