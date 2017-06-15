--- svcore/base/RealTime.cpp.orig	2015-10-22 11:26:02 UTC
+++ svcore/base/RealTime.cpp
@@ -105,7 +105,7 @@ RealTime::fromXsdDuration(std::string xs
         char *eptr = 0;
 
         if (isdigit(s[i]) || s[i] == '.') {
-            value = strtod(&s[i], &eptr);
+            value = strtod_l(&s[i], &eptr, NULL);
             i = int(eptr - s);
         }
 
