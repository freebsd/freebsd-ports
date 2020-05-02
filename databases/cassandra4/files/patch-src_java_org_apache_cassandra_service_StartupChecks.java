--- src/java/org/apache/cassandra/service/StartupChecks.java.orig	2020-01-30 17:34:32 UTC
+++ src/java/org/apache/cassandra/service/StartupChecks.java
@@ -262,7 +262,14 @@ public class StartupChecks
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
 
