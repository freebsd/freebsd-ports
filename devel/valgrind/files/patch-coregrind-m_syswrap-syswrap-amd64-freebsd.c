--- coregrind/m_syswrap/syswrap-amd64-freebsd.c.orig	2015-01-26 16:17:32.000000000 -0400
+++ coregrind/m_syswrap/syswrap-amd64-freebsd.c	2015-08-31 09:51:17.506396000 -0300
@@ -691,6 +691,27 @@
       SET_STATUS_Success2( tst->arch.vex.guest_FS_ZERO, tst->arch.vex.guest_RDX );
       POST_MEM_WRITE( ARG2, sizeof(void *) );
       break;
+   case VKI_AMD64_GET_XFPUSTATE:
+      {
+      	UChar fpuState[160];
+      	struct vki_amd64_get_xfpustate *xfs = (struct vki_amd64_get_xfpustate *)ARG2;
+	int fpuSaveLen;
+      
+      	PRINT("sys_amd64_get_xfpustate ( %#lx, %d )", (long unsigned int)xfs->addr, xfs->len);
+      	tst = VG_(get_ThreadState)(tid);
+
+	if (xfs->len <= sizeof(fpuState)) {
+      		amd64g_dirtyhelper_FXSAVE_ALL_EXCEPT_XMM(
+		    (VexGuestAMD64State *)&tst->arch.vex,
+		    (HWord)fpuState);
+		VG_(memcpy)(xfs->addr, fpuState, xfs->len);
+      		POST_MEM_WRITE( xfs->addr, xfs->len );
+		SET_STATUS_Success ( 0 );
+	} else {
+		SET_STATUS_Failure( VKI_EINVAL );
+	}
+      }
+      break;
    default:
       VG_(message) (Vg_UserMsg, "unhandled sysarch cmd %ld", ARG1);
       VG_(unimplemented) ("unhandled sysarch cmd");
