--- utils/start-stop-daemon.c.orig	2013-03-08 17:45:46.000000000 +0100
+++ utils/start-stop-daemon.c	2013-05-08 20:44:18.000000000 +0200
@@ -55,6 +55,7 @@
 #endif
 
 #if defined(OSOpenBSD) || defined(OSFreeBSD) || defined(OSNetBSD)
+#define _WANT_UCRED
 #include <sys/param.h>
 #include <sys/proc.h>
 
@@ -1164,8 +1165,8 @@
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
@@ -1253,7 +1254,7 @@
 	kp = kvm_getprocs(kd, KERN_PROC_PID, pid, &nentries);
 	if (kp == NULL)
 		errx(1, "%s", kvm_geterr(kd));
-	process_name = (&kp->kp_proc)->p_comm;
+	process_name = kp->ki_paddr->p_comm;
 	if (strlen(name) != strlen(process_name))
 		return false;
 	return (strcmp(name, process_name) == 0);
