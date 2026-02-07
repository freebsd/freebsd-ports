--- lib/font.c.orig	1997-01-24 16:08:55.000000000 +0900
+++ lib/font.c	2012-05-10 00:14:28.809804680 +0900
@@ -44,11 +44,7 @@
     int	shmid;
     struct shmid_ds shmseg;
 
-#if defined(linux)
     shmkey = ftok(CONFIG_NAME, fnum);
-#elif defined(__FreeBSD__)
-    shmkey = 5000 + (fnum & 0x7F);
-#endif
     if ((shmid = shmget(shmkey, sizeof(struct fontInfo), 0444)) < 0)
 	return;
     shmctl(shmid, IPC_STAT, &shmseg);
@@ -63,11 +59,7 @@
     key_t shmkey;
     int shmid;
 
-#if defined(linux)
     shmkey = ftok(CONFIG_NAME, fnum);
-#elif defined(__FreeBSD__)
-    shmkey = 5000 + (fnum & 0x7F);
-#endif
     if ((shmid = shmget(shmkey, sizeof(struct fontInfo), 0444)) < 0) return(0);
     return((u_char*)shmat(shmid, 0, SHM_RDONLY));
 }
