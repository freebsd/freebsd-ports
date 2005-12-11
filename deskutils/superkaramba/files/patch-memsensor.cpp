--- superkaramba/src/memsensor.cpp.orig	Sun Dec 11 02:34:49 2005
+++ superkaramba/src/memsensor.cpp	Sun Dec 11 02:35:08 2005
@@ -99,7 +99,7 @@
 
 int MemSensor::getMemTotal()
 {
-#if defined __FreeBSD || defined(Q_OS_NETBSD)
+#if defined __FreeBSD__ || defined(Q_OS_NETBSD)
     static int mem = 0;
     size_t size = sizeof(mem);
 
