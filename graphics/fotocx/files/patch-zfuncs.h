--- zfuncs.h.orig	2025-11-18 09:44:35 UTC
+++ zfuncs.h
@@ -17,13 +17,15 @@
 
 *********************************************************************************/
 
-#include <sys/sysinfo.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
 #include <sys/time.h>
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
@@ -131,6 +133,7 @@ pthread_t start_Jthread(void * threadfunc(void *), voi
 int  wait_Jthread(pthread_t tid);                                                //  wait for completion (join thread)
 void synch_threads(int NT = 0);                                                  //  synchronize NT threads
 int  main_thread();                                                              //  return 1 if main() thread, else 0
+int  get_nprocs(); // get number of online CPUs in the system
 int  zshell(ch *options, ch *command, ...);                                      //  do shell command and get status
 int  kill_procname(ch *wildname);                                                //  kill processes matching wilcard name
 int  signalProc(ch *pname, ch *signal);                                          //  send signal to process by process name
