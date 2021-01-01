--- lib/Basics/process-utils.cpp.orig	2017-11-15 11:23:07 UTC
+++ lib/Basics/process-utils.cpp
@@ -23,7 +23,7 @@
 
 #include "process-utils.h"
 
-#if defined(TRI_HAVE_MACOS_MEM_STATS)
+#if defined(TRI_HAVE_MACOS_MEM_STATS) || defined (__FreeBSD__)
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
@@ -581,6 +581,7 @@ TRI_process_info_t TRI_ProcessInfoSelf()
 }
 
 #else
+#ifdef _WIN32
 /// --------------------------------------------
 /// transform a file time to timestamp
 /// Particularities:
@@ -673,6 +674,7 @@ TRI_process_info_t TRI_ProcessInfoSelf()
   return result;
 }
 #endif
+#endif
 
 ////////////////////////////////////////////////////////////////////////////////
 /// @brief returns information about the process
@@ -1254,7 +1256,7 @@ bool TRI_ContinueExternalProcess(TRI_ext
 /// @brief gets the physical memory
 ////////////////////////////////////////////////////////////////////////////////
 
-#if defined(TRI_HAVE_MACOS_MEM_STATS)
+#if defined(TRI_HAVE_MACOS_MEM_STATS) || defined(__FreeBSD__)
 
 static uint64_t GetPhysicalMemory() {
   int mib[2];
@@ -1297,6 +1299,7 @@ static uint64_t GetPhysicalMemory() {
 
 #else
 
+#ifdef _WIN32
 static uint64_t GetPhysicalMemory() {
   PROCESS_MEMORY_COUNTERS pmc;
   memset(&result, 0, sizeof(result));
@@ -1307,6 +1310,7 @@ static uint64_t GetPhysicalMemory() {
   }
   return 0;
 }
+#endif  // _WIN32
 #endif
 #endif
 #endif
