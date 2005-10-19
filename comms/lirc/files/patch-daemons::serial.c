--- daemons/serial.c.orig	Mon Mar  7 20:03:48 2005
+++ daemons/serial.c	Sun Aug 21 21:44:26 2005
@@ -29,6 +29,10 @@
 
 #include "lircd.h"
 
+#define LOCKDIR "/var/spool/lock"
+
+static char *lockpath = NULL;
+
 int tty_reset(int fd)
 {
 	struct termios options;
@@ -183,7 +187,7 @@
 	int lock;
 	int len;
 	
-	strcpy(filename,"/var/lock/LCK..");
+	strcpy(filename,LOCKDIR "/LCK..");
 	
 	last=strrchr(name,'/');
 	if(last!=NULL)
@@ -373,63 +377,22 @@
 			}
 		}
 	}
+	lockpath = strdup(filename);
 	return(1);
 }
 
 int tty_delete_lock(void)
 {
-	DIR *dp;
-	struct dirent *ep;
-	int lock;
-	int len;
-	char id[20+1],*endptr;
-	char filename[FILENAME_MAX+1];
-	long pid;
-	int retval=1;
-	
-	dp=opendir("/var/lock/");
-	if(dp!=NULL)
-	{
-		while((ep=readdir(dp)))
-		{
-			strcpy(filename,"/var/lock/");
-			if(strlen(filename)+strlen(ep->d_name)>FILENAME_MAX) 
-			{retval=0;continue;}
-			strcat(filename,ep->d_name);
-			lock=open(filename,O_RDONLY);
-			if(lock==-1) {retval=0;continue;}
-			len=read(lock,id,20);
-			close(lock);
-			if(len<=0) {retval=0;continue;}
-			id[len]=0;
-			pid=strtol(id,&endptr,10);
-			if(!*id || *endptr!='\n')
-			{
-				logprintf(LOG_WARNING,"invalid lockfile (%s) "
-					  "detected",filename);
-				retval=0;
-				continue;
-			}
-			if(pid==getpid())
-			{
-				if(unlink(filename)==-1)
-				{
-					logprintf(LOG_ERR,"could not delete "
-						  "file \"%s\"",filename);
-					logperror(LOG_ERR,NULL);
-					retval=0;
-					continue;
-				}
-			}
-		}
-		closedir(dp);
-	}
-	else
+	if(unlink(lockpath)==-1)
 	{
-		logprintf(LOG_ERR,"could not open directory \"/var/lock/\"");
+		logprintf(LOG_ERR,"could not delete "
+					 "file \"%s\"",lockpath);
+		logperror(LOG_ERR,NULL);
+		free(lockpath);
 		return(0);
 	}
-	return(retval);
+	free(lockpath);
+	return(1);
 }
 
 int tty_set(int fd,int rts,int dtr)
