--- src/java/org/apache/cassandra/service/StartupChecks.java.orig	2020-08-28 13:55:56 UTC
+++ src/java/org/apache/cassandra/service/StartupChecks.java
@@ -281,7 +281,14 @@ public class StartupChecks
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
 
