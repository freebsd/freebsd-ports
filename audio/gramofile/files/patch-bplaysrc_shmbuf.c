--- bplaysrc/shmbuf.c.orig	2000-03-27 21:38:56 UTC
+++ bplaysrc/shmbuf.c
@@ -142,6 +142,7 @@ void init_shm(void)
     if(shmctl(shmid2, IPC_RMID, NULL))
 	ErrDie("shmctl");
 
+#ifndef __DragonFly__
 #if USEBUFFLOCK
 	/* Ok, go root to lock the buffers down */
     if(setreuid(geteuid(), getuid()) == -1)
@@ -173,6 +174,7 @@ void init_shm(void)
     }
 
 #endif
+#endif
     /* Set up the appropriate number of semaphore blocks */
     numsemblks = numbuffs/SEMMSL;
     if((numsemblks * SEMMSL) < numbuffs)
