--- ./zfuncs.h.orig	2014-02-05 20:42:34.000000000 +0100
+++ ./zfuncs.h	2014-02-06 10:32:37.000000000 +0100
@@ -22,7 +22,7 @@
 
 //     zfuncs.h   version  v.5.8
 
-#include <sys/sysinfo.h> 
+//#include <sys/sysinfo.h> 
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/resource.h>
@@ -33,6 +33,7 @@
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <sys/wait.h>
 #include <string.h>
 #include <ctype.h>
 #include <math.h>
@@ -60,7 +61,7 @@
 
 #define  wstrerror(err) strerror(WEXITSTATUS(err))                         //  get text status for child process
 
-#define  mutex          pthread_mutex_t                                    //  abbreviations
+#define  mutex_tp       pthread_mutex_t                                    //  abbreviations
 #define  mutex_init     pthread_mutex_init
 #define  mutex_lock     pthread_mutex_lock
 #define  mutex_trylock  pthread_mutex_trylock
@@ -625,7 +626,7 @@
 {
    char        wmi[8];
    Vxstring  * vd;                                                         //  vector of xstrings
-   mutex       qmutex;                                                     //  for multi-thread access
+   mutex_tp    qmutex;                                                     //  for multi-thread access
    int         qcap;                                                       //  queue capacity
    int         qcount;                                                     //  curr. queue count
    int         ent1;                                                       //  first entry pointer
