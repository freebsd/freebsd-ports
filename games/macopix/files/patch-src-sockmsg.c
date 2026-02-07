--- src/sockmsg.c.orig	2008-05-02 16:05:30.000000000 +0200
+++ src/sockmsg.c	2013-09-13 17:59:53.072457158 +0200
@@ -276,7 +276,7 @@
 
 	fd_close(fd);
 	
-	if(readsize<4) return;
+	if(readsize<4) return(0);
 	
 	strncpy(tmp,buf,2);
 	mode=atoi(tmp);
