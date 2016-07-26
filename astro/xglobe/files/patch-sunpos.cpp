--- sunpos.cpp.orig	1998-12-09 18:51:09 UTC
+++ sunpos.cpp
@@ -203,7 +203,7 @@ double SunPos::julian_date(int y, int m,
   double JD;
 
   /* lazy test to ensure gregorian calendar */
-  ASSERT(y >= 1583);
+  Q_ASSERT(y >= 1583);
 
   if ((m == 1) || (m == 2))
   {
