--- dlist.cc.orig	Wed Mar 14 10:52:01 2001
+++ dlist.cc	Wed Mar 14 16:47:21 2001
@@ -62,7 +62,7 @@
 	a.l_type=F_WRLCK;
 	a.l_whence=SEEK_SET;
 	a.l_start=0;
-	a.l_len=1;
+	a.l_len=0;
 	if (fcntl(fd,F_SETLK,&a)==-1)
 		return(-1);
 	return(0);
@@ -73,7 +73,7 @@
 	a.l_type=F_UNLCK;
 	a.l_whence=SEEK_SET;
 	a.l_start=0;
-	a.l_len=1;
+	a.l_len=0;
 	fcntl(fd,F_SETLK,&a);
 };
 
@@ -360,11 +360,17 @@
 	im_first=0;
 	if (segments==NULL){
 		/*trying to lock*/
-		if (d4x_f_lock(fdesc)){
-			WL->log(LOG_ERROR,_("File is already opened by another download!"));
-			close(fdesc);
-			return(-1);
-		};
+		if(d4x_f_lock(fdesc))
+			switch(errno) {
+		 		case EINVAL:
+					WL->log(LOG_WARNING,_("Filesystem seems not to support advisory record locking!"));
+					WL->log(LOG_WARNING,_("Will proceed without it but beware that you might have problems."));
+					break;
+				default:
+					WL->log(LOG_ERROR,_("File is already opened by another download!"));
+					close(fdesc);
+					return(-1);
+			};
 		/*end of trying */
 		segments=new tSegmentator;
 		char *segname=sum_strings(name,".segments",NULL);
