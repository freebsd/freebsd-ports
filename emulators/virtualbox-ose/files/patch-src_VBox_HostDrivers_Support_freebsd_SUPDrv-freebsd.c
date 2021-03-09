--- src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c.orig	2021-01-07 15:41:26 UTC
+++ src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c
@@ -44,8 +44,10 @@
 #include <sys/fcntl.h>
 #include <sys/conf.h>
 #include <sys/uio.h>
+#include <sys/mutex.h>
 
 #include "../SUPDrvInternal.h"
+#include "freebsd/the-freebsd-kernel.h"
 #include <VBox/version.h>
 #include <iprt/initterm.h>
 #include <iprt/string.h>
@@ -57,7 +59,14 @@
 #include <iprt/alloc.h>
 #include <iprt/err.h>
 #include <iprt/asm.h>
+#include <iprt/x86.h>
 
+#ifdef VBOX_WITH_EFLAGS_AC_SET_IN_VBOXDRV
+# include <machine/cpufunc.h>
+# include <machine/md_var.h>
+# include <machine/specialreg.h>
+#endif
+
 #ifdef VBOX_WITH_HARDENING
 # define VBOXDRV_PERM 0600
 #else
@@ -76,7 +85,9 @@ static d_open_t     VBoxDrvFreeBSDOpenUsr;
 static d_open_t     VBoxDrvFreeBSDOpenSys;
 static void         vboxdrvFreeBSDDtr(void *pvData);
 static d_ioctl_t    VBoxDrvFreeBSDIOCtl;
+static d_ioctl_t    VBoxDrvFreeBSDIOCtlSMAP;
 static int          VBoxDrvFreeBSDIOCtlSlow(PSUPDRVSESSION pSession, u_long ulCmd, caddr_t pvData, struct thread *pTd);
+static bool         VBoxDrvFreeBSDCpuHasSMAP(void);
 
 
 /*********************************************************************************************************************************
@@ -182,6 +193,13 @@ static int VBoxDrvFreeBSDLoad(void)
         rc = supdrvInitDevExt(&g_VBoxDrvFreeBSDDevExt, sizeof(SUPDRVSESSION));
         if (RT_SUCCESS(rc))
         {
+            if (VBoxDrvFreeBSDCpuHasSMAP())
+            {
+                LogRel(("disabling SMAP for VBoxDrvFreeBSDIOCtl\n"));
+                g_VBoxDrvFreeBSDChrDevSwSys.d_ioctl = VBoxDrvFreeBSDIOCtlSMAP;
+                g_VBoxDrvFreeBSDChrDevSwUsr.d_ioctl = VBoxDrvFreeBSDIOCtlSMAP;
+            }
+
             /*
              * Configure character devices. Add symbolic links for compatibility.
              */
@@ -324,6 +342,45 @@ static int VBoxDrvFreeBSDIOCtl(struct cdev *pDev, u_lo
 
 
 /**
+ * Alternative Device I/O Control entry point on hosts with SMAP support.
+ *
+ * @returns depends...
+ * @param   pDev        The device.
+ * @param   ulCmd       The command.
+ * @param   pvData      Pointer to the data.
+ * @param   fFile       The file descriptor flags.
+ * @param   pTd         The calling thread.
+ */
+static int VBoxDrvFreeBSDIOCtlSMAP(struct cdev *pDev, u_long ulCmd, caddr_t pvData, int fFile, struct thread *pTd)
+{
+    /*
+     * Allow VBox R0 code to touch R3 memory. Setting the AC bit disables the
+     * SMAP check.
+     */
+    RTCCUINTREG fSavedEfl = ASMAddFlags(X86_EFL_AC);
+
+    int rc = VBoxDrvFreeBSDIOCtl(pDev, ulCmd, pvData, fFile, pTd);
+
+#ifdef VBOX_WITH_EFLAGS_AC_SET_IN_VBOXDRV
+    /*
+     * Before we restore AC and the rest of EFLAGS, check if the IOCtl handler code
+     * accidentially modified it or some other important flag.
+     */
+    if (RT_UNLIKELY(   (ASMGetFlags() & (X86_EFL_AC | X86_EFL_IF | X86_EFL_DF | X86_EFL_IOPL))
+                    != ((fSavedEfl    & (X86_EFL_AC | X86_EFL_IF | X86_EFL_DF | X86_EFL_IOPL)) | X86_EFL_AC) ))
+    {
+        char szTmp[48];
+        RTStrPrintf(szTmp, sizeof(szTmp), "ulCmd=%#x: %#x->%#x!", ulCmd, (uint32_t)fSavedEfl, (uint32_t)ASMGetFlags());
+        supdrvBadContext(&g_VBoxDrvFreeBSDDevExt, "SUPDrv-freebsd.c",  __LINE__, szTmp);
+    }
+#endif
+
+    ASMSetFlags(fSavedEfl);
+    return rc;
+}
+
+
+/**
  * Deal with the 'slow' I/O control requests.
  *
  * @returns 0 on success, appropriate errno on failure.
@@ -372,11 +429,10 @@ static int VBoxDrvFreeBSDIOCtlSlow(PSUPDRVSESSION pSes
          */
         SUPREQHDR Hdr;
         pvUser = *(void **)pvData;
-        int rc = copyin(pvUser, &Hdr, sizeof(Hdr));
-        if (RT_UNLIKELY(rc))
+        if (RT_FAILURE(RTR0MemUserCopyFrom(&Hdr, pvUser, sizeof(Hdr))))
         {
-            OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyin(%p,Hdr,) -> %#x; ulCmd=%#lx\n", pvUser, rc, ulCmd));
-            return rc;
+            OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyin(%p,Hdr,); ulCmd=%#lx\n", pvUser, ulCmd));
+            return EFAULT;
         }
         if (RT_UNLIKELY((Hdr.fFlags & SUPREQHDR_FLAGS_MAGIC_MASK) != SUPREQHDR_FLAGS_MAGIC))
         {
@@ -401,13 +457,12 @@ static int VBoxDrvFreeBSDIOCtlSlow(PSUPDRVSESSION pSes
             OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: failed to allocate buffer of %d bytes; ulCmd=%#lx\n", cbReq, ulCmd));
             return ENOMEM;
         }
-        rc = copyin(pvUser, pHdr, Hdr.cbIn);
-        if (RT_UNLIKELY(rc))
+        if (RT_FAILURE(RTR0MemUserCopyFrom(pHdr, pvUser, Hdr.cbIn)))
         {
-            OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyin(%p,%p,%#x) -> %#x; ulCmd=%#lx\n",
-                        pvUser, pHdr, Hdr.cbIn, rc, ulCmd));
+            OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyin(%p,%p,%#x); ulCmd=%#lx\n",
+                        pvUser, pHdr, Hdr.cbIn, ulCmd));
             RTMemTmpFree(pHdr);
-            return rc;
+            return EFAULT;
         }
         if (Hdr.cbIn < cbReq)
             RT_BZERO((uint8_t *)pHdr + Hdr.cbIn, cbReq - Hdr.cbIn);
@@ -435,9 +490,8 @@ static int VBoxDrvFreeBSDIOCtlSlow(PSUPDRVSESSION pSes
                 OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: too much output! %#x > %#x; uCmd=%#lx!\n", cbOut, cbReq, ulCmd));
                 cbOut = cbReq;
             }
-            rc = copyout(pHdr, pvUser, cbOut);
-            if (RT_UNLIKELY(rc))
-                OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyout(%p,%p,%#x) -> %d; uCmd=%#lx!\n", pHdr, pvUser, cbOut, rc, ulCmd));
+            if (RT_FAILURE(RTR0MemUserCopyTo(pvUser, pHdr, cbOut)))
+                OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyout(%p,%p,%#x); uCmd=%#lx!\n", pHdr, pvUser, cbOut, ulCmd));
 
             Log(("VBoxDrvFreeBSDIOCtlSlow: returns %d / %d ulCmd=%lx\n", 0, pHdr->rc, ulCmd));
 
@@ -540,8 +594,7 @@ bool VBOXCALL  supdrvOSGetForcedAsyncTscMode(PSUPDRVDE
 
 bool VBOXCALL  supdrvOSAreCpusOfflinedOnSuspend(void)
 {
-    /** @todo verify this. */
-    return false;
+    return true;
 }
 
 
@@ -624,11 +677,25 @@ int VBOXCALL    supdrvOSMsrProberModify(RTCPUID idCpu,
 #endif /* SUPDRV_WITH_MSR_PROBER */
 
 
+/**
+ * Check if the CPU has SMAP support.
+ */
+static bool VBoxDrvFreeBSDCpuHasSMAP(void)
+{
+#ifdef VBOX_WITH_EFLAGS_AC_SET_IN_VBOXDRV
+    if ((cpu_stdext_feature & CPUID_STDEXT_SMAP) != 0)
+        return true;
+#endif
+    return false;
+}
+
+
 SUPR0DECL(int) SUPR0Printf(const char *pszFormat, ...)
 {
     va_list va;
     char szMsg[256];
     int cch;
+    IPRT_FREEBSD_SAVE_EFL_AC();
 
     va_start(va, pszFormat);
     cch = RTStrPrintfV(szMsg, sizeof(szMsg), pszFormat, va);
@@ -636,12 +703,19 @@ SUPR0DECL(int) SUPR0Printf(const char *pszFormat, ...)
 
     printf("%s", szMsg);
 
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return cch;
 }
 
 
 SUPR0DECL(uint32_t) SUPR0GetKernelFeatures(void)
 {
-    return 0;
+    uint32_t fFlags = 0;
+#ifdef VBOX_WITH_EFLAGS_AC_SET_IN_VBOXDRV
+    if (g_VBoxDrvFreeBSDChrDevSwSys.d_ioctl == VBoxDrvFreeBSDIOCtlSMAP)
+        fFlags |= SUPKERNELFEATURES_SMAP;
+    else
+        Assert(!(ASMGetCR4() & X86_CR4_SMAP));
+#endif
+    return fFlags;
 }
-
