--- SePort.c.orig	Thu Apr  4 11:44:26 1996
+++ SePort.c	Thu Apr  4 11:51:54 1996
@@ -1011,6 +1011,7 @@
   pid_t           pid,
                   lckpid;
   char           *modemname;
+  int		  killret;
 #if LF_USE_ASCII_PID
   char            pidstr[20],
                   lckpidstr[20];
@@ -1077,11 +1078,13 @@
 #endif
 
       lockPid = (pid_t) lckpid;
-      if (kill(lckpid, 0) == 0) {
-		SeErrorF("Device %s is locked by process %d", modem_port, lckpid, "");
-		unlink(ltmp);
-		return -1;
-      }
+      killret = kill(lockPid, 0);
+        if(killret == 0 || (killret == -1 && errno != ESRCH)) {
+	  SeErrorF("Device %s is locked by process %d.",
+		   modem_port, lckpid, "");
+	  unlink(ltmp);
+	  return -1;
+	}
     }
   }
 
