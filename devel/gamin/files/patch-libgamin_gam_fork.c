--- libgamin/gam_fork.c.orig	2007-07-04 06:36:48.000000000 -0700
+++ libgamin/gam_fork.c	2013-02-16 20:37:31.298176973 -0800
@@ -42,6 +42,78 @@
     return NULL;
 }
 
+#ifdef RUN_AS_EUID
+/**
+ * gamin_drop_privileges
+ *
+ * Attempt to drop privileges to another user and group before forking
+ * a copy of the gam server
+ * 
+ * Return 0 in case of success or -1 in case of detected error.
+ */
+int
+gamin_drop_privileges(int to_uid, int to_gid)
+{
+    GAM_DEBUG(DEBUG_INFO, "Dropping privileges to %d:%d before forking server\n", to_uid, to_gid);
+
+    /* Get the current real user and group */
+    int from_uid = getuid();
+    int from_gid = getgid();
+
+    /* Make sure we were able to get the user and group values */
+    if ( from_uid == -1 || to_uid == -1 || from_gid == -1 || to_gid == -1 ) {
+        gam_error(DEBUG_INFO, "failed to get user or group info, unable to drop privileges\n");
+        return(-1);
+    }
+
+    /* Refuse to run setuid if it would escalate privileges */
+    if ( from_uid != 0 && to_uid == 0 )
+    {
+        gam_error(DEBUG_INFO, "refusing to escalate user privileges from=%d to=%d\n", from_uid, to_uid);
+        return(-1);
+    }
+
+    /* Refuse to run setgid if it would escalate privileges */
+    if ( from_gid != 0 && to_gid == 0 )
+    {
+        gam_error(DEBUG_INFO, "refusing to escalate group privileges from=%d to=%d\n", from_gid, to_gid);
+        return(-1);
+    }
+
+    /* Run setuid to drop privileges to the effective user */
+    if ( from_uid != to_uid ) {
+        GAM_DEBUG(DEBUG_INFO, "Attempting setuid from=%d to=%d\n", from_uid, to_uid);
+
+        /* run setuid and check for errors */
+        if (setuid(to_uid) == -1) {
+            gam_error(DEBUG_INFO, "failed to run setuid from=%d to=%d\n", from_uid, to_uid);
+            return(-1);
+        }
+    }
+    else {
+        GAM_DEBUG(DEBUG_INFO, "Already running as effective user, skipping setuid\n");
+    }
+
+    /* Run setgid to drop privileges to the effective group */
+    if ( from_gid != to_gid ) {
+        GAM_DEBUG(DEBUG_INFO, "Attempting setgid from=%d to=%d\n", from_gid, to_gid);
+
+        /* run setuid and check for errors */
+        if (setgid(to_gid) == -1) {
+            gam_error(DEBUG_INFO, "failed to run setgid from=%d to=%d\n", from_gid, to_gid);
+            return(-1);
+        }
+    }
+    else {
+        GAM_DEBUG(DEBUG_INFO, "Already running as effective group, skipping setgid\n");
+    }
+
+    GAM_DEBUG(DEBUG_INFO, "Succeeded in dropping privileges from %d:%d to %d:%d\n", from_uid, from_gid, to_uid, to_gid);
+
+    return(0);
+}
+#endif
+
 /**
  * gamin_fork_server:
  * @fam_client_id: the client ID string to use
@@ -71,6 +143,13 @@
         long open_max;
 	long i;
 
+#ifdef RUN_AS_EUID
+        /* Drop privileges to the current effective uid/gid and return on failure */
+        if(gamin_drop_privileges( geteuid(), getegid() ) == -1) {
+            return(-1);
+        }
+#endif
+
         /* don't hold open fd opened from the client of the library */
 	open_max = sysconf (_SC_OPEN_MAX);
 	for (i = 0; i < open_max; i++)
