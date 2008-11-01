--- ./LibFoundation/Containment/Wm4ContEllipse2MinCR.cpp.orig	2008-10-31 21:09:27.000000000 +0100
+++ ./LibFoundation/Containment/Wm4ContEllipse2MinCR.cpp	2008-10-31 21:21:10.000000000 +0100
@@ -101,7 +101,9 @@
             iYMin = i;
         }
     }
+#ifdef _DEBUG
     assert(iXMin != -1 && iYMin != -1);
+#endif
     abUsed[iYMin] = true;
 
     // The convex hull is searched in a clockwise manner starting with the
