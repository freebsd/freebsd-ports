--- sync.cpp.orig	Fri Mar  2 17:01:17 2001
+++ sync.cpp	Fri Mar  2 17:03:08 2001
@@ -160,11 +160,11 @@
 #if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED) 
 /* union semun is defined by including <sys/sem.h> */  
 #else
-union semun {
+/*union semun {
     int val;
     struct semid_ds* buf;
     unsigned short* array;
-};
+};*/
 #endif
 static union semun u;
 
