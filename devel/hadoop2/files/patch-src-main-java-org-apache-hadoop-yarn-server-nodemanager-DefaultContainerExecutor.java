--- hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/DefaultContainerExecutor.java.orig	2015-02-27 14:36:18.000000000 +0300
+++ hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/DefaultContainerExecutor.java	2015-02-27 14:36:48.000000000 +0300
@@ -353,7 +353,7 @@ public class DefaultContainerExecutor ex
         pout.println();
         pout.println("echo $$ > " + pidFile.toString() + ".tmp");
         pout.println("/bin/mv -f " + pidFile.toString() + ".tmp " + pidFile);
-        String exec = Shell.isSetsidAvailable? "exec setsid" : "exec";
+        String exec = Shell.isSetsidAvailable? "exec ssid" : "exec";
         pout.println(exec + " /bin/bash \"" +
             launchDst.toUri().getPath().toString() + "\"");
       } finally {
