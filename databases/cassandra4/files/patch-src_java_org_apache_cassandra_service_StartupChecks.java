--- src/java/org/apache/cassandra/service/StartupChecks.java.orig	2023-05-25 14:13:38 UTC
+++ src/java/org/apache/cassandra/service/StartupChecks.java
@@ -363,7 +363,13 @@ public class StartupChecks
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
 
