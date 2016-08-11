--- src/rtapi/uspace_rtapi_app.cc.orig	2016-06-25 02:19:12 UTC
+++ src/rtapi/uspace_rtapi_app.cc
@@ -17,7 +17,9 @@
 
 #include "config.h"
 
+#ifdef __linux__
 #include <sys/fsuid.h>
+#endif
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
@@ -42,8 +44,13 @@
 #endif
 #include <sys/resource.h>
 #include <sys/mman.h>
-#include <malloc.h>
+#ifdef __linux__
 #include <sys/prctl.h>
+#endif
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
+
 
 #include "config.h"
 
@@ -56,6 +63,10 @@
 #include <sys/shm.h>		/* shmget() */
 #include <string.h>
 
+#ifndef __linux__
+#define cpu_set_t cpuset_t
+#endif
+
 static int rtapi_clock_nanosleep(clockid_t clock_id, int flags,
         const struct timespec *prequest, struct timespec *remain,
         const struct timespec *pnow);
@@ -462,7 +473,11 @@ int main(int argc, char **argv) {
             "Running with fallback_uid.  getuid()=%d geteuid()=%d\n",
             getuid(), geteuid());
     }
+#ifdef __linux__
     setfsuid(getuid());
+#else
+    seteuid(getuid());
+#endif
     vector<string> args;
     for(int i=1; i<argc; i++) { args.push_back(string(argv[i])); }
 
@@ -589,6 +604,7 @@ static void configure_memory()
     res = mlockall(MCL_CURRENT | MCL_FUTURE);
     if(res < 0) perror("mlockall");
 
+#ifdef __linux__
     /* Turn off malloc trimming.*/
     if (!mallopt(M_TRIM_THRESHOLD, -1)) {
         rtapi_print_msg(RTAPI_MSG_WARN,
@@ -599,6 +615,7 @@ static void configure_memory()
         rtapi_print_msg(RTAPI_MSG_WARN,
                   "mallopt(M_MMAP_MAX, -1) failed\n");
     }
+#endif
     char *buf = static_cast<char *>(malloc(PRE_ALLOC_SIZE));
     if (buf == NULL) {
         rtapi_print_msg(RTAPI_MSG_WARN, "malloc(PRE_ALLOC_SIZE) failed\n");
@@ -617,9 +634,12 @@ static void configure_memory()
 
 static int harden_rt()
 {
+    struct sigaction sig_act = {};
+
     if(!rtapi_is_realtime()) return -EINVAL;
 
     WITH_ROOT;
+#ifdef __linux__
 #if defined(__x86_64__) || defined(__i386__)
     if (iopl(3) < 0) {
         rtapi_print_msg(RTAPI_MSG_ERR,
@@ -629,7 +649,6 @@ static int harden_rt()
     }
 #endif
 
-    struct sigaction sig_act = {};
     // enable realtime
     if (setrlimit(RLIMIT_RTPRIO, &unlimited) < 0)
     {
@@ -638,18 +657,20 @@ static int harden_rt()
 		  strerror(errno));
         return -errno;
     }
+#endif /* __linux__ */
 
     // enable core dumps
     if (setrlimit(RLIMIT_CORE, &unlimited) < 0)
 	rtapi_print_msg(RTAPI_MSG_WARN,
 		  "setrlimit: %s - core dumps may be truncated or non-existant\n",
 		  strerror(errno));
-
+#ifdef __linux__
     // even when setuid root
     if (prctl(PR_SET_DUMPABLE, 1) < 0)
 	rtapi_print_msg(RTAPI_MSG_WARN,
 		  "prctl(PR_SET_DUMPABLE) failed: no core dumps will be created - %d - %s\n",
 		  errno, strerror(errno));
+#endif /* __linux__ */
 
     configure_memory();
 
@@ -669,6 +690,7 @@ static int harden_rt()
     sigaction(SIGTERM, &sig_act, (struct sigaction *) NULL);
     sigaction(SIGINT, &sig_act, (struct sigaction *) NULL);
 
+#ifdef __linux__
     int fd = open("/dev/cpu_dma_latency", O_WRONLY | O_CLOEXEC);
     if (fd < 0) {
         rtapi_print_msg(RTAPI_MSG_WARN, "failed to open /dev/cpu_dma_latency: %s\n", strerror(errno));
@@ -682,6 +704,7 @@ static int harden_rt()
         }
         // deliberately leak fd until program exit
     }
+#endif /* __linux__ */
     return 0;
 }
 
