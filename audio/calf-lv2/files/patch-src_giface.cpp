--- src/giface.cpp.orig	2015-01-24 17:21:09 UTC
+++ src/giface.cpp
@@ -173,7 +173,7 @@ std::string human_readable(float value, 
     }
     double val = abs(value);
     int place = (int)(log(val) / log(base));
-    double num = val / pow(base, place);
+    double num = val / pow((double)base, place);
     sprintf(buf, format, (float)((value > 0) - (value < 0)) * num, suf[place]);
     return string(buf);
 }
