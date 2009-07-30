--- scheduler/lockfs.c.orig	2009-07-08 23:45:57.000000000 -0300
+++ scheduler/lockfs.c	2009-07-30 12:15:25.000000000 -0300
@@ -32,6 +32,8 @@
 #include "scheduler.h"
 #include "logging.h"
 
+#define LOCK_PREFIX "/var/tmp"
+
 /********************************************
  LockGetPID() returns PID of process that 
  owns a lock (or zero if there is no lock).
@@ -43,8 +45,11 @@
   int Handle;
   int rc;
   char S[10];
+  char _lockfile[FILENAME_MAX];
+
+  snprintf(_lockfile, sizeof(_lockfile), "%s/%s", LOCK_PREFIX, ProcessName);
 
-  Handle = shm_open(ProcessName,O_RDONLY,0444);
+  Handle = shm_open(_lockfile,O_RDONLY,0444);
   if (Handle < 0)
   {
     /* don't report error if lock file does not exist.  That may be normal.  */
@@ -59,7 +64,7 @@
   if (Pid < 2)
   {
     /* bogus pid can't be less than 2 digits, remove lockfile */
-    if (shm_unlink(ProcessName) == -1)
+    if (shm_unlink(_lockfile) == -1)
       LogPrint("*** failed to remove invalid lock file for %s (see LockGetPID). %s\n", ProcessName, strerror(errno));
     return(0);
   }
@@ -99,7 +104,11 @@
  ********************************************/
 int	UnlockName	(char *ProcessName)
 {
-  return(shm_unlink(ProcessName));
+  char _lockfile[FILENAME_MAX];
+
+  snprintf(_lockfile, sizeof(_lockfile), "%s/%s", LOCK_PREFIX, ProcessName);
+
+  return(shm_unlink(_lockfile));
 } /* UnlockName() */
 
 /********************************************
@@ -114,13 +123,16 @@
   int rv;
   pid_t Pid = 0;
   char S[10];
+  char _lockfile[FILENAME_MAX];
+
+  snprintf(_lockfile, sizeof(_lockfile), "%s/%s", LOCK_PREFIX, ProcessName);
 
   /* return if there is already a lock */
   Pid = LockGetPID(ProcessName);
   if (Pid) return (Pid);
 
   /* No lock, so create the lock file */
-  Handle = shm_open(ProcessName,O_RDWR|O_CREAT|O_EXCL,0744);
+  Handle = shm_open(_lockfile,O_RDWR|O_CREAT|O_EXCL,0744);
   if (-1 == Handle)
   {
     /* create failed */
