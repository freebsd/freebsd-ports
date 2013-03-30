--- zfuncs.h.orig	2011-02-28 16:04:24.000000000 +0000
+++ zfuncs.h	2013-03-30 08:58:28.000000000 +0000
@@ -36,7 +36,13 @@
 #include <signal.h>
 #include <execinfo.h>
 #include <locale.h>
-#include <sys/inotify.h>
+
+#ifdef __linux__
+   #include <sys/inotify.h>
+#elif defined(__FreeBSD__)
+   #include <sys/event.h>
+   #include <sys/types.h>
+#endif
 
 #define  int8   char                                                       //  number types
 #define  int16  short
@@ -52,7 +58,7 @@
 
 #define  wstrerror(err) strerror(WEXITSTATUS(err))                         //  get text status for child process
 
-#define  mutex          pthread_mutex_t                                    //  abbreviations
+#define  mutex_tp          pthread_mutex_t                                    //  abbreviations
 #define  mutex_init     pthread_mutex_init
 #define  mutex_lock     pthread_mutex_lock
 #define  mutex_trylock  pthread_mutex_trylock
@@ -504,7 +510,7 @@
 {
    char        wmi[8];
    Vxstring  * vd;                                                         //  vector of xstrings
-   mutex       qmutex;                                                     //  for multi-thread access
+   mutex_tp       qmutex;                                                     //  for multi-thread access
    int         qcap;                                                       //  queue capacity
    int         qcount;                                                     //  curr. queue count
    int         ent1;                                                       //  first entry pointer
