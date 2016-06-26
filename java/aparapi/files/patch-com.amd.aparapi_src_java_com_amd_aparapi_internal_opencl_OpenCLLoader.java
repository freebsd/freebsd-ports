--- com.amd.aparapi/src/java/com/amd/aparapi/internal/opencl/OpenCLLoader.java.orig	2015-09-21 01:20:26 UTC
+++ com.amd.aparapi/src/java/com/amd/aparapi/internal/opencl/OpenCLLoader.java
@@ -26,10 +26,8 @@ public class OpenCLLoader extends OpenCL
          logger.fine("arch = " + arch);
          String aparapiLibraryName = null;
 
-         if (arch.equals("amd64") || arch.equals("x86_64")) {
-            aparapiLibraryName = "aparapi_x86_64";
-         } else if (arch.equals("x86") || arch.equals("i386")) {
-            aparapiLibraryName = "aparapi_x86";
+         if (arch.equals("amd64") || arch.equals("x86_64") || arch.equals("x86") || arch.equals("i386")) {
+            aparapiLibraryName = "aparapi";
          } else {
             logger.warning("Expected property os.arch to contain amd64, x86_64, x86 or i386 but instead found " + arch
                   + " as a result we don't know which aparapi to attempt to load.");
