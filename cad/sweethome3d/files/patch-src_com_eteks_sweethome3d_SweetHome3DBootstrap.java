--- src/com/eteks/sweethome3d/SweetHome3DBootstrap.java.orig	2022-07-13 08:03:06 UTC
+++ src/com/eteks/sweethome3d/SweetHome3DBootstrap.java
@@ -135,6 +135,11 @@ public class SweetHome3DBootstrap {
             "yafaray/macosx/libyafarayjni.dylib"}));
         yafarayPluginsFolder = "yafaray/macosx/yafaray-plugins";
       }
+    } else if ("FreeBSD".equals(operatingSystemName)) {
+      extensionJarsAndDlls.addAll(Arrays.asList(new String[] {
+        System.getProperty("sun.boot.library.path") + "/libj3dcore-ogl.so",
+        "yafaray/libyafaray_v3_core.so", "yafaray/libyafarayjni.so" }));
+      yafarayPluginsFolder = "yafaray/yafaray-plugins";
     } else { // Other OS
       if ("1.5.2".equals(System.getProperty("com.eteks.sweethome3d.j3d.version", "1.6"))
           || "d3d".equals(System.getProperty("j3d.rend", "jogl"))
