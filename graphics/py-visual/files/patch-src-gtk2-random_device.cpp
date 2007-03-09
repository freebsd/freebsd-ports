--- src/gtk2/random_device.cpp	Sat Jul 31 20:20:28 2004
+++ src/gtk2/random_device.cpp.port	Tue Mar  6 13:17:28 2007
@@ -32,7 +32,7 @@
 #endif
 
 // Known to be supported for GNU/Linux and Apple OSX.  Probably others as well.
-#if defined(__linux__) || (defined(__APPLE__) && defined(__MACH__))
+#if defined(__linux__) || defined(__FreeBSD__) || (defined(__APPLE__) && defined(__MACH__))
 
 // the default is the unlimited capacity device, using some secure hash
 // try "/dev/random" for blocking when the entropy pool has drained
