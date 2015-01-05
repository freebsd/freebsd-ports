--- ./hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/src/main/java/org/apache/hadoop/mapred/TaskLog.java.orig	2015-01-06 01:14:31.000000000 +0300
+++ ./hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/src/main/java/org/apache/hadoop/mapred/TaskLog.java	2015-01-06 01:14:47.000000000 +0300
@@ -538,7 +538,7 @@ public class TaskLog {
       mergedCmd.append("(");
     } else if(ProcessTree.isSetsidAvailable && useSetsid &&
         !Shell.WINDOWS) {
-      mergedCmd.append("exec setsid ");
+      mergedCmd.append("exec ssid ");
     } else {
       mergedCmd.append("exec ");
     }
