--- src/pcm/pcm_direct.c~
+++ src/pcm/pcm_direct.c
@@ -44,12 +44,16 @@
  *
  */
  
+#if defined(__NetBSD__)
+typedef __semun semun;
+#elif !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__OpenBSD__)
 union semun {
 	int              val;    /* Value for SETVAL */
 	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
 	unsigned short  *array;  /* Array for GETALL, SETALL */
 	struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
 };
+#endif
  
 /*
  * FIXME:
