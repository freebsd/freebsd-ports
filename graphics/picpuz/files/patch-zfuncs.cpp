--- zfuncs.cpp.orig	2009-10-29 08:38:40 UTC
+++ zfuncs.cpp
@@ -23,6 +23,11 @@
 //     zfuncs.cpp   version  v.2.28
 
 #include "zfuncs.h"
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#include <sys/types.h>
+#include <pwd.h>
+#endif
 
 /**************************************************************************
    system-level utility functions
@@ -236,7 +241,7 @@ void synch_threads(int NT)
 //  safely access parameters from multiple threads
 //  limitation: one lock for any number of parameters
 
-mutex    zget_lock = PTHREAD_MUTEX_INITIALIZER;
+mutex_tp    zget_lock = PTHREAD_MUTEX_INITIALIZER;
 
 int zget_locked(int &param)                                                //  lock and return parameter
 {
@@ -2916,7 +2921,7 @@ int initz_appfiles(const char *appname, 
    strcpy(zicondir,zdatadir);
    strcat(zicondir,"/icons");
 
-   pp = cuserid(0);
+   pp = getpwuid(geteuid())->pw_name;
    if (strEqu(pp,"root")) snprintf(zuserdir,199,"/root/.%s",zappname);     //  get /root/.appname
    else snprintf(zuserdir,199,"%s/.%s",getenv("HOME"),zappname);           //  or /home/user/.appname
 
@@ -3415,7 +3420,7 @@ pthread_t   tid_main = 0;
 pthread_t   tids[tmax];
 int         tlocks[tmax];
 int         zinit = 0;
-mutex       zmutex;
+mutex_tp       zmutex;
 
 void zlockInit()                                                           //  initz. call from main()
 {
