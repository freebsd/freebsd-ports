--- lib/font.c.orig	Sun Apr 14 16:40:36 1996
+++ lib/font.c	Tue Nov 26 11:45:51 2002
@@ -35,6 +35,7 @@
     struct shmid_ds shmseg;
 
     shmkey = ftok(CONFIG_NAME, fnum);
+    shmkey = 5000 + (fnum & 0x7F);
     if ((shmid = shmget(shmkey, sizeof(struct fontInfo), 0444)) < 0)
 	return;
     shmctl(shmid, IPC_STAT, &shmseg);
@@ -50,6 +51,7 @@
     int shmid;
 
     shmkey = ftok(CONFIG_NAME, fnum);
+    shmkey = 5000 + (fnum & 0x7F);
     if ((shmid = shmget(shmkey, sizeof(struct fontInfo), 0444)) < 0) return(0);
     return((u_char*)shmat(shmid, 0, SHM_RDONLY));
 }
