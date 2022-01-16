--- cpp/test/IceUtil/priority/PriorityInversion.cpp.orig	2021-06-21 14:44:58 UTC
+++ cpp/test/IceUtil/priority/PriorityInversion.cpp
@@ -338,8 +338,8 @@ PriorityInversionTest::run()
         return; // Mutex protocol PrioInherit not supported
     }
     cores = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
-    high = 45;
-    medium = 35;
+    high = 31;
+    medium = 15;
     low = 1;
 
     {
