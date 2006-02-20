--- coregrind/vg_syscalls.c.orig	Fri Jul 16 10:22:32 2004
+++ coregrind/vg_syscalls.c	Sun Jan  1 15:07:25 2006
@@ -1284,6 +1284,38 @@
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
@@ -1307,6 +1339,14 @@
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
@@ -1489,6 +1529,21 @@
    VG_TRACK( post_mem_write, arg1, arg2 );
 }
 
+#if __FreeBSD__ >= 5
+PRE(uuidgen)
+{
+   /* int uuidgen(struct uuid *store, int count); */
+   MAYBE_PRINTF("uuidgen ( %p, %d )\n", arg1, arg2);
+   SYSCALL_TRACK( pre_mem_write, tid, "uuidgen(store, count)", arg1, arg2);
+}
+
+POST(uuidgen)
+{
+   VG_TRACK( post_mem_write, arg1, arg2 );
+}
+
+#endif
+
 #endif
 
 PRE(setresgid)
@@ -3249,8 +3304,7 @@
 		     arg3, sizeof(struct shmid_ds) );
       break;
    case IPC_SET:
-   case IPC_RMID:
-      SYSCALL_TRACK( pre_mem_read, tid, "shmctl(IPC_SET or IPC_RMID,buf)",
+      SYSCALL_TRACK( pre_mem_read, tid, "shmctl(IPC_SET,buf)",
 		     arg3, sizeof(struct shmid_ds) );
       break;
    }
@@ -6498,6 +6552,9 @@
    SYSBA(kldstat,		False),
    SYSB_(kldfirstmod,		False),
    SYSBA(__getcwd,		False),
+#if __FreeBSD__ >= 5
+   SYSBA(uuidgen,		False),
+#endif
 };
 #define MAX_SYS_INFO		(sizeof(sys_info)/sizeof(sys_info[0]))
 
