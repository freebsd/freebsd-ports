--- shmap/shmap_internals.h.orig	Thu Jul 11 13:16:52 2002
+++ shmap/shmap_internals.h	Thu Jul 11 13:17:13 2002
@@ -85,12 +85,14 @@
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
 
 /**
  *  Module pointer definitions
