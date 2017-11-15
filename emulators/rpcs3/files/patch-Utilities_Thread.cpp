Utilities/Thread.cpp:1920:2: error: unknown type name 'cpu_set_t'; did you mean 'cpusetid_t'?
        cpu_set_t cs;
        ^~~~~~~~~
        cpusetid_t
/usr/include/sys/types.h:84:22: note: 'cpusetid_t' declared here
typedef __cpusetid_t    cpusetid_t;
                        ^
Utilities/Thread.cpp:1921:2: error: use of undeclared identifier 'CPU_ZERO'
        CPU_ZERO(&cs);
        ^
Utilities/Thread.cpp:1922:2: error: use of undeclared identifier 'CPU_SET'
        CPU_SET(core, &cs);
        ^
Utilities/Thread.cpp:1923:48: error: unknown type name 'cpu_set_t'; did you mean 'cpusetid_t'?
        pthread_setaffinity_np(pthread_self(), sizeof(cpu_set_t), &cs);
                                                      ^~~~~~~~~
                                                      cpusetid_t

--- Utilities/Thread.cpp.orig	2017-11-15 18:00:02 UTC
+++ Utilities/Thread.cpp
@@ -25,6 +25,11 @@
 #include <sys/resource.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <pthread_np.h>
+#define cpu_set_t cpuset_t
+#endif
+
 #include "sync.h"
 
 thread_local u64 g_tls_fault_all = 0;
@@ -1916,7 +1921,7 @@ void thread_ctrl::set_ideal_processor_core(int core)
 #ifdef _WIN32
 	HANDLE _this_thread = GetCurrentThread();
 	SetThreadIdealProcessor(_this_thread, core);
-#else
+#elif defined(__linux__) || defined(__DragonFly__) || defined(__FreeBSD__)
 	cpu_set_t cs;
 	CPU_ZERO(&cs);
 	CPU_SET(core, &cs);
