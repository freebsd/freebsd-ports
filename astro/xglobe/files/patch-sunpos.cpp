--- sunpos.cpp.orig	1998-12-09 10:51:09.000000000 -0800
+++ sunpos.cpp	2011-01-18 14:22:52.000000000 -0800
@@ -203,7 +203,7 @@
   double JD;
 
   /* lazy test to ensure gregorian calendar */
-  ASSERT(y >= 1583);
+  Q_ASSERT(y >= 1583);
 
   if ((m == 1) || (m == 2))
   {
