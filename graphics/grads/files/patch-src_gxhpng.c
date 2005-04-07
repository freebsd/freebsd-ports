$FreeBSD$

--- src/gxhpng.c.orig	Fri Mar 25 15:23:06 2005
+++ src/gxhpng.c	Fri Mar 25 15:23:48 2005
@@ -377,7 +377,11 @@
   return (retcod);
 }
 	
-int gdCompareInt(const void *a, const void *b);
+int gdCompareInt(const void *a, const void *b)
+{
+	return (*(const int *)a) - (*(const int *)b);
+}
+
 
 /* Version of gdImageFilledPolygon to invoke my local 
    version of gdImageLne.  Nothing else changed... B.Doty 5/31/01 */
