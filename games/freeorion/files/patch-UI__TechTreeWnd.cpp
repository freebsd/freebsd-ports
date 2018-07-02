--- ./UI/TechTreeWnd.cpp.orig	Fri Aug 10 21:45:52 2007
+++ ./UI/TechTreeWnd.cpp	Thu Jan 10 23:14:08 2008
@@ -20,6 +20,11 @@
 #include <boost/format.hpp>
 #include <algorithm>
 
+#define PI M_PI
+
+#define POINTS_PER_INCH	72
+#define POINTS(f_inch)	(ROUND((f_inch)*POINTS_PER_INCH))
+#define PS2INCH(ps)		((ps)/(double)POINTS_PER_INCH)
 
 namespace {
     // command-line options
