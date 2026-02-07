--- jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java
+++ jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java
@@ -26,6 +26,7 @@
 package sun.nio.fs;
 
 import java.nio.file.*;
+import java.nio.file.spi.FileSystemProvider;
 import java.nio.file.spi.FileTypeDetector;
 import java.io.IOException;
 import java.security.AccessController;
@@ -40,6 +41,10 @@
         super();
     }
 
+    public BsdFileSystemProvider(FileSystemProvider f) {
+        super();
+    }
+
     @Override
     BsdFileSystem newFileSystem(String dir) {
         return new BsdFileSystem(this, dir);
@@ -54,7 +59,7 @@
     FileTypeDetector getFileTypeDetector() {
         Path userMimeTypes = Paths.get(AccessController.doPrivileged(
             new GetPropertyAction("user.home")), ".mime.types");
-        Path etcMimeTypes = Paths.get("/etc/mime.types");
+        Path etcMimeTypes = Paths.get("%%LOCALBASE%%/etc/mime.types");
 
         return chain(new GnomeFileTypeDetector(),
                      new MimeTypesFileTypeDetector(userMimeTypes),
