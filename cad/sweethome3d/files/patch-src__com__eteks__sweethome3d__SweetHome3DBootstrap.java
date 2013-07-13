--- ./src/com/eteks/sweethome3d/SweetHome3DBootstrap.java.orig	2013-05-31 16:51:26.000000000 +0200
+++ ./src/com/eteks/sweethome3d/SweetHome3DBootstrap.java	2013-07-11 21:24:10.000000000 +0200
@@ -56,13 +56,8 @@
       extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
           "j3dcore.jar", // Main Java 3D jars
           "vecmath.jar",
-          "j3dutils.jar",
-          "macosx/gluegen-rt.jar", // Mac OS X jars and DLLs
-          "macosx/jogl.jar",
-          "macosx/libgluegen-rt.jnilib",
-          "macosx/libjogl.jnilib",
-          "macosx/libjogl_awt.jnilib",
-          "macosx/libjogl_cg.jnilib"}));
+          "j3dutils.jar"
+      }));
     } else {
       String message = Locale.getDefault().getLanguage().equals(Locale.FRENCH.getLanguage())
           ? "Sweet Home 3D ne peut pas encore fonctionner avec Java %c sous Mac OS X.\n" 
@@ -77,16 +72,9 @@
       System.exit(1);
     }
     if ("64".equals(System.getProperty("sun.arch.data.model"))) {
-      extensionJarsAndDlls.add("linux/x64/libj3dcore-ogl.so"); // Linux 64 bits DLLs
-      extensionJarsAndDlls.add("windows/x64/j3dcore-ogl.dll"); // Windows 64 bits DLLs
+      extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/amd64/libj3dcore-ogl.so");
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
@@ -125,4 +113,4 @@
     // Call application class main method with reflection
     applicationClassMain.invoke(null, new Object [] {args});
   }
-}
\ No newline at end of file
+}
