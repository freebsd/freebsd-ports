--- src/com/eteks/sweethome3d/SweetHome3DBootstrap.java.orig	2020-04-15 10:23:38 UTC
+++ src/com/eteks/sweethome3d/SweetHome3DBootstrap.java
@@ -116,6 +116,9 @@ public class SweetHome3DBootstrap {
         // Disable JOGL library loader
         System.setProperty("jogamp.gluegen.UseTempJarCache", "false");
       }
+    } else if ("FreeBSD".equals(operatingSystemName)) {
+      extensionJarsAndDlls.add(System.getProperty("sun.boot.library.path")
+        + "/libj3dcore-ogl.so");
     } else { // Other OS
       if ("1.5.2".equals(System.getProperty("com.eteks.sweethome3d.j3d.version", "1.6"))
           || "d3d".equals(System.getProperty("j3d.rend", "jogl"))
