--- utils/start-stop-daemon.c.orig	2009-02-01 14:19:02.000000000 +0800
+++ utils/start-stop-daemon.c	2009-11-12 07:23:18.000000000 +0800
@@ -50,6 +50,7 @@
 #endif
 
 #if defined(OSOpenBSD) || defined(OSFreeBSD) || defined(OSNetBSD)
+#define _WANT_UCRED
 #include <sys/param.h>
 #include <sys/proc.h>
 #include <sys/stat.h>
@@ -941,8 +942,8 @@
 	kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries);
 	if (kp == NULL)
 		errx(1, "%s", kvm_geterr(kd));
-	if (kp->kp_proc.p_cred)
-		kvm_read(kd, (u_long)&(kp->kp_proc.p_cred->p_ruid),
+	if (kp->ki_paddr->p_ucred)
+		kvm_read(kd, (u_long)&(kp->ki_paddr->p_ucred->cr_ruid),
 		         &proc_uid, sizeof(uid_t));
 	else
 		return 0;
@@ -963,7 +964,7 @@
 	kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries);
 	if (kp == NULL)
 		errx(1, "%s", kvm_geterr(kd));
-	pidexec = (&kp->kp_proc)->p_comm;
+	pidexec = kp->ki_paddr->p_comm;
 	if (strlen(name) != strlen(pidexec))
 		return 0;
 	return (strcmp(name, pidexec) == 0) ? 1 : 0;
