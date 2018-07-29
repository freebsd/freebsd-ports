--- src/XESCore/DEMDefs.h.orig	2018-07-15 04:23:17 UTC
+++ src/XESCore/DEMDefs.h
@@ -1217,14 +1217,32 @@ inline bool&	DEMMask::operator()(int x, 
 
 inline bool	DEMMask::operator()(int x, int y) const
 {
-	if (x < 0 || x >= mWidth || y < 0 || y >= mHeight) return DEM_NO_DATA;
+        bool b;
+//	if (x < 0 || x >= mWidth || y < 0 || y >= mHeight) return DEM_NO_DATA;
+        if (x < 0 || x >= mWidth || y < 0 || y >= mHeight) 
+	{
+		b=true;
+		return b;
+        }
+        else
+        {
 	return mData[x + y * mWidth];
+        }
 }
 
 inline bool	DEMMask::get(int x, int y) const
 {
-	if (x < 0 || x >= mWidth || y < 0 || y >= mHeight) return DEM_NO_DATA;
+	bool b;
+//	if (x < 0 || x >= mWidth || y < 0 || y >= mHeight) return DEM_NO_DATA;
+        if (x < 0 || x >= mWidth || y < 0 || y >= mHeight)
+        {
+                b=true;
+                return b;
+        }
+        else
+        {
 	return mData[x + y * mWidth];
+	}
 }
 
 inline void	DEMMask::set(int x, int y, bool v)
