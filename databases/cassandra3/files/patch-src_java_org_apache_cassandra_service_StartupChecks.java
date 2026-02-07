--- src/java/org/apache/cassandra/service/StartupChecks.java.orig	2018-02-14 20:43:59 UTC
+++ src/java/org/apache/cassandra/service/StartupChecks.java
@@ -263,7 +263,14 @@ public class StartupChecks
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
 
