--- shmap/core.h.orig	Wed Mar  6 01:38:37 2002
+++ shmap/core.h	Wed Mar  6 01:38:47 2002
@@ -53,12 +53,14 @@
 #define CORE_LOCK(l,m)          if ( l != NULL ) _core_lock(l,SHMAP_LOCK_WRITE);
 #define CORE_UNLOCK(l)          if ( l != NULL ) _core_unlock(l);
 
+#if 0
 union semun {
         int val;                    /* value for SETVAL */
         struct semid_ds *buf;       /* buffer for IPC_STAT, IPC_SET */
         unsigned short int *array;  /* array for GETALL, SETALL */
         struct seminfo *__buf;
 };
+#endif
 
 
 #endif
