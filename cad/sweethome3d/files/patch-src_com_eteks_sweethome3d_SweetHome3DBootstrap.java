--- src/com/eteks/sweethome3d/SweetHome3DBootstrap.java.orig	2020-04-15 10:23:38 UTC
+++ src/com/eteks/sweethome3d/SweetHome3DBootstrap.java
@@ -54,117 +54,31 @@ public class SweetHome3DBootstrap {
     String operatingSystemName = System.getProperty("os.name");
     String javaVersion = System.getProperty("java.version");
     String java7Prefix = "1.7.0_";
-    if (operatingSystemName.startsWith("Mac OS X")) {
-      if (javaVersion.startsWith("1.6")
-          && System.getProperty("com.eteks.sweethome3d.deploymentInformation", "").startsWith("Java Web Start")) {
-        // Refuse to let Sweet Home 3D run under Mac OS X with Java Web Start 6
-        String message = Locale.getDefault().getLanguage().equals(Locale.FRENCH.getLanguage())
-            ? "Sweet Home 3D ne peut pas fonctionner avec Java\n"
-            + "Web Start 6 sous Mac OS X de façon fiable.\n"
-            + "Merci de télécharger le programme d'installation depuis\n"
-            + "http://www.sweethome3d.com/fr/download.jsp"
-            : "Sweet Home 3D can't reliably run with Java Web Start 6\n"
-            + "under Mac OS X.\n"
-            + "Please download the installer version from\n"
-            + "http://www.sweethome3d.com/download.jsp";
-        JOptionPane.showMessageDialog(null, message);
-        System.exit(1);
-      } else if (javaVersion.startsWith("1.5")
-          || javaVersion.startsWith("1.6")) {
-        extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-            "j3dcore.jar", // Main Java 3D jars
-            "vecmath.jar",
-            "j3dutils.jar",
-            "macosx/gluegen-rt.jar", // Mac OS X jars and DLLs for Java 5 or 6
-            "macosx/jogl.jar",
-            "macosx/libgluegen-rt.jnilib",
-            "macosx/libjogl.jnilib",
-            "macosx/libjogl_awt.jnilib",
-            "macosx/libjogl_cg.jnilib"}));
-      } else if (javaVersion.startsWith(java7Prefix)
-          && javaVersion.length() >= java7Prefix.length() + 1
-          && Character.isDigit(javaVersion.charAt(java7Prefix.length()))
-          && (javaVersion.length() >= java7Prefix.length() + 2 // Test version on 2 digits
-          && Character.isDigit(javaVersion.charAt(java7Prefix.length() + 1))
-          && Integer.parseInt(javaVersion.substring(java7Prefix.length(), java7Prefix.length() + 2)) < 40
-          || javaVersion.length() == java7Prefix.length() + 1 // Test whether version is on 1 digit (i.e. < 40)
-          || !Character.isDigit(javaVersion.charAt(java7Prefix.length() + 1)))) {
-        // Refuse to let Sweet Home 3D run under Mac OS X with Java 7 before version 7u40
-        String message = Locale.getDefault().getLanguage().equals(Locale.FRENCH.getLanguage())
-            ? "Sous Mac OS X, Sweet Home 3D ne peut fonctionner avec Java 7\n"
-            + "qu'à partir de la version Java 7u40. Merci de mettre à jour\n"
-            + "votre version de Java ou de lancer Sweet Home 3D sous Java 6."
-            : "Under Mac OS X, Sweet Home 3D can run with Java 7 only\n"
-            + "from version Java 7u40. Please, update you Java version\n"
-            + "or run Sweet Home 3D under Java 6.";
-        JOptionPane.showMessageDialog(null, message);
-        System.exit(1);
-      } else { // Java >= 1.7.0_40
-        extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-            "java3d-1.6/j3dcore.jar", // Mac OS X Java 3D 1.6 jars and DLLs
-            "java3d-1.6/vecmath.jar",
-            "java3d-1.6/j3dutils.jar",
-            "java3d-1.6/gluegen-rt.jar",
-            "java3d-1.6/jogl-java3d.jar",
-            "java3d-1.6/macosx/libgluegen-rt.jnilib",
-            "java3d-1.6/macosx/libjogl_desktop.jnilib",
-            "java3d-1.6/macosx/libnativewindow_awt.jnilib",
-            "java3d-1.6/macosx/libnativewindow_macosx.jnilib"}));
-        // Disable JOGL library loader
-        System.setProperty("jogamp.gluegen.UseTempJarCache", "false");
-      }
-    } else { // Other OS
-      if ("1.5.2".equals(System.getProperty("com.eteks.sweethome3d.j3d.version", "1.6"))
-          || "d3d".equals(System.getProperty("j3d.rend", "jogl"))
-          || javaVersion.startsWith("1.5")) {
-        extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-            "j3dcore.jar", // Main Java 3D jars
-            "vecmath.jar",
-            "j3dutils.jar"}));
-        if ("64".equals(System.getProperty("sun.arch.data.model"))) {
-          extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-              "linux/x64/libj3dcore-ogl.so",    // Linux 64 bits DLL for Java 3D 1.5.2
-              "windows/x64/j3dcore-ogl.dll"})); // Windows 64 bits DLL for Java 3D 1.5.2
-        } else {
-          extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-              "linux/i386/libj3dcore-ogl.so", // Linux 32 bits DLLs
-              "linux/i386/libj3dcore-ogl-cg.so",
-              "windows/i386/j3dcore-d3d.dll", // Windows 32 bits DLLs
-              "windows/i386/j3dcore-ogl.dll",
-              "windows/i386/j3dcore-ogl-cg.dll",
-              "windows/i386/j3dcore-ogl-chk.dll"}));
-        }
-      } else {
-        extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-            "java3d-1.6/j3dcore.jar", // Java 3D 1.6 jars
-            "java3d-1.6/vecmath.jar",
-            "java3d-1.6/j3dutils.jar",
-            "java3d-1.6/gluegen-rt.jar",
-            "java3d-1.6/jogl-java3d.jar"}));
-        // Disable JOGL library loader
-        System.setProperty("jogamp.gluegen.UseTempJarCache", "false");
-        if ("64".equals(System.getProperty("sun.arch.data.model"))) {
-          extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-              "java3d-1.6/linux/amd64/libgluegen-rt.so", // Linux 64 bits DLLs for Java 3D 1.6
-              "java3d-1.6/linux/amd64/libjogl_desktop.so",
-              "java3d-1.6/linux/amd64/libnativewindow_awt.so",
-              "java3d-1.6/linux/amd64/libnativewindow_x11.so",
-              "java3d-1.6/windows/amd64/gluegen-rt.dll", // Windows 64 bits DLLs for Java 3D 1.6
-              "java3d-1.6/windows/amd64/jogl_desktop.dll",
-              "java3d-1.6/windows/amd64/nativewindow_awt.dll",
-              "java3d-1.6/windows/amd64/nativewindow_win32.dll"}));
-        } else {
-          extensionJarsAndDlls.addAll(Arrays.asList(new String [] {
-              "java3d-1.6/linux/i586/libgluegen-rt.so", // Linux 32 bits DLLs for Java 3D 1.6
-              "java3d-1.6/linux/i586/libjogl_desktop.so",
-              "java3d-1.6/linux/i586/libnativewindow_awt.so",
-              "java3d-1.6/linux/i586/libnativewindow_x11.so",
-              "java3d-1.6/windows/i586/gluegen-rt.dll", // Windows 32 bits DLLs for Java 3D 1.6
-              "java3d-1.6/windows/i586/jogl_desktop.dll",
-              "java3d-1.6/windows/i586/nativewindow_awt.dll",
-              "java3d-1.6/windows/i586/nativewindow_win32.dll"}));
-        }
-      }
+    String java8Prefix = "1.8.0_";
+
+    Boolean amd64 = "64".equals(System.getProperty("sun.arch.data.model"));
+    Boolean java7 = (null!=javaVersion && javaVersion.startsWith(java7Prefix));
+    Boolean java8 = (null!=javaVersion && javaVersion.startsWith(java8Prefix));
+
+    if (!amd64 && !java7 && !java8) {
+      extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/i386/libj3dcore-ogl.so");
+    } else if (amd64 && !java7 && !java8) {
+      extensionJarsAndDlls.add("/usr/local/openjdk6/jre/lib/amd64/libj3dcore-ogl.so");
+    } else if (!amd64 && java7) {
+      extensionJarsAndDlls.add("/usr/local/openjdk7/jre/lib/i386/libj3dcore-ogl.so");
+    } else if (amd64 && java7) {
+      extensionJarsAndDlls.add("/usr/local/openjdk7/jre/lib/amd64/libj3dcore-ogl.so");
+    } else if (!amd64 && java8) {
+      extensionJarsAndDlls.add("/usr/local/openjdk8/jre/lib/i386/libj3dcore-ogl.so");
+    } else if (amd64 && java8) {
+      extensionJarsAndDlls.add("/usr/local/openjdk8/jre/lib/amd64/libj3dcore-ogl.so");
+    } else {
+      String message = "Your combination of JDK version and\n"
+                     + "hardware architecture is not supported.\n"
+                     + "If you think that this is an error, please\n"
+                     + "contact the port maintainer.";
+      JOptionPane.showMessageDialog(null, message);
+      System.exit(1);
     }
 
     String [] applicationPackages = {
