--- zfuncs.h.orig	2021-10-17 20:02:26 UTC
+++ zfuncs.h
@@ -17,14 +17,17 @@
 
 *********************************************************************************/
 
-#include <sys/sysinfo.h>
+#include <sys/param.h>
+#include <sys/cpuset.h>
+#include <sys/sysctl.h>
 #include <sys/time.h>
 #include <sys/timeb.h>
 #include <sys/stat.h>
 #include <sys/resource.h>
 #include <sys/file.h>
 #include <sys/utsname.h>
-#include <malloc.h>
+#include <sys/wait.h>
+#include <vm/vm_param.h>
 #include <errno.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -130,6 +133,8 @@ pthread_t start_Jthread(void * threadfunc(void *), voi
 int  wait_Jthread(pthread_t tid);                                                //  wait for completion (join thread)
 void synch_threads(int NT = 0);                                                  //  synchronize NT threads
 int  main_thread();                                                              //  return 1 if main() thread, else 0
+int  get_nprocs();
+ //  get number of CPUs in the system
 void set_cpu_affinity(int cpu);                                                  //  set cpu affinity for calling thread
 int  zshell(cchar *options, cchar *command, ...);                                //  do shell command and get status
 int  zshell_gtk(cchar *options, cchar *command, ...);                            //  same, with parallel gtk mainloop
