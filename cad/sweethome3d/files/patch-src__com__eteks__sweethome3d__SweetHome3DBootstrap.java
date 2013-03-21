--- ./src/com/eteks/sweethome3d/SweetHome3DBootstrap.java.orig	2012-09-18 23:50:39.000000000 +0200
+++ ./src/com/eteks/sweethome3d/SweetHome3DBootstrap.java	2012-09-18 23:52:55.000000000 +0200
@@ -48,23 +48,12 @@
         "jnlp.jar",
         "j3dcore.jar", // Main Java 3D jars
         "vecmath.jar",
-        "j3dutils.jar",
-        "macosx/gluegen-rt.jar", // Mac OS X jars and DLLs
-        "macosx/jogl.jar",
-        "macosx/libgluegen-rt.jnilib",
-        "macosx/libjogl.jnilib",
-        "macosx/libjogl_awt.jnilib",
-        "macosx/libjogl_cg.jnilib"}));
+        "j3dutils.jar"
+    }));
     if ("64".equals(System.getProperty("sun.arch.data.model"))) {
-      extensionJarsAndDlls.add("linux/x64/libj3dcore-ogl.so"); // Linux 64 bits DLLs
-      extensionJarsAndDlls.add("windows/x64/j3dcore-ogl.dll"); // Windows 64 bits DLLs
+      extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/amd64/libj3dcore-ogl.so");
     } else {
-      extensionJarsAndDlls.add("linux/i386/libj3dcore-ogl.so"); // Linux 32 bits DLLs
-      extensionJarsAndDlls.add("linux/i386/libj3dcore-ogl-cg.so"); // Windows 32 bits DLLs
-      extensionJarsAndDlls.add("windows/i386/j3dcore-d3d.dll");
-      extensionJarsAndDlls.add("windows/i386/j3dcore-ogl.dll");
-      extensionJarsAndDlls.add("windows/i386/j3dcore-ogl-cg.dll");
-      extensionJarsAndDlls.add("windows/i386/j3dcore-ogl-chk.dll");
+      extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/i386/libj3dcore-ogl.so");
     }
     
     String [] applicationPackages = {
@@ -93,4 +82,4 @@
     // Call application class main method with reflection
     applicationClassMain.invoke(null, new Object [] {args});
   }
-}
\ No newline at end of file
+}
