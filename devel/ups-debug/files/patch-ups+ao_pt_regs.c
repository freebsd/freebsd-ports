--- ups/ao_pt_regs.c.orig	Wed Oct 23 01:07:46 2002
+++ ups/ao_pt_regs.c	Fri Nov 29 01:01:58 2002
@@ -495,9 +495,13 @@
 	e_ptrace(PTRACE_GETDREGS, ip->ip_pid, (char *)&pr->dbregs, 0);
 
 	/* FreeBSD : .../sys/i386/i386/machdep.c
-	 * dr6 is status register, dr7 is control register.
+	 * dr[6] is status register, dr[7] is control register.
 	 */
+#if (defined __FreeBSD__) && __FreeBSD_version >= 500043
+	return (pr->dbregs.dr[6] & 0x0000000f);
+#else
 	return (pr->dbregs.dr6 & 0x0000000f);
+#endif
 }
 
 /*
