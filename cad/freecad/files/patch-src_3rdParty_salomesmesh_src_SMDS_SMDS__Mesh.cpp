--- src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp.orig	2016-09-07 14:39:54 UTC
+++ src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp
@@ -57,7 +57,7 @@
 using namespace std;
 
 #ifndef WIN32
-#if !(defined(__MACH__) && defined(__APPLE__))
+#ifdef __linux__
 #include <sys/sysinfo.h>
 #endif
 #include <sys/wait.h>
