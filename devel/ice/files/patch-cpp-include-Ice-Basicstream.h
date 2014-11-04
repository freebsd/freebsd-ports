--- cpp/include/Ice/BasicStream.h.orig	2014-11-04 18:12:19.183757485 +0100
+++ cpp/include/Ice/BasicStream.h	2014-11-04 18:13:37.223886887 +0100
@@ -964,7 +964,7 @@
 
         struct InstanceData
         {
-            InstanceData(InstanceData* previous) : previous(previous), next(0)
+            InstanceData(InstanceData* prev) : previous(prev), next(0)
             {
                 if(previous)
                 {
@@ -1123,7 +1123,7 @@
 
         struct InstanceData
         {
-            InstanceData(InstanceData* previous) : previous(previous), next(0)
+            InstanceData(InstanceData* prev) : previous(prev), next(0)
             {
                 if(previous)
                 {
