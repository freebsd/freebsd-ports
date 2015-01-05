--- ./hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/Shell.java.orig	2014-06-21 09:40:07.000000000 +0400
+++ ./hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/Shell.java	2015-01-06 01:21:22.000000000 +0300
@@ -348,15 +348,15 @@ abstract public class Shell {
     ShellCommandExecutor shexec = null;
     boolean setsidSupported = true;
     try {
-      String[] args = {"setsid", "bash", "-c", "echo $$"};
+      String[] args = {"ssid", "bash", "-c", "echo $$"};
       shexec = new ShellCommandExecutor(args);
       shexec.execute();
     } catch (IOException ioe) {
-      LOG.debug("setsid is not available on this machine. So not using it.");
+      LOG.debug("ssid is not available on this machine. So not using it.");
       setsidSupported = false;
     } finally { // handle the exit code
       if (LOG.isDebugEnabled()) {
-        LOG.debug("setsid exited with exit code "
+        LOG.debug("ssid exited with exit code "
                  + (shexec != null ? shexec.getExitCode() : "(null executor)"));
       }
     }
