--- include/Optimized.h.orig	Sat Dec 31 06:26:59 2005
+++ include/Optimized.h	Thu Oct 11 02:07:55 2007
@@ -193,7 +193,7 @@
 		void Normalize( Point3D& );
 		
 		typedef Point3D Normal3D;
-		typedef std::vector< Point3D, Align< Point3D > > Point3DVector;
+		typedef std::vector< Point3D > Point3DVector;
 
 		void Normalize( Point3DVector& );
 		/*class Point3DVector
