--- fld/fld.c.orig	Wed May 20 17:49:32 1998
+++ fld/fld.c	Tue Nov 26 11:45:51 2002
@@ -55,7 +55,7 @@
 	int	shmid;
 	struct shmid_ds shmseg;
 
-	shmkey = ftok(CONFIG_NAME, fnum);
+	shmkey = 5000 + (fnum & 0x7F);
 	if ((shmid = shmget(shmkey, sizeof(struct fontInfo), 0444)) < 0)
 	return;
 	shmctl(shmid, IPC_STAT, &shmseg);
@@ -70,7 +70,7 @@
 	extern int forceLoad;
 
 	if (forceLoad) return(EOF);
-	shmkey = ftok(SHMEM_NAME, fnum);
+	shmkey = 5000 + (fnum & 0x7F);
 	if (shmget(shmkey, 1, 0444) == EOF) return(EOF);
 	return(0);
 }
@@ -82,7 +82,7 @@
 	int	shmid;
 	u_char *shmbuff;
 
-	shmkey = ftok(SHMEM_NAME, fi->type);
+	shmkey = 5000 + (fi->type & 0x0000007F);
 	shmid = shmget(shmkey, fi->size+sizeof(struct fontInfo),
 		   IPC_CREAT|0666);
 	fprintf( stderr,"%ld\n",fi->size+sizeof(struct fontInfo) );
@@ -120,7 +120,7 @@
 	int shmid;
 	struct fontInfo *fi;
 
-	shmkey = ftok(CONFIG_NAME, fnum);
+	shmkey = 5000 + (fnum & 0x7F);
 	if ((shmid = shmget(shmkey, sizeof(struct fontInfo), 0444)) < 0)
 	return(0);
 	fi = (struct fontInfo*)shmat(shmid, 0, SHM_RDONLY);
