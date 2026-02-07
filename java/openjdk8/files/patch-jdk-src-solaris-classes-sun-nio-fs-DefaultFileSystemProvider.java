--- jdk/src/solaris/classes/sun/nio/fs/DefaultFileSystemProvider.java
+++ jdk/src/solaris/classes/sun/nio/fs/DefaultFileSystemProvider.java
@@ -27,6 +27,8 @@
 
 import java.nio.file.spi.FileSystemProvider;
 import java.security.AccessController;
+import java.util.Set;
+import java.util.HashSet;
 import sun.security.action.GetPropertyAction;
 
 /**
@@ -36,6 +38,15 @@
 public class DefaultFileSystemProvider {
     private DefaultFileSystemProvider() { }
 
+    private static final Set<String> validFileSystemProviders
+        = new HashSet<String>();
+    static {
+        validFileSystemProviders.add("sun.nio.fs.SolarisFileSystemProvider");
+        validFileSystemProviders.add("sun.nio.fs.LinuxFileSystemProvider");
+        validFileSystemProviders.add("sun.nio.fs.BsdFileSystemProvider");
+        validFileSystemProviders.add("sun.nio.fs.MacOSXFileSystemProvider");
+    }
+
     @SuppressWarnings("unchecked")
     private static FileSystemProvider createProvider(String cn) {
         Class<FileSystemProvider> c;
@@ -57,6 +68,10 @@
     public static FileSystemProvider create() {
         String osname = AccessController
             .doPrivileged(new GetPropertyAction("os.name"));
+        String fileSystemProvider = System
+            .getProperty("java.nio.file.spi.DefaultFileSystemProvider");
+        if (validFileSystemProviders.contains(fileSystemProvider))
+            return createProvider(fileSystemProvider);
         if (osname.equals("SunOS"))
             return createProvider("sun.nio.fs.SolarisFileSystemProvider");
         if (osname.equals("Linux"))
