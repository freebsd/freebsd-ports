--- src/SMDS/SMDS_MemoryLimit.cxx.orig	2009-06-08 11:36:15.000000000 +0700
+++ src/SMDS/SMDS_MemoryLimit.cxx	2009-06-08 14:28:59.000000000 +0700
@@ -28,9 +28,15 @@
 // to the system. (PAL16631)
 //
 #ifndef WIN32
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#include <sys/wait.h>
+#else
 #include <sys/sysinfo.h>
 #endif
-
+#endif
 #ifdef _DEBUG_
 #include <iostream>
 #endif
@@ -39,14 +45,24 @@
 {
   // To better understand what is going on here, consult bug [SALOME platform 0019911]
 #ifndef WIN32
-  struct sysinfo si;
-  int err = sysinfo( &si );
-  if ( err )
-    return -1;
-  unsigned long freeRamKb = ( si.freeram  * si.mem_unit ) / 1024;
+//  struct sysinfo si;
+//  int err = sysinfo( &si );
+//  if ( err )
+//    return -1;
+//  unsigned long freeRamKb = ( si.freeram  * si.mem_unit ) / 1024;
 
   // totat RAM size in Gb, float is in order not to have 1 instead of 1.9
-  float totalramGb = float( si.totalram * si.mem_unit ) / 1024 / 1024 / 1024;
+//  float totalramGb = float( si.totalram * si.mem_unit ) / 1024 / 1024 / 1024;
+  long freeRam;
+  long pageSize;
+  long totalmem;
+  int err;
+  size_t sizelong=sizeof(long);
+  sysctlbyname("vm.stats.vm.v_free_count",&freeRam,&sizelong,NULL,0);  //free pages
+  sysctlbyname("hw.pagesize",&pageSize,&sizelong,NULL,0); //page size in kbytes
+  sysctlbyname("hw.physmem",&totalmem,&sizelong,NULL,0); //total memory (in bytes)
+  unsigned long freeRamKb = freeRam*pageSize/1024;
+  float totalramGb = float(totalmem)/1024/1024/1024;
 
   // nb Kbites to allocate at one step. Small nb leads to hung up
   const int stepKb = int( 5 * totalramGb );
@@ -55,9 +71,11 @@
   try {
     while ( nbSteps-- ) {
       new char[stepKb*1024];
-      err = sysinfo( &si );
+//      err = sysinfo( &si );
+	err=sysctlbyname("vm.stats.vm.v_free_count",&freeRam,&sizelong,NULL,0);
       if ( !err )
-        freeRamKb = ( si.freeram  * si.mem_unit ) / 1024;
+//        freeRamKb = ( si.freeram  * si.mem_unit ) / 1024;
+	  freeRamKb = freeRam*pageSize/1024;
     }
   } catch (...) {}
 
