--- kstars/skyobjects/kscomet.cpp.orig	2014-09-15 23:02:14.160209962 +0200
+++ kstars/skyobjects/kscomet.cpp	2014-09-15 23:03:33.261204279 +0200
@@ -119,7 +119,7 @@
         qint64 fragment   = letterDesigToN( rePro.cap(6) );
 
         uidPart =
-            1          << 43 |
+            1ull       << 43 |
             type       << 40 |  // Bits 40-42 (3)
             halfMonth  << 33 |  // Bits 33-39 (7) Hope this is enough 
             nHalfMonth << 28 |  // Bits 28-32 (5)
