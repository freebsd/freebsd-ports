--- async/core/AsyncConfig.h.orig	2013-05-25 13:14:51.000000000 -0700
+++ async/core/AsyncConfig.h	2014-04-20 22:49:04.000000000 -0700
@@ -212,7 +212,9 @@
       }
       std::stringstream ssval(str_val);
       Rsp tmp;
-      ssval >> tmp >> std::ws;
+      ssval >> tmp;
+      if(!ssval.eof())
+        ssval >> std::ws;
       if (ssval.fail() || !ssval.eof())
       {
 	return false;
@@ -261,7 +263,9 @@
       while (!ssval.eof())
       {
         Value tmp;
-        ssval >> tmp >> std::ws;
+        ssval >> tmp;
+        if(!ssval.eof())
+          ssval >> std::ws;
         if (ssval.fail())
         {
           return false;
@@ -304,7 +308,9 @@
       }
       std::stringstream ssval(str_val);
       Rsp tmp;
-      ssval >> tmp >> std::ws;
+      ssval >> tmp;
+      if(!ssval.eof())
+        ssval >> std::ws;
       if (ssval.fail() || !ssval.eof() || (tmp < min) || (tmp > max))
       {
 	return false;
