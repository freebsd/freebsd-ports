--- qwssignalhandler.cpp.orig	Thu Mar 22 16:17:51 2007
+++ qwssignalhandler.cpp	Thu Mar 22 16:18:10 2007
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
 class QWSSignalHandlerPrivate
 {
 public:
