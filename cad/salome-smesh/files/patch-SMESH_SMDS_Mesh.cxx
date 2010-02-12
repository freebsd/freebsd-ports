--- src/SMDS/SMDS_Mesh.cxx.orig	2009-06-08 11:00:20.000000000 +0700
+++ src/SMDS/SMDS_Mesh.cxx	2009-06-08 11:35:21.000000000 +0700
@@ -42,8 +42,15 @@
 using namespace std;
 
 #ifndef WIN32
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#include <sys/wait.h>
+#else
 #include <sys/sysinfo.h>
 #endif
+#endif
 
 // number of added entitis to check memory after
 #define CHECKMEMORY_INTERVAL 1000
@@ -59,10 +66,10 @@
 int SMDS_Mesh::CheckMemory(const bool doNotRaise) throw (std::bad_alloc)
 {
 #ifndef WIN32
-  struct sysinfo si;
-  int err = sysinfo( &si );
-  if ( err )
-    return -1;
+//  struct sysinfo si;
+//  int err = sysinfo( &si );
+//  if ( err )
+//    return -1;
 
   static int limit = -1;
   if ( limit < 0 ) {
@@ -79,11 +86,17 @@
 #endif
   }
 
-  const unsigned long Mbyte = 1024 * 1024;
-  // compute separately to avoid overflow
-  int freeMb =
-    ( si.freeram  * si.mem_unit ) / Mbyte +
-    ( si.freeswap * si.mem_unit ) / Mbyte;
+//  const unsigned long Mbyte = 1024 * 1024;
+  // compute separately to avoid overflow    
+  long freeRam;
+  long pageSize;
+  size_t sizelong=sizeof(long);
+  sysctlbyname("vm.stats.vm.v_free_count",&freeRam,&sizelong,NULL,0);
+  sysctlbyname("hw.pagesize",&pageSize,&sizelong,NULL,0);
+//  sysctlbyname();
+  int freeMb = freeRam*pageSize/1024;
+//    ( si.freeram  * si.mem_unit ) / Mbyte +
+//    ( si.freeswap * si.mem_unit ) / Mbyte;
 
   if ( freeMb > limit )
     return freeMb - limit;
