--- kstars/skyobjects/kscomet.cpp.orig	2014-09-19 05:39:42 UTC
+++ kstars/skyobjects/kscomet.cpp
@@ -119,7 +119,7 @@ KSComet::KSComet( const QString &_s, con
         qint64 fragment   = letterDesigToN( rePro.cap(6) );
 
         uidPart =
-            1          << 43 |
+            1ull       << 43 |
             type       << 40 |  // Bits 40-42 (3)
             halfMonth  << 33 |  // Bits 33-39 (7) Hope this is enough 
             nHalfMonth << 28 |  // Bits 28-32 (5)
