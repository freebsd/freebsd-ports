--- ./src/com/eteks/sweethome3d/SweetHome3DBootstrap.java.orig	2013-11-01 23:41:20.000000000 +0100
+++ ./src/com/eteks/sweethome3d/SweetHome3DBootstrap.java	2013-11-18 18:43:37.000000000 +0100
@@ -75,13 +75,8 @@
       extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
           "j3dcore.jar", // Main Java 3D jars
           "vecmath.jar",
-          "j3dutils.jar",
-          "macosx/gluegen-rt.jar", // Mac OS X jars and DLLs for Java 5 or 6
-          "macosx/jogl.jar",
-          "macosx/libgluegen-rt.jnilib",
-          "macosx/libjogl.jnilib",
-          "macosx/libjogl_awt.jnilib",
-          "macosx/libjogl_cg.jnilib"}));
+          "j3dutils.jar"
+      }));
     } else if (javaVersion.startsWith(java7Prefix)
                && javaVersion.length() >= java7Prefix.length() + 1
                && Character.isDigit(javaVersion.charAt(java7Prefix.length()))
@@ -116,16 +111,9 @@
       System.setProperty("com.eteks.sweethome3d.j3d.useOffScreen3DView", "true");
     }
     if ("64".equals(System.getProperty("sun.arch.data.model"))) {
-      extensionJarsAndDlls.add("linux/x64/libj3dcore-ogl.so"); // Linux 64 bits DLLs
-      extensionJarsAndDlls.add("windows/x64/j3dcore-ogl.dll"); // Windows 64 bits DLLs
+	  extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/amd64/libj3dcore-ogl.so");
     } else {
-      extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-          "linux/i386/libj3dcore-ogl.so", // Linux 32 bits DLLs
-          "linux/i386/libj3dcore-ogl-cg.so", // Windows 32 bits DLLs
-          "windows/i386/j3dcore-d3d.dll",
-          "windows/i386/j3dcore-ogl.dll",
-          "windows/i386/j3dcore-ogl-cg.dll",
-          "windows/i386/j3dcore-ogl-chk.dll"}));
+      extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/i386/libj3dcore-ogl.so");
     }
     
     String [] applicationPackages = {
@@ -164,4 +152,4 @@
     // Call application class main method with reflection
     applicationClassMain.invoke(null, new Object [] {args});
   }
-}
\ No newline at end of file
+}
