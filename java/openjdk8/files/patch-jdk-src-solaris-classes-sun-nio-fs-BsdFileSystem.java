--- ./jdk/src/solaris/classes/sun/nio/fs/BsdFileSystem.java.orig	2018-12-13 14:23:02.834223000 +0100
+++ ./jdk/src/solaris/classes/sun/nio/fs/BsdFileSystem.java	2018-12-13 17:34:09.359192000 +0100
@@ -45,8 +45,10 @@
     public WatchService newWatchService()
         throws IOException
     {
-        // use polling implementation until we implement a BSD/kqueue one
-        return new PollingWatchService();
+        if (System.getProperty("sun.nio.fs.watchservice", "").equals("polling"))
+            return new PollingWatchService();
+        else
+            return new LinuxWatchService(this); // use the linux inotify implementation that wraps the kqueue calls
     }
 
     // lazy initialization of the list of supported attribute views
