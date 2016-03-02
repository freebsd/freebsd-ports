Use the right type to avoid overflows and negative values.
--- src/sensors/mem.cpp.orig	2014-09-14 14:15:59 UTC
+++ src/sensors/mem.cpp
@@ -97,7 +97,7 @@ void MemSensor::processExited(K3Process 
 int MemSensor::getMemTotal()
 {
 #if defined Q_OS_FREEBSD || defined(Q_OS_NETBSD) || defined(__DragonFly__)
-    static int mem = 0;
+    static long mem = 0;
     size_t size = sizeof(mem);
 
     sysctlbyname("hw.physmem", &mem, &size, NULL, 0);
@@ -136,7 +136,7 @@ int MemSensor::getMemFree()
 int MemSensor::getBuffers()
 {
 #if defined(Q_OS_FREEBSD) || defined(__DragonFly__)
-    static int mem = 0;
+    static long mem = 0;
     size_t size = sizeof(mem);
 
     sysctlbyname("vfs.bufspace", &mem, &size, NULL, 0);
