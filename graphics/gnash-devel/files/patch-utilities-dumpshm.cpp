--- utilities/dumpshm.cpp.orig	2010-01-10 20:05:25.000000000 +0300
+++ utilities/dumpshm.cpp	2010-01-11 02:30:47.000000000 +0300
@@ -314,10 +314,10 @@
 	}
 #ifdef IPC_PERM_KEY
 	if (shmseg.shm_segsz == 64528) {
-	    log_debug(_("Found it! \"set LCShmKey 0x %s %s \" in your ~/.gnashrc", hex, shmseg.shm_perm.IPC_PERM_KEY));
-	    log_debug(_("Last changed on: %s", ctime(&shmseg.shm_ctime)));
-	    log_debug(_("Last attached on: %s", ctime(&shmseg.shm_atime)));
-	    log_debug(_("Last detached on: %s", ctime(&shmseg.shm_dtime)));
+	    log_debug("Found it! \"set LCShmKey 0x %s %s \" in your ~/.gnashrc", hex, shmseg.shm_perm.IPC_PERM_KEY);
+	    log_debug("Last changed on: %s", ctime(&shmseg.shm_ctime));
+	    log_debug("Last attached on: %s", ctime(&shmseg.shm_atime));
+	    log_debug("Last detached on: %s", ctime(&shmseg.shm_dtime));
 	    return shmseg.shm_perm.IPC_PERM_KEY;
 	}
 #endif	// end of IPC_PERM_KEY
