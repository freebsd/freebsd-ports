--- bforce/daemon.c.old	Tue Jun  1 16:14:31 2004
+++ bforce/daemon.c	Tue Jun  1 16:20:15 2004
@@ -772,10 +772,13 @@
 				fclose(pf);
 
 				if (hispid != 0) {
+					if (hispid == mypid)
+						return 0;
 					if (kill(hispid, 0) == 0) {
 						log("daemon_pidfile: another daemon exist. pid=%d", hispid);
 						return (-1);
-					} else if(errno != ESRCH) {
+					}
+					if (errno != ESRCH) {
 						log("daemon_pidfile: error sending signal. pid=%d, errno=%d", hispid, errno);
 						return (-1);
 					}	
