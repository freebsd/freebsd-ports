--- src/java/org/apache/cassandra/service/StartupChecks.java.orig	2024-10-12 12:40:43 UTC
+++ src/java/org/apache/cassandra/service/StartupChecks.java
@@ -426,7 +426,13 @@ public class StartupChecks
         {
             if (options.isDisabled(getStartupCheckType()))
                 return;
-            SigarLibrary.instance.warnIfRunningInDegradedMode();
+            try {
+                @SuppressWarnings("unused")
+                Class<?> loadMe = org.hyperic.sigar.SigarException.class;
+                SigarLibrary.instance.warnIfRunningInDegradedMode();
+            } catch (NoClassDefFoundError e) {
+                logger.info("Could not initialize SIGAR library: SIGAR option not selected during install or jar no longer available.");
+            }
         }
     };
 
