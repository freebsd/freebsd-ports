$FreeBSD$

--- jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java.orig	2013-10-28 01:26:45.766774262 +0100
+++ jdk/src/solaris/classes/sun/nio/ch/DefaultAsynchronousChannelProvider.java	2013-10-28 01:27:24.043766301 +0100
@@ -50,7 +50,7 @@
             return new SolarisAsynchronousChannelProvider();
         if (osname.equals("Linux"))
             return new LinuxAsynchronousChannelProvider();
-        if (osname.contains("OS X"))
+        if (osname.contains("OS X") || osname.equals("FreeBSD"))
             return new BsdAsynchronousChannelProvider();
         throw new InternalError("platform not recognized");
     }
