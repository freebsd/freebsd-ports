--- src/Templates/array.h.orig	Thu Jan 10 07:22:01 2002
+++ src/Templates/array.h	Fri Sep  3 00:48:47 2004
@@ -100,7 +100,7 @@
 	}
 
 	//construct from C array
-	array(T *inData, int aSize, int initialCap = aSize)
+	array(T *inData, int aSize, int initialCap)
 	{
 		sz = aSize;
 		cap = initialCap;
