--- include/Optimized.h.orig	2005-12-31 03:26:59 UTC
+++ include/Optimized.h
@@ -193,7 +193,7 @@ namespace SharpConstruct
 		void Normalize( Point3D& );
 		
 		typedef Point3D Normal3D;
-		typedef std::vector< Point3D, Align< Point3D > > Point3DVector;
+		typedef std::vector< Point3D > Point3DVector;
 
 		void Normalize( Point3DVector& );
 		/*class Point3DVector
