--- utils/start-stop-daemon.c.orig	Mon May 14 07:01:28 2001
+++ utils/start-stop-daemon.c	Fri Apr  4 21:02:53 2003
@@ -30,6 +30,8 @@
 #  define OSsunos
 #elif defined(OPENBSD)
 #  define OSOpenBSD
+#elif defined(__FreeBSD__)
+#  define OSFreeBSD
 #else
 #  error Unknown architecture - cannot build start-stop-daemon
 #endif
@@ -41,7 +43,8 @@
 #  include <ps.h>
 #endif
 
-#if defined(OSOpenBSD)
+#if defined(OSOpenBSD) || defined(OSFreeBSD)
+#define _WANT_UCRED
 #include <sys/param.h>
 #include <sys/user.h>
 #include <sys/proc.h>
@@ -744,7 +747,7 @@
 #endif /* OSHURD */
 
 
-#if defined(OSOpenBSD)
+#if defined(OSOpenBSD) || defined(OSFreeBSD)
 int
 pid_is_cmd(pid_t pid, const char *name)
 {
@@ -787,7 +790,7 @@
 }
  
 int
-pid_is_user(pid_t pid, int uid)
+pid_is_user(pid_t pid, uid_t uid)
 {
 	kvm_t *kd;
 	int nentries;   /* Value not used */
@@ -801,9 +804,15 @@
 		errx(1, "%s", errbuf);
 	if ((kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries)) == 0)
 		errx(1, "%s", kvm_geterr(kd));
+#if defined(OSOpenBSD) || (defined(OSFreeBSD) && __FreeBSD_version < 500014)
 	if ( kp->kp_proc.p_cred )
 		kvm_read(kd, (u_long)&(kp->kp_proc.p_cred->p_ruid),
 			&proc_uid, sizeof(uid_t));
+#elif defined(OSFreeBSD)
+	if ( kp->ki_paddr->p_ucred )
+		kvm_read(kd, (u_long)&(kp->ki_paddr->p_ucred->cr_ruid),
+			&proc_uid, sizeof(uid_t));
+#endif
 	else
 		return 0;
 	return (proc_uid == (uid_t)uid);
@@ -822,7 +831,11 @@
 		errx(1, "%s", errbuf);
 	if ((kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries)) == 0)
 		errx(1, "%s", kvm_geterr(kd));
+#if defined(OSOpenBSD) || (defined(OSFreeBSD) && __FreeBSD_version < 500014)
 	pidexec = (&kp->kp_proc)->p_comm;
+#elif defined(OSFreeBSD)
+	pidexec = kp->ki_paddr->p_comm;
+#endif
 	if (strlen(name) != strlen(pidexec))
 		return 0;
 	return (strcmp(name, pidexec) == 0) ? 1 : 0;
@@ -835,7 +848,7 @@
 	/* Nothing to do */
 }
 
-#endif /* OSOpenBSD */
+#endif /* OSOpenBSD || OSFreeBSD */
 
 
 static void
