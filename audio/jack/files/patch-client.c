--- libjack/client.c.orig	Sun Jan 11 20:07:14 2004
+++ libjack/client.c	Wed Mar 10 13:13:55 2004
@@ -26,20 +26,23 @@
 #else
     #include <sys/poll.h>
 #endif
-
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <pthread.h>
 #include <errno.h>
 #include <fcntl.h>
-#include <sys/types.h>
+
 #include <sys/ipc.h>
 #include <sys/mman.h>
 
 #include <stdarg.h>
 #include <stdio.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <regex.h>
+#include <string.h>
 
 #include <config.h>
 
@@ -1152,8 +1155,12 @@
 				    "thread (%s)", strerror (errno));
 			return -1;
 		}
-                
-#if defined(__APPLE__) && defined(__POWERPC__) 
+
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif                
+#if defined(__APPLE__) && defined(__POWERPC__) || (__FreeBSD_version < 501000)
+
                 // To be implemented
 #else
                 if (mlockall (MCL_CURRENT | MCL_FUTURE) != 0) {
@@ -1307,8 +1314,11 @@
 	 * pages are actually mapped (more important for mlockall(2)
 	 * usage in jack_start_thread())
 	 */
-         
-#if defined(__APPLE__) && defined(__POWERPC__)
+
+#ifdef __FreeBSD__
+#include <osreldate.h>
+#endif        
+#if (defined(__APPLE__) && defined(__POWERPC__)) || (__FreeBSD_version < 501000)
 /* a bigger stack makes the application crash... */
 #define BIG_ENOUGH_STACK 10000
 #else
@@ -1748,6 +1758,15 @@
 	return client->thread_id;
 }
 
+static int64_t
+rdtsc(void)
+{
+        unsigned int i, j;
+#define RDTSC   ".byte 0x0f, 0x31; "
+        asm(RDTSC : "=a"(i), "=d"(j) : );
+        return ((int64_t)j<<32) + (int64_t)i;
+}
+
 #if defined(__APPLE__) && defined(__POWERPC__) 
 
 double __jack_time_ratio;
@@ -1763,6 +1782,7 @@
 jack_time_t
 jack_get_mhz (void)
 {
+#ifndef __FreeBSD__
 	FILE *f = fopen("/proc/cpuinfo", "r");
 	if (f == 0)
 	{
@@ -1803,6 +1823,25 @@
 			return (jack_time_t)mhz;
 		}
 	}
+
+#else
+       int64_t tsc_start, tsc_end;
+       struct timeval tv_start, tv_end;
+       int usec_delay;
+       jack_time_t mhz;
+                     
+       tsc_start = rdtsc();   
+       gettimeofday(&tv_start, NULL);
+       usleep(100000);
+       tsc_end = rdtsc();
+       gettimeofday(&tv_end, NULL);
+                
+       usec_delay = 1000000 * (tv_end.tv_sec - tv_start.tv_sec)
+           + (tv_end.tv_usec - tv_start.tv_usec);
+       mhz = (tsc_end - tsc_start) / usec_delay;
+       printf("cpu MHz:\t %.3f\n",(double) mhz);                  
+       return mhz;
+#endif 
 }
 
 jack_time_t __jack_cpu_mhz;
