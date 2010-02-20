--- utilities/dumpshm.cpp.orig	2010-02-11 02:20:23.000000000 +0300
+++ utilities/dumpshm.cpp	2010-02-18 22:26:30.000000000 +0300
@@ -316,12 +316,12 @@
         }
 #ifdef IPC_PERM_KEY
         if (shmseg.shm_segsz == 64528) {
-            log_debug(_("Found it! \"set LCShmKey %s\" in your ~/.gnashrc",
+            log_debug(_("Found it! \"set LCShmKey %s\" in your ~/.gnashrc"),
                         boost::io::group(hex, showbase,
-                            shmseg.shm_perm.IPC_PERM_KEY)));
-            log_debug(_("Last changed on: %s", ctime(&shmseg.shm_ctime)));
-            log_debug(_("Last attached on: %s", ctime(&shmseg.shm_atime)));
-            log_debug(_("Last detached on: %s", ctime(&shmseg.shm_dtime)));
+                            shmseg.shm_perm.IPC_PERM_KEY));
+            log_debug(_("Last changed on: %s"), ctime(&shmseg.shm_ctime));
+            log_debug(_("Last attached on: %s"), ctime(&shmseg.shm_atime));
+            log_debug(_("Last detached on: %s"), ctime(&shmseg.shm_dtime));
             return shmseg.shm_perm.IPC_PERM_KEY;
         }
 #endif    // end of IPC_PERM_KEY
