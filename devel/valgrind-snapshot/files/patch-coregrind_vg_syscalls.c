--- coregrind/vg_syscalls.c.orig	Fri Jul 16 19:21:08 2004
+++ coregrind/vg_syscalls.c	Wed Sep 14 22:13:44 2005
@@ -1369,6 +1369,38 @@
 					 &tst->m_eflags,
 					 arg1, arg2);
 	break;
+    case 7:
+	SYSCALL_TRACK( pre_mem_write, tid,
+		       "sysarch.get_fsbase(args)", arg2, sizeof(UInt));
+	tst->m_eax = VG_(do_syscall_err)(__NR_sysarch,
+					 tst->m_edx,
+					 &tst->m_eflags,
+					 arg1, arg2);
+	break;
+    case 8:
+	SYSCALL_TRACK( pre_mem_read, tid,
+		       "sysarch.set_fsbase(args)", arg2, sizeof(UInt));
+	tst->m_eax = VG_(do_syscall_err)(__NR_sysarch,
+					 tst->m_edx,
+					 &tst->m_eflags,
+					 arg1, arg2);
+	break;
+    case 9:
+	SYSCALL_TRACK( pre_mem_read, tid,
+		       "sysarch.get_gsbase(args)", arg2, sizeof(UInt));
+	tst->m_eax = VG_(do_syscall_err)(__NR_sysarch,
+					 tst->m_edx,
+					 &tst->m_eflags,
+					 arg1, arg2);
+	break;
+    case 10:
+	SYSCALL_TRACK( pre_mem_read, tid,
+		       "sysarch.set_gsbase(args)", arg2, sizeof(UInt));
+	tst->m_eax = VG_(do_syscall_err)(__NR_sysarch,
+					 tst->m_edx,
+					 &tst->m_eflags,
+					 arg1, arg2);
+	break;
     default:
 	VG_(core_panic)("Unhandled sysarch call");
     }
@@ -1392,6 +1424,14 @@
 	break;
     case 6:			/* vm86 */
 	break;
+    case 7:			/* get_fsbase */
+   	break;
+    case 8:			/* set_fsbase */
+   	break;
+    case 9:			/* get_gsbase */
+   	break;
+    case 10:		/* set_gsbase */
+   	break;
     default:
 	VG_(core_panic)("Unhandled sysarch call");
     }
