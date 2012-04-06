--- utils/start-stop-daemon.c.orig	2011-11-10 07:17:51.000000000 +0100
+++ utils/start-stop-daemon.c	2012-03-16 20:31:14.000000000 +0100
@@ -59,6 +59,7 @@
 #endif
 
 #if defined(OSOpenBSD) || defined(OSFreeBSD) || defined(OSNetBSD)
+#define _WANT_UCRED
 #include <sys/param.h>
 #include <sys/proc.h>
 
@@ -989,7 +990,7 @@
 	kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries);
 	if (kp == NULL)
 		errx(1, "%s", kvm_geterr(kd));
-	pidexec = (&kp->kp_proc)->p_comm;
+	pidexec = kp->ki_paddr->p_comm;
 	if (strlen(name) != strlen(pidexec))
 		return false;
 	return (strcmp(name, pidexec) == 0) ? 1 : 0;
@@ -1043,8 +1044,8 @@
 	kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries);
 	if (kp == NULL)
 		errx(1, "%s", kvm_geterr(kd));
-	if (kp->kp_proc.p_cred)
-		kvm_read(kd, (u_long)&(kp->kp_proc.p_cred->p_ruid),
+	if (kp->ki_paddr->p_ucred)
+		kvm_read(kd, (u_long)&(kp->ki_paddr->p_ucred->cr_ruid),
 		         &proc_uid, sizeof(uid_t));
 	else
 		return false;
