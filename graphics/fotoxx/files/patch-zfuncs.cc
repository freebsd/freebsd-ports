--- ./zfuncs.cc.orig	2014-02-05 20:42:34.000000000 +0100
+++ ./zfuncs.cc	2014-02-06 10:32:37.000000000 +0100
@@ -854,7 +854,7 @@
 //  A mutex lock is used to insure one thread at a time has access to the parameter.
 //  Many parameters can be used but there is only one mutex lock.
 
-mutex zget_lock = PTHREAD_MUTEX_INITIALIZER;
+mutex_tp zget_lock = PTHREAD_MUTEX_INITIALIZER;
 
 int zget_locked(int &param)                                                //  lock and return parameter
 {
@@ -1276,7 +1276,7 @@
 namespace shell_asynch_names {
    char     *command[10];
    int      status[10];
-   mutex    mlock = PTHREAD_MUTEX_INITIALIZER;
+   mutex_tp mlock = PTHREAD_MUTEX_INITIALIZER;
 }
 
 int shell_asynch(cchar *Fcommand, ...)                                     //  v.5.5
