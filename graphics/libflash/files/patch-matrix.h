--- lib/matrix.h	Fri May 25 15:04:22 2007
+++ lib2/matrix.h	Fri May 25 15:05:10 2007
@@ -33,13 +33,13 @@
 #endif
 
 	inline
-	long Matrix::getX(long x, long y)
+	long getX(long x, long y)
 	{
 		return (long) (x*a+y*b+tx);
 	};
 
 	inline
-	long Matrix::getY(long x, long y)
+	long getY(long x, long y)
 	{
 		return (long) (x*c+y*d+ty);
 	};
