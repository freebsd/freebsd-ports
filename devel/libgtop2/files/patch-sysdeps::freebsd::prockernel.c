--- sysdeps/freebsd/prockernel.c.orig	Sun Oct 17 03:31:43 1999
+++ sysdeps/freebsd/prockernel.c	Tue Sep  9 11:36:35 2003
@@ -34,12 +34,6 @@
 #if (!defined __OpenBSD__) && (!defined __bsdi__)
 #include <sys/user.h>
 #endif
-#if !defined(__bsdi__) && !(defined(__FreeBSD__) && defined(__alpha__))
-#include <machine/pcb.h>
-#endif
-#if defined(__FreeBSD__) && !defined(__alpha__)
-#include <machine/tss.h>
-#endif
 
 #include <unistd.h>
 #include <fcntl.h>
@@ -78,14 +72,8 @@
 			   pid_t pid)
 {
 	struct kinfo_proc *pinfo;
-	struct user *u_addr = (struct user *)USRSTACK;
-	struct pstats pstats;
-	struct pcb pcb;
 	int count;
 
-	char filename [BUFSIZ];
-	struct stat statb;
-
 	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_PROC_KERNEL), 0);
 	
 	memset (buf, 0, sizeof (glibtop_proc_kernel));
@@ -98,14 +86,30 @@
 	
 	/* Get the process information */
 	pinfo = kvm_getprocs (server->machine.kd, KERN_PROC_PID, pid, &count);
-	if ((pinfo == NULL) || (count != 1))
-		glibtop_error_io_r (server, "kvm_getprocs (%d)", pid);
+	if ((pinfo == NULL) || (count != 1)) {
+		glibtop_warn_io_r (server, "kvm_getprocs (%d)", pid);
+		return;
+	}
+
+#if __FreeBSD_version >= 500013
+
+#define	XXX_P_WCHAN	ki_wchan
+#define	XXX_P_WMESG	ki_wmesg
+#define	XXX_E_WMESG	ki_wmesg
 
-	buf->nwchan = (unsigned long) pinfo [0].kp_proc.p_wchan &~ KERNBASE;
+#else
+
+#define	XXX_P_WCHAN	kp_proc.p_wchan
+#define	XXX_P_WMESG	kp_proc.p_wmesg
+#define	XXX_E_WMESG	kp_eproc.e_wmesg
+
+#endif
+
+	buf->nwchan = (unsigned long) pinfo [0].XXX_P_WCHAN &~ KERNBASE;
 	buf->flags |= (1L << GLIBTOP_PROC_KERNEL_NWCHAN);
 
-	if (pinfo [0].kp_proc.p_wchan && pinfo [0].kp_proc.p_wmesg) {
-		strncpy (buf->wchan, pinfo [0].kp_eproc.e_wmesg,
+	if (pinfo [0].XXX_P_WCHAN && pinfo [0].XXX_P_WMESG) {
+		strncpy (buf->wchan, pinfo [0].XXX_E_WMESG,
 			 sizeof (buf->wchan) - 1);
 		buf->wchan [sizeof (buf->wchan) - 1] = 0;
 		buf->flags |= (1L << GLIBTOP_PROC_KERNEL_WCHAN);
@@ -113,72 +117,10 @@
 		buf->wchan [0] = 0;
 	}
 
-	/* Taken from `saveuser ()' in `/usr/src/bin/ps/ps.c'. */
-
-	/* [FIXME]: /usr/include/sys/user.h tells me that the user area
-	 *          may or may not be at the same kernel address in all
-	 *          processes, but I don't see any way to get that address.
-	 *          Since `ps' simply uses its own address, I think it's
-	 *          safe to do this here, too. */
-
-	/* NOTE: You need to mount the /proc filesystem to make
-	 *       `kvm_uread' work. */
-
-	sprintf (filename, "/proc/%d/mem", (int) pid);
-	if (stat (filename, &statb)) return;
-
-	glibtop_suid_enter (server);
-
-	if ((pinfo [0].kp_proc.p_flag & P_INMEM) &&
-	    kvm_uread (server->machine.kd, &(pinfo [0]).kp_proc,
-		       (unsigned long) &u_addr->u_stats,
-		       (char *) &pstats, sizeof (pstats)) == sizeof (pstats))
-		{
-			/*
-			 * The u-area might be swapped out, and we can't get
-			 * at it because we have a crashdump and no swap.
-			 * If it's here fill in these fields, otherwise, just
-			 * leave them 0.
-			 */
-
-			buf->min_flt = (u_int64_t) pstats.p_ru.ru_minflt;
-			buf->maj_flt = (u_int64_t) pstats.p_ru.ru_majflt;
-			buf->cmin_flt = (u_int64_t) pstats.p_cru.ru_minflt;
-			buf->cmaj_flt = (u_int64_t) pstats.p_cru.ru_majflt;
-			
-			buf->flags |= _glibtop_sysdeps_proc_kernel_pstats;
-		}
-
-	if ((pinfo [0].kp_proc.p_flag & P_INMEM) &&
-	    kvm_uread (server->machine.kd, &(pinfo [0]).kp_proc,
-		       (unsigned long) &u_addr->u_pcb,
-		       (char *) &pcb, sizeof (pcb)) == sizeof (pcb))
-		{
-#ifdef __FreeBSD__
-#ifndef __alpha__
-#if (__FreeBSD_version >= 300003)
-			buf->kstk_esp = (u_int64_t) pcb.pcb_esp;
-			buf->kstk_eip = (u_int64_t) pcb.pcb_eip;
-#else
-			buf->kstk_esp = (u_int64_t) pcb.pcb_ksp;
-			buf->kstk_eip = (u_int64_t) pcb.pcb_pc;
-#endif
-#else
-			/*xxx FreeBSD/Alpha? */
-#endif
-#else
-			buf->kstk_esp = (u_int64_t) pcb.pcb_tss.tss_esp0;
-#ifdef __bsdi__
-			buf->kstk_eip = (u_int64_t) pcb.pcb_tss.tss_eip;
-#else
-			buf->kstk_eip = (u_int64_t) pcb.pcb_tss.__tss_eip;
-#endif
-
-			buf->flags |= _glibtop_sysdeps_proc_kernel_pcb;
-#endif
-		}
-
-	/* Taken from `wchan ()' in `/usr/src/bin/ps/print.c'. */
-
-	glibtop_suid_leave (server);
+	/* XXX: the code here was, quite frankly, junk, and almost
+	 * certainly wrong - remove it all, leave these fields
+	 * unpopulated, and give up until such time as the right
+	 * code is produced for both FreeBSD 4.x and 5.x
+	 */
+	return;
 }
