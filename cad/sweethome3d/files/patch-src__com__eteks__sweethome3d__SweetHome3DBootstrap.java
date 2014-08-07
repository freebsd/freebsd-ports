--- ./src/com/eteks/sweethome3d/SweetHome3DBootstrap.java.orig	2014-08-03 13:59:08.000000000 +0200
+++ ./src/com/eteks/sweethome3d/SweetHome3DBootstrap.java	2014-08-03 15:16:26.000000000 +0200
@@ -54,77 +54,26 @@
     String operatingSystemName = System.getProperty("os.name");
     String javaVersion = System.getProperty("java.version");
     String java7Prefix = "1.7.0_";
-    if (operatingSystemName.startsWith("Mac OS X")
-        && javaVersion.startsWith("1.6")
-        && System.getProperty("com.eteks.sweethome3d.deploymentInformation", "").startsWith("Java Web Start")) {
-      // Refuse to let Sweet Home 3D run under Mac OS X with Java Web Start 6
-      String message = Locale.getDefault().getLanguage().equals(Locale.FRENCH.getLanguage())
-          ? "Sweet Home 3D ne peut pas fonctionner avec Java\n"
-            + "Web Start 6 sous Mac OS X de façon fiable.\n" 
-            + "Merci de télécharger le programme d'installation depuis\n" 
-            + "http://www.sweethome3d.com/fr/download.jsp"
-          : "Sweet Home 3D can't reliably run with Java Web Start 6\n" 
-            + "under Mac OS X.\n" 
-            + "Please download the installer version from\n" 
-            + "http://www.sweethome3d.com/download.jsp";
-      JOptionPane.showMessageDialog(null, message);
-      System.exit(1);
-    } else if (!operatingSystemName.startsWith("Mac OS X")
-               || javaVersion.startsWith("1.5")
-               || javaVersion.startsWith("1.6")) {
-      extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-          "j3dcore.jar", // Main Java 3D jars
-          "vecmath.jar",
-          "j3dutils.jar",
-          "macosx/gluegen-rt.jar", // Mac OS X jars and DLLs for Java 5 or 6
-          "macosx/jogl.jar",
-          "macosx/libgluegen-rt.jnilib",
-          "macosx/libjogl.jnilib",
-          "macosx/libjogl_awt.jnilib",
-          "macosx/libjogl_cg.jnilib"}));
-    } else if (javaVersion.startsWith(java7Prefix)
-               && javaVersion.length() >= java7Prefix.length() + 1
-               && Character.isDigit(javaVersion.charAt(java7Prefix.length()))
-               && (javaVersion.length() >= java7Prefix.length() + 2 // Test version on 2 digits
-                      && Character.isDigit(javaVersion.charAt(java7Prefix.length() + 1))
-                      && Integer.parseInt(javaVersion.substring(java7Prefix.length(), java7Prefix.length() + 2)) < 40
-                   || javaVersion.length() == java7Prefix.length() + 1 // Test whether version is on 1 digit (i.e. < 40)
-                   || !Character.isDigit(javaVersion.charAt(java7Prefix.length() + 1)))) {
-      // Refuse to let Sweet Home 3D run under Mac OS X with Java 7 before version 7u40 
-      String message = Locale.getDefault().getLanguage().equals(Locale.FRENCH.getLanguage())
-          ? "Sous Mac OS X, Sweet Home 3D ne peut fonctionner avec Java 7\n" 
-            + "qu'à partir de la version Java 7u40. Merci de mettre à jour\n" 
-            + "votre version de Java ou de lancer Sweet Home 3D sous Java 6."
-      	  : "Under Mac OS X, Sweet Home 3D can run with Java 7 only\n" 
-      	    + "from version Java 7u40. Please, update you Java version\n" 
-            + "or run Sweet Home 3D under Java 6.";
-      JOptionPane.showMessageDialog(null, message);
-      System.exit(1);
-    } else { // Java >= 1.7.0_40    
-      extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-          "macosx/java3d-1.6/j3dcore.jar", // Mac OS X Java 3D 1.6 jars and DLLs
-          "macosx/java3d-1.6/vecmath.jar",
-          "macosx/java3d-1.6/j3dutils.jar",
-          "macosx/java3d-1.6/gluegen.jar", 
-          "macosx/java3d-1.6/jogl-java3d.jar",
-          "macosx/java3d-1.6/libgluegen-rt.jnilib",
-          "macosx/java3d-1.6/libjogl_desktop.jnilib",
-          "macosx/java3d-1.6/libnativewindow_awt.jnilib",
-          "macosx/java3d-1.6/libnativewindow_macosx.jnilib"}));
-      // Disable JOGL library loader
-      System.setProperty("jogamp.gluegen.UseTempJarCache", "false");
-    }
-    if ("64".equals(System.getProperty("sun.arch.data.model"))) {
-      extensionJarsAndDlls.add("linux/x64/libj3dcore-ogl.so"); // Linux 64 bits DLLs
-      extensionJarsAndDlls.add("windows/x64/j3dcore-ogl.dll"); // Windows 64 bits DLLs
+    
+    Boolean amd64 = "64".equals(System.getProperty("sun.arch.data.model"));
+    Boolean java7 = (null!=javaVersion && javaVersion.startsWith(java7Prefix));
+
+    if (!amd64 && !java7) {
+        extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/i386/libj3dcore-ogl.so");
+    } else if (amd64 && !java7) {
+        extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/amd64/libj3dcore-ogl.so");
+    } else if (!amd64 && java7) {
+        extensionJarsAndDlls.add("/usr/local/openjdk7/jre/lib/i386/libj3dcore-ogl.so");
+    } else if (amd64 && java7) {
+        extensionJarsAndDlls.add("/usr/local/openjdk7/jre/lib/amd64/libj3dcore-ogl.so");
     } else {
-      extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-          "linux/i386/libj3dcore-ogl.so", // Linux 32 bits DLLs
-          "linux/i386/libj3dcore-ogl-cg.so", 
-          "windows/i386/j3dcore-d3d.dll", // Windows 32 bits DLLs
-          "windows/i386/j3dcore-ogl.dll",
-          "windows/i386/j3dcore-ogl-cg.dll",
-          "windows/i386/j3dcore-ogl-chk.dll"}));
+        String message = "Your combination of JDK version and\n" 
+            + "hardware architecture is not supported.\n"
+            + "If you think that this is an error, please\n"
+            + "contact the port maintainer.";
+            
+        JOptionPane.showMessageDialog(null, message);
+        System.exit(1);
     }
     
     String [] applicationPackages = {
@@ -163,4 +112,4 @@
     // Call application class main method with reflection
     applicationClassMain.invoke(null, new Object [] {args});
   }
-}
\ No newline at end of file
+}
