--- misc/common.h.orig	2013-09-14 03:27:37.000000000 -0700
+++ misc/common.h	2014-04-20 22:45:31.000000000 -0700
@@ -119,7 +119,9 @@
 static bool setValueFromString(ValueType &val, const std::string &str)
 {
   std::istringstream ss(str);
-  ss >> std::noskipws >> val >> std::ws;
+  ss >> std::noskipws >> val;
+  if(!ss.eof())
+    ss >> std::ws;
   return !ss.fail() && ss.eof();
 } /* setValueFromString */
 
