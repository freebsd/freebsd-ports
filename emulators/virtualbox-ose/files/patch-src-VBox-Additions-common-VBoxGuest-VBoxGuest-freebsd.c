--- src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c.orig	2019-01-25 18:12:28 UTC
+++ src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c
@@ -45,6 +45,7 @@
 #include <sys/uio.h>
 #include <sys/bus.h>
 #include <sys/poll.h>
+#include <sys/proc.h>
 #include <sys/selinfo.h>
 #include <sys/queue.h>
 #include <sys/lock.h>
@@ -61,6 +62,7 @@
 #include <VBox/version.h>
 #include <VBox/log.h>
 #include <iprt/assert.h>
+#include <iprt/err.h>
 #include <iprt/initterm.h>
 #include <iprt/process.h>
 #include <iprt/string.h>
@@ -102,8 +104,6 @@ struct VBoxGuestDeviceState
     struct resource   *pIrqRes;
     /** Pointer to the IRQ handler. */
     void              *pfnIrqHandler;
-    /** VMMDev version */
-    uint32_t           u32Version;
 };
 
 
@@ -113,8 +113,7 @@ struct VBoxGuestDeviceState
 /*
  * Character device file handlers.
  */
-static d_fdopen_t vgdrvFreeBSDOpen;
-static d_close_t  vgdrvFreeBSDClose;
+static d_open_t   vgdrvFreeBSDOpen;
 static d_ioctl_t  vgdrvFreeBSDIOCtl;
 static int        vgdrvFreeBSDIOCtlSlow(PVBOXGUESTSESSION pSession, u_long ulCmd, caddr_t pvData, struct thread *pTd);
 static d_write_t  vgdrvFreeBSDWrite;
@@ -145,8 +144,7 @@ static struct cdevsw    g_vgdrvFreeBSDChrDevSW =
 {
     .d_version =        D_VERSION,
     .d_flags =          D_TRACKCLOSE | D_NEEDMINOR,
-    .d_fdopen =         vgdrvFreeBSDOpen,
-    .d_close =          vgdrvFreeBSDClose,
+    .d_open =           vgdrvFreeBSDOpen,
     .d_ioctl =          vgdrvFreeBSDIOCtl,
     .d_read =           vgdrvFreeBSDRead,
     .d_write =          vgdrvFreeBSDWrite,
@@ -154,81 +152,28 @@ static struct cdevsw    g_vgdrvFreeBSDChrDevSW =
     .d_name =           "vboxguest"
 };
 
+/** Device structure. */
+static struct cdev         *g_pDev;
+
 /** Device extention & session data association structure. */
 static VBOXGUESTDEVEXT      g_DevExt;
 
-/** List of cloned device. Managed by the kernel. */
-static struct clonedevs    *g_pvgdrvFreeBSDClones;
-/** The dev_clone event handler tag. */
-static eventhandler_tag     g_vgdrvFreeBSDEHTag;
 /** Reference counter */
 static volatile uint32_t    cUsers;
 /** selinfo structure used for polling. */
 static struct selinfo       g_SelInfo;
 
-/**
- * DEVFS event handler.
- */
-static void vgdrvFreeBSDClone(void *pvArg, struct ucred *pCred, char *pszName, int cchName, struct cdev **ppDev)
+static void vgdrvFreeBSDDtr(void *pSession)
 {
-    int iUnit;
-    int rc;
-
-    Log(("vgdrvFreeBSDClone: pszName=%s ppDev=%p\n", pszName, ppDev));
-
-    /*
-     * One device node per user, si_drv1 points to the session.
-     * /dev/vboxguest<N> where N = {0...255}.
-     */
-    if (!ppDev)
-        return;
-    if (strcmp(pszName, "vboxguest") == 0)
-        iUnit =  -1;
-    else if (dev_stdclone(pszName, NULL, "vboxguest", &iUnit) != 1)
-        return;
-    if (iUnit >= 256)
-    {
-        Log(("vgdrvFreeBSDClone: iUnit=%d >= 256 - rejected\n", iUnit));
-        return;
-    }
-
-    Log(("vgdrvFreeBSDClone: pszName=%s iUnit=%d\n", pszName, iUnit));
-
-    rc = clone_create(&g_pvgdrvFreeBSDClones, &g_vgdrvFreeBSDChrDevSW, &iUnit, ppDev, 0);
-    Log(("vgdrvFreeBSDClone: clone_create -> %d; iUnit=%d\n", rc, iUnit));
-    if (rc)
-    {
-        *ppDev = make_dev(&g_vgdrvFreeBSDChrDevSW,
-                          iUnit,
-                          UID_ROOT,
-                          GID_WHEEL,
-                          0664,
-                          "vboxguest%d", iUnit);
-        if (*ppDev)
-        {
-            dev_ref(*ppDev);
-            (*ppDev)->si_flags |= SI_CHEAPCLONE;
-            Log(("vgdrvFreeBSDClone: Created *ppDev=%p iUnit=%d si_drv1=%p si_drv2=%p\n",
-                     *ppDev, iUnit, (*ppDev)->si_drv1, (*ppDev)->si_drv2));
-            (*ppDev)->si_drv1 = (*ppDev)->si_drv2 = NULL;
-        }
-        else
-            Log(("vgdrvFreeBSDClone: make_dev iUnit=%d failed\n", iUnit));
-    }
-    else
-        Log(("vgdrvFreeBSDClone: Existing *ppDev=%p iUnit=%d si_drv1=%p si_drv2=%p\n",
-             *ppDev, iUnit, (*ppDev)->si_drv1, (*ppDev)->si_drv2));
+    VGDrvCommonCloseSession(&g_DevExt, pSession);
+    ASMAtomicDecU32(&cUsers);
 }
 
 /**
  * File open handler
  *
  */
-#if __FreeBSD_version >= 700000
-static int vgdrvFreeBSDOpen(struct cdev *pDev, int fOpen, struct thread *pTd, struct file *pFd)
-#else
-static int vgdrvFreeBSDOpen(struct cdev *pDev, int fOpen, struct thread *pTd)
-#endif
+static int vgdrvFreeBSDOpen(struct cdev *pDev, int fOpen, int DevType, struct thread *pTd)
 {
     int                 rc;
     PVBOXGUESTSESSION   pSession;
@@ -240,12 +185,6 @@ static int vgdrvFreeBSDOpen(struct cdev *pDev, int fOp
     LogFlow(("vgdrvFreeBSDOpen:\n"));
 
     /*
-     * Try grab it (we don't grab the giant, remember).
-     */
-    if (!ASMAtomicCmpXchgPtr(&pDev->si_drv1, (void *)0x42, NULL))
-        return EBUSY;
-
-    /*
      * Create a new session.
      */
     fRequestor = VMMDEV_REQUESTOR_USERMODE | VMMDEV_REQUESTOR_TRUST_NOT_GIVEN;
@@ -262,14 +201,13 @@ static int vgdrvFreeBSDOpen(struct cdev *pDev, int fOp
     rc = VGDrvCommonCreateUserSession(&g_DevExt, fRequestor, &pSession);
     if (RT_SUCCESS(rc))
     {
-        if (ASMAtomicCmpXchgPtr(&pDev->si_drv1, pSession, (void *)0x42))
-        {
-            Log(("vgdrvFreeBSDOpen: success - g_DevExt=%p pSession=%p rc=%d pid=%d\n", &g_DevExt, pSession, rc, (int)RTProcSelf()));
+        Log(("vgdrvFreeBSDOpen: success - g_DevExt=%p pSession=%p rc=%d pid=%d\n", &g_DevExt, pSession, rc, (int)RTProcSelf()));
+        rc = devfs_set_cdevpriv(pSession, vgdrvFreeBSDDtr);
+        if (rc)
+            VGDrvCommonCloseSession(&g_DevExt, pSession);
+        else
             ASMAtomicIncU32(&cUsers);
-            return 0;
-        }
-
-        VGDrvCommonCloseSession(&g_DevExt, pSession);
+        return rc;
     }
 
     LogRel(("vgdrvFreeBSDOpen: failed. rc=%d\n", rc));
@@ -277,33 +215,6 @@ static int vgdrvFreeBSDOpen(struct cdev *pDev, int fOp
 }
 
 /**
- * File close handler
- *
- */
-static int vgdrvFreeBSDClose(struct cdev *pDev, int fFile, int DevType, struct thread *pTd)
-{
-    PVBOXGUESTSESSION pSession = (PVBOXGUESTSESSION)pDev->si_drv1;
-    Log(("vgdrvFreeBSDClose: fFile=%#x pSession=%p\n", fFile, pSession));
-
-    /*
-     * Close the session if it's still hanging on to the device...
-     */
-    if (VALID_PTR(pSession))
-    {
-        VGDrvCommonCloseSession(&g_DevExt, pSession);
-        if (!ASMAtomicCmpXchgPtr(&pDev->si_drv1, NULL, pSession))
-            Log(("vgdrvFreeBSDClose: si_drv1=%p expected %p!\n", pDev->si_drv1, pSession));
-        ASMAtomicDecU32(&cUsers);
-        /* Don't use destroy_dev here because it may sleep resulting in a hanging user process. */
-        destroy_dev_sched(pDev);
-    }
-    else
-        Log(("vgdrvFreeBSDClose: si_drv1=%p!\n", pSession));
-    return 0;
-}
-
-
-/**
  * I/O control request.
  *
  * @returns depends...
@@ -316,8 +227,12 @@ static int vgdrvFreeBSDClose(struct cdev *pDev, int fF
 static int vgdrvFreeBSDIOCtl(struct cdev *pDev, u_long ulCmd, caddr_t pvData, int fFile, struct thread *pTd)
 {
     PVBOXGUESTSESSION pSession;
-    devfs_get_cdevpriv((void **)&pSession);
+    int rc;
 
+    rc = devfs_get_cdevpriv((void **)&pSession);
+    if (rc)
+        return rc;
+
     /*
      * Deal with the fast ioctl path first.
      */
@@ -512,12 +427,14 @@ int VBOXCALL VBoxGuestIDC(void *pvSession, uintptr_t u
 
 static int vgdrvFreeBSDPoll(struct cdev *pDev, int fEvents, struct thread *td)
 {
-    int fEventsProcessed;
+    PVBOXGUESTSESSION pSession;
+    int fEventsProcessed, rc;
 
     LogFlow(("vgdrvFreeBSDPoll: fEvents=%d\n", fEvents));
 
-    PVBOXGUESTSESSION pSession = (PVBOXGUESTSESSION)pDev->si_drv1;
-    if (RT_UNLIKELY(!VALID_PTR(pSession))) {
+    rc = devfs_get_cdevpriv((void **)&pSession);
+    if (rc)
+    {
         Log(("vgdrvFreeBSDPoll: no state data for %s\n", devtoname(pDev)));
         return (fEvents & (POLLHUP|POLLIN|POLLRDNORM|POLLOUT|POLLWRNORM));
     }
@@ -558,11 +475,8 @@ static int vgdrvFreeBSDDetach(device_t pDevice)
     /*
      * Reverse what we did in vgdrvFreeBSDAttach.
      */
-    if (g_vgdrvFreeBSDEHTag != NULL)
-        EVENTHANDLER_DEREGISTER(dev_clone, g_vgdrvFreeBSDEHTag);
+    destroy_dev(g_pDev);
 
-    clone_cleanup(&g_pvgdrvFreeBSDClones);
-
     vgdrvFreeBSDRemoveIRQ(pDevice, pState);
 
     if (pState->pVMMDevMemRes)
@@ -727,18 +641,21 @@ static int vgdrvFreeBSDAttach(device_t pDevice)
                     VGDrvCommonProcessOptionsFromHost(&g_DevExt);
 
                     /*
-                     * Configure device cloning.
+                     * Configure device.
                      */
-                    clone_setup(&g_pvgdrvFreeBSDClones);
-                    g_vgdrvFreeBSDEHTag = EVENTHANDLER_REGISTER(dev_clone, vgdrvFreeBSDClone, 0, 1000);
-                    if (g_vgdrvFreeBSDEHTag)
+                    g_pDev = make_dev(&g_vgdrvFreeBSDChrDevSW,
+                                      0,
+                                      UID_ROOT,
+                                      GID_WHEEL,
+                                      0664,
+                                      "vboxguest");
+                    if (g_pDev)
                     {
                         printf(DEVICE_NAME ": loaded successfully\n");
                         return 0;
                     }
 
-                    printf(DEVICE_NAME ": EVENTHANDLER_REGISTER(dev_clone,,,) failed\n");
-                    clone_cleanup(&g_pvgdrvFreeBSDClones);
+                    printf(DEVICE_NAME ": make_dev failed\n");
                     vgdrvFreeBSDRemoveIRQ(pDevice, pState);
                 }
                 else
