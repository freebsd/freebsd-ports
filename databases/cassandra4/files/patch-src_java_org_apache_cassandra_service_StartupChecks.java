--- src/java/org/apache/cassandra/service/StartupChecks.java.orig	2020-07-17 21:24:30 UTC
+++ src/java/org/apache/cassandra/service/StartupChecks.java
@@ -276,7 +276,14 @@ public class StartupChecks
     {
         public void execute()
         {
-            SigarLibrary.instance.warnIfRunningInDegradedMode();
+            try {
+                @SuppressWarnings("unused")
+                Class<?> loadMe = org.hyperic.sigar.SigarException.class;
+                
+                SigarLibrary.instance.warnIfRunningInDegradedMode();
+            } catch (NoClassDefFoundError e) {
+                logger.info("Could not initialize SIGAR library: SIGAR option not selected during install or jar no longer available.");
+            }
         }
     };
 
