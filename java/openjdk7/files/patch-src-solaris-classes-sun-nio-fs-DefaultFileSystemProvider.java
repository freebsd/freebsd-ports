--- jdk/src/solaris/classes/sun/nio/fs/DefaultFileSystemProvider.java	Sun Mar 10 14:04:37 2013 -0400
+++ jdk/src/solaris/classes/sun/nio/fs/DefaultFileSystemProvider.java	Tue Mar 26 18:25:51 2013 -0700
@@ -28,6 +28,8 @@
 import java.nio.file.spi.FileSystemProvider;
 import java.security.AccessController;
 import java.security.PrivilegedAction;
+import java.util.Set;
+import java.util.HashSet;
 import sun.security.action.GetPropertyAction;
 
 /**
@@ -37,6 +39,14 @@
 public class DefaultFileSystemProvider {
     private DefaultFileSystemProvider() { }
 
+    private static final Set<String> validFileSystemProviders
+        = new HashSet<String>();
+    static {
+        validFileSystemProviders.add("sun.nio.fs.SolarisFileSystemProvider");
+        validFileSystemProviders.add("sun.nio.fs.LinuxFileSystemProvider");
+        validFileSystemProviders.add("sun.nio.fs.BsdFileSystemProvider");
+    }
+
     @SuppressWarnings("unchecked")
     private static FileSystemProvider createProvider(final String cn) {
         return AccessController
@@ -64,6 +74,10 @@
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
