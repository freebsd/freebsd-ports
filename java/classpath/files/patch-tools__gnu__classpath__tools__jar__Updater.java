--- tools/gnu/classpath/tools/jar/Updater.java.orig	2010-06-03 15:14:36.000000000 -0400
+++ tools/gnu/classpath/tools/jar/Updater.java	2012-09-20 16:26:23.000000000 -0400
@@ -70,9 +70,13 @@
     // Set this early so that createManifest can use it.
     inputJar = new JarFile(parameters.archiveFile);
 
+    // Find the current directory.
+    File tmpDir = parameters.archiveFile.getParentFile();
+    if (tmpDir == null)
+      tmpDir = new File(".");
+
     // Write all the new entries to a temporary file.
-    File tmpFile = File.createTempFile("jarcopy", null,
-                                       parameters.archiveFile.getParentFile());
+    File tmpFile = File.createTempFile("jarcopy", null, tmpDir);
     OutputStream os = new BufferedOutputStream(new FileOutputStream(tmpFile));
     writeCommandLineEntries(parameters, os);
 
@@ -91,7 +95,7 @@
     if (!tmpFile.renameTo(parameters.archiveFile))
       {
           throw new IOException("Couldn't rename new JAR file " + tmpFile +
-                                "to " + parameters.archiveFile);
+                                " to " + parameters.archiveFile);
       }
   }
 
