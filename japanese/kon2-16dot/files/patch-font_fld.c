 --- font/fld.c	30 Sep 2008 08:02:59 -0000	1.1.1.1
 +++ font/fld.c	23 Oct 2008 09:24:33 -0000
 @@ -52,36 +52,13 @@
      {NULL, NULL}
  };
  
 -void UnloadShmem(char fnum)
 -{
 -    key_t shmkey;
 -    int	shmid;
 -    struct shmid_ds shmseg;
 -
 -#if defined(linux)
 -    shmkey = ftok(CONFIG_NAME, fnum);
 -#elif defined(__FreeBSD__)
 -    shmkey = 5000 + (fnum & 0x7F);
 -#endif
 -    if ((shmid = shmget(shmkey, sizeof(struct fontInfo), 0444)) < 0)
 -	return;
 -    shmctl(shmid, IPC_STAT, &shmseg);
 -    if (shmseg.shm_nattch < 1) {
 -	shmctl(shmid, IPC_RMID, 0);
 -    }
 -}
 -
  int CheckLoadedFont(char fnum)
  {
      key_t shmkey;
      extern int forceLoad;
  
      if (forceLoad) return(EOF);
 -#if defined(linux)
 -    shmkey = ftok(SHMEM_NAME, fnum);
 -#elif defined(__FreeBSD__)
 -    shmkey = 5000 + (fnum & 0x7F);
 -#endif
 +    shmkey = ftok(CONFIG_NAME, fnum);
      if (shmget(shmkey, 1, 0444) == EOF) return(EOF);
      return(0);
  }
 @@ -93,11 +70,7 @@
      int	shmid;
      u_char *shmbuff;
  
 -#if defined(linux)
 -    shmkey = ftok(SHMEM_NAME, fi->type);
 -#elif defined(__FreeBSD__)
 -    shmkey = 5000 + (fi->type & 0x0000007F);
 -#endif
 +    shmkey = ftok(CONFIG_NAME, fi->type);
      shmid = shmget(shmkey, fi->size+sizeof(struct fontInfo),
  		   IPC_CREAT|0666);
      shmbuff = shmat(shmid, 0, 0);
 @@ -134,11 +107,7 @@
      int shmid;
      struct fontInfo *fi;
  
 -#if defined(linux)
      shmkey = ftok(CONFIG_NAME, fnum);
 -#elif defined(__FreeBSD__)
 -    shmkey = 5000 + (fnum & 0x7F);
 -#endif
      if ((shmid = shmget(shmkey, sizeof(struct fontInfo), 0444)) < 0)
  	return(0);
      fi = (struct fontInfo*)shmat(shmid, 0, SHM_RDONLY);
 @@ -194,7 +163,7 @@
  			(n & CHR_DBC) ?
  			fDRegs[n&~CHR_DFLD].registry:
  			fSRegs[n&~CHR_SFLD].registry);
 -		UnloadShmem(n | CHR_SFLD);
 +		DownShmem(n | CHR_SFLD);
  		break;
  	    }
  	    st = ST_ARG;
