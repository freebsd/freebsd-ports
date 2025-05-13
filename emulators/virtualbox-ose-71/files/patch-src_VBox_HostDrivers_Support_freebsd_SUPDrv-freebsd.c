--- src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c.orig	2025-01-21 14:06:14 UTC
+++ src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c
@@ -44,9 +44,13 @@
 #include <sys/fcntl.h>
 #include <sys/conf.h>
 #include <sys/uio.h>
+#include <vm/vm.h>
 #include <vm/pmap.h> /* for pmap_map() */
+#include <sys/mutex.h>
+#include <sys/smp.h>				/* mp_maxcpus */
 
 #include "../SUPDrvInternal.h"
+#include "freebsd/the-freebsd-kernel.h"
 #include <VBox/version.h>
 #include <iprt/initterm.h>
 #include <iprt/string.h>
@@ -58,7 +62,15 @@
 #include <iprt/alloc.h>
 #include <iprt/err.h>
 #include <iprt/asm.h>
+#include <iprt/x86.h>
 
+ 
+#ifdef VBOX_WITH_EFLAGS_AC_SET_IN_VBOXDRV
+# include <machine/cpufunc.h>
+# include <machine/md_var.h>
+# include <machine/specialreg.h>
+#endif
+
 #ifdef VBOX_WITH_HARDENING
 # define VBOXDRV_PERM 0600
 #else
@@ -77,7 +89,9 @@ static d_ioctl_t    VBoxDrvFreeBSDIOCtl;
 static d_open_t     VBoxDrvFreeBSDOpenSys;
 static void         vboxdrvFreeBSDDtr(void *pvData);
 static d_ioctl_t    VBoxDrvFreeBSDIOCtl;
+static d_ioctl_t    VBoxDrvFreeBSDIOCtlSMAP;
 static int          VBoxDrvFreeBSDIOCtlSlow(PSUPDRVSESSION pSession, u_long ulCmd, caddr_t pvData, struct thread *pTd);
+static bool         VBoxDrvFreeBSDCpuHasSMAP(void);
 
 
 /*********************************************************************************************************************************
@@ -94,7 +108,8 @@ static moduledata_t         g_VBoxDrvFreeBSDModule =
 };
 
 /** Declare the module as a pseudo device. */
-DECLARE_MODULE(vboxdrv,     g_VBoxDrvFreeBSDModule, SI_SUB_PSEUDO, SI_ORDER_ANY);
+#define	KERNEL_RELBRANCHEND	(roundup(__FreeBSD_version, 500) - 1)
+DECLARE_MODULE_WITH_MAXVER(vboxdrv,     g_VBoxDrvFreeBSDModule, SI_SUB_PSEUDO, SI_ORDER_ANY, KERNEL_RELBRANCHEND);
 MODULE_VERSION(vboxdrv, 1);
 
 /**
@@ -141,6 +156,13 @@ static int VBoxDrvFreeBSDModuleEvent(struct module *pM
 static int VBoxDrvFreeBSDModuleEvent(struct module *pMod, int enmEventType, void *pvArg)
 {
     int rc;
+
+    /* Refuse to load if mp_maxcpus is wrong */
+    if (MAXCPU != mp_maxcpus) {
+	printf("vboxdrv: MAXCPU != mp_maxcpus (%d != %d)\n", MAXCPU, mp_maxcpus);
+	return EINVAL;
+    }
+
     switch (enmEventType)
     {
         case MOD_LOAD:
@@ -183,6 +205,13 @@ static int VBoxDrvFreeBSDLoad(void)
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
@@ -322,7 +351,45 @@ static int VBoxDrvFreeBSDIOCtl(struct cdev *pDev, u_lo
     return VBoxDrvFreeBSDIOCtlSlow(pSession, ulCmd, pvData, pTd);
 }
 
+/**
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
 /**
  * Deal with the 'slow' I/O control requests.
  *
@@ -372,11 +439,10 @@ static int VBoxDrvFreeBSDIOCtlSlow(PSUPDRVSESSION pSes
          */
         SUPREQHDR Hdr;
         pvUser = *(void **)pvData;
-        int rc = copyin(pvUser, &Hdr, sizeof(Hdr));
-        if (RT_UNLIKELY(rc))
+        if (RT_FAILURE(RTR0MemUserCopyFrom(&Hdr, (uintptr_t)pvUser, sizeof(Hdr))))
         {
-            OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyin(%p,Hdr,) -> %#x; ulCmd=%#lx\n", pvUser, rc, ulCmd));
-            return rc;
+            OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyin(%p,Hdr,); ulCmd=%#lx\n", pvUser, ulCmd));
+            return EFAULT;
         }
         if (RT_UNLIKELY((Hdr.fFlags & SUPREQHDR_FLAGS_MAGIC_MASK) != SUPREQHDR_FLAGS_MAGIC))
         {
@@ -401,13 +467,12 @@ static int VBoxDrvFreeBSDIOCtlSlow(PSUPDRVSESSION pSes
             OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: failed to allocate buffer of %d bytes; ulCmd=%#lx\n", cbReq, ulCmd));
             return ENOMEM;
         }
-        rc = copyin(pvUser, pHdr, Hdr.cbIn);
-        if (RT_UNLIKELY(rc))
+        if (RT_FAILURE(RTR0MemUserCopyFrom(pHdr, (uintptr_t)pvUser, Hdr.cbIn)))
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
@@ -435,9 +500,8 @@ static int VBoxDrvFreeBSDIOCtlSlow(PSUPDRVSESSION pSes
                 OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: too much output! %#x > %#x; uCmd=%#lx!\n", cbOut, cbReq, ulCmd));
                 cbOut = cbReq;
             }
-            rc = copyout(pHdr, pvUser, cbOut);
-            if (RT_UNLIKELY(rc))
-                OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyout(%p,%p,%#x) -> %d; uCmd=%#lx!\n", pHdr, pvUser, cbOut, rc, ulCmd));
+            if (RT_FAILURE(RTR0MemUserCopyTo((uintptr_t)pvUser, pHdr, cbOut)))
+                OSDBGPRINT(("VBoxDrvFreeBSDIOCtlSlow: copyout(%p,%p,%#x); uCmd=%#lx!\n", pHdr, pvUser, cbOut, ulCmd));
 
             Log(("VBoxDrvFreeBSDIOCtlSlow: returns %d / %d ulCmd=%lx\n", 0, pHdr->rc, ulCmd));
 
@@ -540,8 +604,7 @@ bool VBOXCALL  supdrvOSAreCpusOfflinedOnSuspend(void)
 
 bool VBOXCALL  supdrvOSAreCpusOfflinedOnSuspend(void)
 {
-    /** @todo verify this. */
-    return false;
+    return true;
 }
 
 
@@ -637,31 +700,44 @@ int VBOXCALL    supdrvOSMsrProberModify(RTCPUID idCpu,
 #endif /* SUPDRV_WITH_MSR_PROBER */
 
 
-#if defined(RT_ARCH_AMD64) || defined(RT_ARCH_ARM64)
-SUPR0DECL(int) SUPR0HCPhysToVirt(RTHCPHYS HCPhys, void **ppv)
+/**
+ * Check if the CPU has SMAP support.
+ */
+static bool VBoxDrvFreeBSDCpuHasSMAP(void)
 {
-    AssertReturn(!(HCPhys & PAGE_OFFSET_MASK), VERR_INVALID_POINTER);
-    AssertReturn(HCPhys != NIL_RTHCPHYS, VERR_INVALID_POINTER);
-    *ppv = (void *)(uintptr_t)pmap_map(NULL, HCPhys, (HCPhys | PAGE_OFFSET_MASK) + 1, VM_PROT_WRITE | VM_PROT_READ);
-    return VINF_SUCCESS;
-}
+#ifdef VBOX_WITH_EFLAGS_AC_SET_IN_VBOXDRV
+    if ((cpu_stdext_feature & CPUID_STDEXT_SMAP) != 0)
+        return true;
 #endif
+    return false;
+}
 
 
 SUPR0DECL(int) SUPR0PrintfV(const char *pszFormat, va_list va)
 {
     char szMsg[256];
+    IPRT_FREEBSD_SAVE_EFL_AC();
+
     RTStrPrintfV(szMsg, sizeof(szMsg), pszFormat, va);
     szMsg[sizeof(szMsg) - 1] = '\0';
 
     printf("%s", szMsg);
+
+    IPRT_FREEBSD_RESTORE_EFL_AC();
     return 0;
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
 
 
