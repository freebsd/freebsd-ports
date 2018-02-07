--- lib/Basics/process-utils.cpp.orig	2018-01-05 13:56:52 UTC
+++ lib/Basics/process-utils.cpp
@@ -23,7 +23,7 @@
 
 #include "process-utils.h"
 
-#if defined(TRI_HAVE_MACOS_MEM_STATS)
+#if defined(TRI_HAVE_MACOS_MEM_STATS) || defined(__FreeBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -557,6 +557,7 @@ ProcessInfo TRI_ProcessInfoSelf() {
 }
 
 #else
+#ifdef _WIN32
 /// --------------------------------------------
 /// transform a file time to timestamp
 /// Particularities:
@@ -648,6 +649,7 @@ ProcessInfo TRI_ProcessInfoSelf() {
   return result;
 }
 #endif
+#endif
 
 ////////////////////////////////////////////////////////////////////////////////
 /// @brief returns information about the process
@@ -1435,7 +1437,7 @@ bool TRI_ContinueExternalProcess(Externa
 /// @brief gets the physical memory
 ////////////////////////////////////////////////////////////////////////////////
 
-#if defined(TRI_HAVE_MACOS_MEM_STATS)
+#if defined(TRI_HAVE_MACOS_MEM_STATS) || defined(__FreeBSD__)
 
 static uint64_t GetPhysicalMemory() {
   int mib[2];
