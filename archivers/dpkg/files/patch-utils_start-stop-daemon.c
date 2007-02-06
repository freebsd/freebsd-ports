--- utils/start-stop-daemon.c.orig	Wed Jun 21 07:59:36 2006
+++ utils/start-stop-daemon.c	Thu Oct 26 18:59:40 2006
@@ -48,6 +48,7 @@
 #endif
 
 #if  defined(OSOpenBSD) || defined(OSFreeBSD) || defined(OSNetBSD)
+#define _WANT_UCRED
 #include <sys/param.h>
 #include <sys/proc.h>
 #include <sys/stat.h>
@@ -928,9 +929,15 @@
 		errx(1, "%s", errbuf);
 	if ((kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries)) == 0)
 		errx(1, "%s", kvm_geterr(kd));
+#if defined(OSOpenBSD) || (defined(OSFreeBSD) && __FreeBSD_version < 500014)
 	if (kp->kp_proc.p_cred )
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
@@ -949,7 +956,11 @@
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
