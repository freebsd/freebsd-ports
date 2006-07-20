--- libs/random/random_device.cpp.orig	Tue Jul 18 12:48:49 2006
+++ libs/random/random_device.cpp	Tue Jul 18 12:49:59 2006
@@ -22,7 +22,7 @@
 #endif
 
 
-#ifdef __linux__
+#if defined(__linux__) || defined (__FreeBSD__)
 
 // the default is the unlimited capacity device, using some secure hash
 // try "/dev/random" for blocking when the entropy pool has drained
@@ -90,7 +90,7 @@
   int fd;
 };
 
-#endif // __linux__
+#endif // __linux__ || __FreeBSD__
 
 
 boost::random_device::random_device(const std::string& token)
