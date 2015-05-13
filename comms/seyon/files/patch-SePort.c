--- SePort.c.orig	2015-05-08 01:08:39 UTC
+++ SePort.c
@@ -1022,6 +1022,7 @@ lock_tty()
   pid_t           pid,
                   lckpid;
   char           *modemname;
+  int		  killret;
 #if LF_USE_ASCII_PID
   char            pidstr[20],
                   lckpidstr[20];
@@ -1088,11 +1089,13 @@ relink:
 #endif
 
       lockPid = (pid_t) lckpid;
-      if (kill(lckpid, 0) == 0 || errno != ESRCH) {
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
 
