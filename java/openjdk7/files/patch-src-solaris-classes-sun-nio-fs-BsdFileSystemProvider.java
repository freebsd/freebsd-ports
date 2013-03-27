--- jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java.orig
+++ jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java
@@ -27,6 +27,7 @@
 
 import java.nio.file.*;
 import java.nio.file.attribute.*;
+import java.nio.file.spi.FileSystemProvider;
 import java.io.IOException;
 
 /**
@@ -38,6 +39,10 @@
         super();
     }
 
+    public BsdFileSystemProvider(FileSystemProvider f) {
+        super();
+    }
+
     @Override
     BsdFileSystem newFileSystem(String dir) {
        return new BsdFileSystem(this, dir);
