--- src/mod_inputdev/inputdev_serial/inputdev_serial.cpp.orig	2009-03-07 18:41:23.000000000 +0200
+++ src/mod_inputdev/inputdev_serial/inputdev_serial.cpp	2009-04-11 13:08:44.939571159 +0300
@@ -44,6 +44,8 @@
 
 #ifdef WIN32
 #define DEFAULT_PORT_NAME "COM1"
+#elif defined (__FreeBSD__)
+#define DEFAULT_PORT_NAME "/dev/cuad0"
 #else
 #define DEFAULT_PORT_NAME "/dev/ttyS0"
 #endif
@@ -444,11 +446,19 @@
 #else
   // --- implementation for other OSes ----------------------------------------
   #ifdef OLD_WAY
+#if defined (__FreeBSD__)
+  const char* serialDevs[] = {"/dev/cuad0", "/dev/cuad1",
+                              "/dev/cuad2", "/dev/cuad3",
+                              "/dev/cuaU0", "/dev/cuaU1",
+                              "/dev/cuaU2", "/dev/cuaU3",
+                              NULL};
+#else
   const char* serialDevs[] = {"/dev/ttyS0", "/dev/ttyS1",
                               "/dev/ttyS2", "/dev/ttyS3",
                               "/dev/ttyUSB0", "/dev/ttyUSB1",
                               "/dev/ttyUSB2", "/dev/ttyUSB3",
                               NULL};
+#endif
   const char** ptr;
   
   for (ptr = serialDevs; *ptr != NULL; ptr++)
@@ -459,8 +469,13 @@
   // look for some well-known names in /dev/
   std::vector<std::string> serialDevs;
   std::string sPath = "/dev";
+#if defined (__FreeBSD__)
+  serialDevs.push_back("cuad");
+  serialDevs.push_back("cuaU");
+#else
   serialDevs.push_back("ttyS");
   serialDevs.push_back("ttyUSB");
+#endif
   
   ulDir *dir = ulOpenDir(sPath.c_str());
   if (dir != NULL)
