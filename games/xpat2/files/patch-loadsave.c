--- loadsave.c.orig
+++ loadsave.c
@@ -42,13 +42,18 @@
 #ifdef _POSIX_SAVED_IDS
     static int uid_state = -1; /* -1 = unknown, 1 = real, 0 = effective */
     static uid_t real_uid, effective_uid;
+    static gid_t real_gid, effective_gid;
     if (uid_state < 0) {
 	real_uid = getuid();
+	real_gid = getgid();
 	effective_uid = geteuid();
+	effective_gid = getegid();
 	uid_state = 0;
     }
-    if (to_real != uid_state && real_uid != effective_uid) {
+    if (to_real != uid_state && (real_uid != effective_uid || real_gid !=
+	    effective_gid)) {
 	setuid(to_real ? real_uid : effective_uid);
+	setgid(to_real ? real_gid : effective_gid);
 	uid_state = to_real;
     }
 #endif
