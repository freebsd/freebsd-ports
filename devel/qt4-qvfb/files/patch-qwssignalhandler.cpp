--- qwssignalhandler.cpp.orig	Sun Jan 14 15:53:45 2007
+++ qwssignalhandler.cpp	Sun Jan 14 15:53:52 2007
@@ -27,13 +27,6 @@
 #include <sys/ipc.h>
 #include <sys/sem.h>
 
-union semun {
-    int val;
-    struct semid_ds *buf;
-    unsigned short *array;
-    struct seminfo  *__buf;
-};
-
 QWSSignalHandler::QWSSignalHandler()
 {
     const int signums[] = { SIGHUP, SIGINT, SIGQUIT, SIGILL, SIGABRT, SIGFPE,
