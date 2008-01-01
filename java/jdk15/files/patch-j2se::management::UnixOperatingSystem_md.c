$FreeBSD$

--- ../../j2se/src/solaris/native/com/sun/management/UnixOperatingSystem_md.c	8 Mar 2007 08:40:23 -0000	1.7
+++ ../../j2se/src/solaris/native/com/sun/management/UnixOperatingSystem_md.c	31 Dec 2007 17:45:30 -0000
@@ -16,6 +16,10 @@
 #include <sys/stat.h>
 #if defined(_ALLBSD_SOURCE)
 #include <sys/sysctl.h>
+#if defined(__FreeBSD__)
+#include <vm/vm_param.h>
+#include <sys/time.h>
+#endif
 #else
 #include <sys/swap.h>
 #endif
@@ -133,6 +137,30 @@
 
     return available ? avail : total;
 #else /* _ALLBSD_SOURCE */
+#if defined(__FreeBSD__) && __FreeBSD__ >= 6
+    struct xswdev xsw;
+    size_t mibsize, size;
+    int mib[16], n;
+    jlong total = 0, used = 0;
+
+    mibsize = sizeof mib / sizeof mib[0];
+    if (sysctlnametomib("vm.swap_info", mib, &mibsize) == -1) {
+        throw_internal_error(env, "sysctl failed to get swap size");
+    }
+    for (n = 0; ; ++n) {
+        mib[mibsize] = n;
+        size = sizeof xsw;
+        if (sysctl(mib, mibsize + 1, &xsw, &size, NULL, 0) == -1)
+            break;
+        used += xsw.xsw_used;
+        total += xsw.xsw_nblks;
+    }
+    if (errno != ENOENT) {
+        fprintf(stderr, "sysctl failed to get swap size");
+    }
+
+    return ((jlong) page_size) * (available ? (total - used) : total);
+#endif
     /*
      * XXXBSD: there's no way available to get swap info in
      *         FreeBSD.  Usage of libkvm is not an option here
@@ -225,17 +253,25 @@
 Java_com_sun_management_UnixOperatingSystem_getProcessCpuTime
   (JNIEnv *env, jobject mbean)
 {
-    jlong clk_tck, ns_per_clock_tick;
     jlong cpu_time_ns;
+#if defined(_ALLBSD_SOURCE)
+    struct rusage time;
+    if (getrusage(RUSAGE_SELF, &time) == -1) {
+        throw_internal_error(env,
+                             "getrusage failed - not able to get cpu time");
+        return -1;
+    }
+    cpu_time_ns = ((jlong) (1000 * 1000 * 1000)) *
+                 ((jlong) (time.ru_utime.tv_sec + time.ru_stime.tv_sec));
+    cpu_time_ns += ((jlong) 1000) *
+                 ((jlong) (time.ru_utime.tv_usec + time.ru_stime.tv_usec));
+#else
+    jlong clk_tck, ns_per_clock_tick;
     struct tms time;
 
-    /*
-     * BSDNOTE: FreeBSD implements _SC_CLK_TCK since FreeBSD 5, so
-     *          add a magic to handle it
-     */
 #if defined(__solaris__) || defined(_SC_CLK_TCK)
     clk_tck = (jlong) sysconf(_SC_CLK_TCK);
-#elif defined(__linux__) || defined(_ALLBSD_SOURCE)
+#elif defined(__linux__)
     clk_tck = 100;
 #endif
     if (clk_tck == -1) {
@@ -248,6 +284,7 @@
     ns_per_clock_tick = (jlong) 1000 * 1000 * 1000 / (jlong) clk_tck;
     cpu_time_ns = ((jlong)time.tms_utime + (jlong) time.tms_stime) * 
                       ns_per_clock_tick;
+#endif
     return cpu_time_ns;
 }
 
@@ -256,6 +293,16 @@
   (JNIEnv *env, jobject mbean)
 {
 #ifdef _ALLBSD_SOURCE
+#if defined(__FreeBSD__) && __FreeBSD__ >= 6
+    int free_mem;
+    size_t len = sizeof free_mem;
+
+    if (sysctlbyname("vm.stats.vm.v_free_count", &free_mem, &len, NULL, 0) == -1) {
+        throw_internal_error(env, "Can't get free physical memory count.\n");
+    }
+
+    return ((jlong) page_size) * ((jlong) free_mem);
+#endif
     /*
      * XXXBSD: there's no way available to do it in FreeBSD, AFAIK.
      */
@@ -272,7 +319,7 @@
   (JNIEnv *env, jobject mbean)
 {
 #ifdef _ALLBSD_SOURCE
-    jlong result;
+    unsigned long result;
     int mib[2];
     int rlen;
 
@@ -282,7 +329,7 @@
     if (sysctl(mib, 2, &result, &rlen, NULL, 0) == -1)
 	result = 256 * MB;
 
-    return (result);
+    return (jlong) result;
 #else
     jlong num_physical_pages = sysconf(_SC_PHYS_PAGES);
     return (num_physical_pages * page_size);
