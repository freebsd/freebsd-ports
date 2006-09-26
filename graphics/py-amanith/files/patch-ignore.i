--- ignore.i	Fri May  5 01:23:47 2006
+++ ignore.i	Tue Sep 26 03:54:57 2006
@@ -15,6 +15,7 @@
 %ignore Amanith::GEllipseCurve2D::YAxis;
 %ignore Amanith::GFont2D::CharMap;
 %ignore Amanith::GRenderingContext::GRenderingContext;
+%ignore Amanith::GDrawBoard::DrawEllipseArc;
 
 /* Don't mind these unsupported things */
 %warnfilter(362) Amanith::GInterval::operator=;
