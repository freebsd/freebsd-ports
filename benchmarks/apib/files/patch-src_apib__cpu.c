--- src/apib_cpu.c.orig	2017-08-28 22:38:37 UTC
+++ src/apib_cpu.c
@@ -14,6 +14,11 @@
    limitations under the License.
 */
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <sys/times.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -35,6 +40,9 @@ static double       TicksPerSecond;
  * for hyperthreading, etc. */
 int cpu_Count(apr_pool_t* pool)
 {
+#ifdef _SC_NPROCESSORS_ONLN
+  return (int)sysconf(_SC_NPROCESSORS_ONLN);
+#else
   apr_status_t s;
   apr_file_t* f;
   char buf[PROC_BUF_LEN];
@@ -66,10 +74,20 @@ int cpu_Count(apr_pool_t* pool)
     count = 1;
   }
   return count;
+#endif
 }
 
 static int getTicks(CPUUsage* cpu, apr_pool_t* pool)
 {
+#ifdef __FreeBSD__
+  struct tms ticks;
+
+  cpu->idle = times(&ticks);
+  if (cpu->idle == -1)
+    return 0;
+  cpu->nonIdle = ticks.tms_utime + ticks.tms_stime;
+  return 1;
+#else
   apr_status_t s;
   apr_file_t* proc;
   char buf[PROC_BUF_LEN];
@@ -118,10 +136,12 @@ static int getTicks(CPUUsage* cpu, apr_pool_t* pool)
   }
 
   return 0;
+#endif
 }
 
 double cpu_GetMemoryUsage(apr_pool_t* pool)
 {
+#ifdef __linux__
   apr_status_t s;
   apr_file_t* proc;
   char buf[PROC_BUF_LEN];
@@ -138,12 +158,36 @@ double cpu_GetMemoryUsage(apr_pool_t* pool)
   if (s != APR_SUCCESS) {
     return 0.0;
   }
+#endif
 
   long totalMem = 0;
   long freeMem = 0;
   long buffers = 0;
   long cache = 0;
 
+#ifdef __FreeBSD__
+  /* We work with kilobytes to match Linux' /proc/meminfo. */
+  long pagesize = sysconf(_SC_PAGESIZE) / 1024;
+  totalMem = sysconf(_SC_PHYS_PAGES) * pagesize;
+
+  size_t len;
+
+  unsigned free;
+  len = sizeof(free);
+  sysctlbyname("vm.stats.vm.v_free_count", &free, &len, NULL, 0);
+  freeMem = free * pagesize;
+
+  /* `buffers' is of expected type (long), no need for another variable. */
+  len = sizeof(buffers);
+  sysctlbyname("vfs.bufspace", &buffers, &len, NULL, 0);
+  buffers /= 1024;
+
+  /* `cache' is based on number of inactive pages since r309017. */
+  unsigned inact;
+  len = sizeof(inact);
+  sysctlbyname("vm.stats.vm.v_inactive_count", &inact, &len, NULL, 0);
+  cache = inact * pagesize;
+#else
   while (linep_NextLine(&line)) {
     char* n = linep_NextToken(&line, " ");
     char* v = linep_NextToken(&line, " ");
@@ -158,6 +202,7 @@ double cpu_GetMemoryUsage(apr_pool_t* pool)
       cache = atol(v);
     }
   }
+#endif
 
   if ((totalMem <= 0) || (freeMem <= 0)) {
     return 0.0;
