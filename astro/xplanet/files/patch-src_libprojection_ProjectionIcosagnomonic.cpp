--- src/libprojection/ProjectionIcosagnomonic.cpp.orig	2009-04-16 15:10:08 UTC
+++ src/libprojection/ProjectionIcosagnomonic.cpp
@@ -26,6 +26,19 @@ using namespace std;
 #define THIGH 3
 #define RATIO (((THIGH)*sqrt(3.0)/2)/(TWIDE))
 
+/* signbit() appaired only in FreeBSD 5.1, so we need this hack */
+#ifndef signbit
+static int
+signbit(double x)
+{
+
+	if ((x < 0.0) || (x = -0.0)) 
+		return 1;
+	else
+		return 0;
+}
+#endif /* signbit */
+
 bool
 ProjectionIcosagnomonic::PointXY::sameSide(const PointXY& p1,
                                            const PointXY& p2,
