--- image/imgs.cpp.orig	2009-04-14 10:20:27.000000000 +0000
+++ image/imgs.cpp	2009-04-14 10:25:19.000000000 +0000
@@ -643,7 +643,7 @@
                                  //put in destination
     dest->put_line (xdest, ydest, destext, &copyline, 0);
   }
-  delete linesums;
+  delete[] linesums;
 }
 
 
@@ -784,7 +784,7 @@
                                  //put in destination
     dest->put_line (xdest, ydest, destext, &copyline, 0);
   }
-  delete linesums;
+  delete[] linesums;
 }
 
 
