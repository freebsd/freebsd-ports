--- cint/lib/ipc/ipcif.h.orig
+++ cint/lib/ipc/ipcif.h
@@ -28,13 +28,16 @@
 #include <sys/ipc.h>
 #include <sys/shm.h>
 #include <sys/sem.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #if defined(G__APPLE) || defined(__APPLE__)
 /* union semun is defined by including <sys/sem.h> */
 #elif defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
 /* union semun is defined by including <sys/sem.h> */
 #else
 /* according to X/OPEN we have to define it ourselves */
-#if !defined(__FreeBSD__) && !defined(__KCC) && !defined(__sgi)
+#if (!defined(__FreeBSD__) || __FreeBSD_version >= 1200059) && !defined(__KCC) && !defined(__sgi)
 union semun {
   int val;                    /* value for SETVAL */
   struct semid_ds *buf;       /* buffer for IPC_STAT, IPC_SET */
