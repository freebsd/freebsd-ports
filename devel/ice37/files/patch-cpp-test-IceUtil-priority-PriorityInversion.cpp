--- cpp/test/IceUtil/priority/PriorityInversion.cpp.orig	2018-04-20 15:02:08 UTC
+++ cpp/test/IceUtil/priority/PriorityInversion.cpp
@@ -342,8 +342,8 @@ PriorityInversionTest::run()
         return; // Mutex protocol PrioInherit not supported
     }
     cores = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
-    high = 45;
-    medium = 35;
+    high = 31;
+    medium = 15;
     low = 1;
 #endif
 
