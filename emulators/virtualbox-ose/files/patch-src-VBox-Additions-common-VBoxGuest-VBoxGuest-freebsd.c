--- src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c.orig	2015-11-10 17:00:16 UTC
+++ src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c
@@ -92,8 +92,6 @@ struct VBoxGuestDeviceState
     struct resource   *pIrqRes;
     /** Pointer to the IRQ handler. */
     void              *pfnIrqHandler;
-    /** VMMDev version */
-    uint32_t           u32Version;
 };
 
 
@@ -103,8 +101,7 @@ struct VBoxGuestDeviceState
 /*
  * Character device file handlers.
  */
-static d_fdopen_t vgdrvFreeBSDOpen;
-static d_close_t  vgdrvFreeBSDClose;
+static d_open_t   vgdrvFreeBSDOpen;
 static d_ioctl_t  vgdrvFreeBSDIOCtl;
 static d_write_t  vgdrvFreeBSDWrite;
 static d_read_t   vgdrvFreeBSDRead;
@@ -134,8 +131,7 @@ static struct cdevsw    g_vgdrvFreeBSDCh
 {
     .d_version =        D_VERSION,
     .d_flags =          D_TRACKCLOSE | D_NEEDMINOR,
-    .d_fdopen =         vgdrvFreeBSDOpen,
-    .d_close =          vgdrvFreeBSDClose,
+    .d_open =           vgdrvFreeBSDOpen,
     .d_ioctl =          vgdrvFreeBSDIOCtl,
     .d_read =           vgdrvFreeBSDRead,
     .d_write =          vgdrvFreeBSDWrite,
@@ -143,81 +139,28 @@ static struct cdevsw    g_vgdrvFreeBSDCh
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
@@ -225,25 +168,18 @@ static int vgdrvFreeBSDOpen(struct cdev 
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
     rc = VGDrvCommonCreateUserSession(&g_DevExt, &pSession);
     if (RT_SUCCESS(rc))
     {
-        if (ASMAtomicCmpXchgPtr(&pDev->si_drv1, pSession, (void *)0x42))
-        {
-            Log(("vgdrvFreeBSDOpen: success - g_DevExt=%p pSession=%p rc=%d pid=%d\n", &g_DevExt, pSession, rc, (int)RTProcSelf()));
+        Log((DEVICE_NAME ":vgdrvFreeBSDOpen success: g_DevExt=%p pSession=%p rc=%d pid=%d\n", &g_DevExt, pSession, rc, (int)RTProcSelf()));
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
@@ -251,47 +187,17 @@ static int vgdrvFreeBSDOpen(struct cdev 
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
-/**
  * IOCTL handler
  *
  */
 static int vgdrvFreeBSDIOCtl(struct cdev *pDev, u_long ulCmd, caddr_t pvData, int fFile, struct thread *pTd)
 {
-    LogFlow(("vgdrvFreeBSDIOCtl\n"));
-
-    int rc = 0;
+    int                 rc;
+    PVBOXGUESTSESSION   pSession;
 
-    /*
-     * Validate the input.
-     */
-    PVBOXGUESTSESSION pSession = (PVBOXGUESTSESSION)pDev->si_drv1;
-    if (RT_UNLIKELY(!VALID_PTR(pSession)))
-        return EINVAL;
+    rc = devfs_get_cdevpriv((void **)&pSession);
+    if (rc)
+        return rc;
 
     /*
      * Validate the request wrapper.
@@ -308,43 +214,46 @@ static int vgdrvFreeBSDIOCtl(struct cdev
         Log(("vgdrvFreeBSDIOCtl: bad magic %#x; pArg=%p Cmd=%lu.\n", ReqWrap->u32Magic, pvData, ulCmd));
         return EINVAL;
     }
-    if (RT_UNLIKELY(   ReqWrap->cbData == 0
-                    || ReqWrap->cbData > _1M*16))
+    if (RT_UNLIKELY(ReqWrap->cbData > _1M*16))
     {
         printf("vgdrvFreeBSDIOCtl: bad size %#x; pArg=%p Cmd=%lu.\n", ReqWrap->cbData, pvData, ulCmd);
         return EINVAL;
     }
 
     /*
-     * Read the request.
+     * Read the request payload if any; requests like VBOXGUEST_IOCTL_CANCEL_ALL_WAITEVENTS have no data payload.
      */
-    void *pvBuf = RTMemTmpAlloc(ReqWrap->cbData);
-    if (RT_UNLIKELY(!pvBuf))
+    void *pvBuf = NULL;
+    if (RT_LIKELY(ReqWrap->cbData > 0))
     {
-        Log(("vgdrvFreeBSDIOCtl: RTMemTmpAlloc failed to alloc %d bytes.\n", ReqWrap->cbData));
-        return ENOMEM;
-    }
+        pvBuf = RTMemTmpAlloc(ReqWrap->cbData);
+        if (RT_UNLIKELY(!pvBuf))
+        {
+            Log((DEVICE_NAME ":vgdrvFreeBSDIOCtl: RTMemTmpAlloc failed to alloc %d bytes.\n", ReqWrap->cbData));
+            return ENOMEM;
+        }
 
-    rc = copyin((void *)(uintptr_t)ReqWrap->pvDataR3, pvBuf, ReqWrap->cbData);
-    if (RT_UNLIKELY(rc))
-    {
-        RTMemTmpFree(pvBuf);
-        Log(("vgdrvFreeBSDIOCtl: copyin failed; pvBuf=%p pArg=%p Cmd=%lu. rc=%d\n", pvBuf, pvData, ulCmd, rc));
-        return EFAULT;
-    }
-    if (RT_UNLIKELY(   ReqWrap->cbData != 0
-                    && !VALID_PTR(pvBuf)))
-    {
-        RTMemTmpFree(pvBuf);
-        Log(("vgdrvFreeBSDIOCtl: pvBuf invalid pointer %p\n", pvBuf));
-        return EINVAL;
+        rc = copyin((void *)(uintptr_t)ReqWrap->pvDataR3, pvBuf, ReqWrap->cbData);
+        if (RT_UNLIKELY(rc))
+        {
+            RTMemTmpFree(pvBuf);
+            Log(("vgdrvFreeBSDIOCtl: copyin failed; pvBuf=%p pArg=%p Cmd=%lu. rc=%d\n", pvBuf, pvData, ulCmd, rc));
+            return EFAULT;
+        }
+        if (RT_UNLIKELY(   ReqWrap->cbData != 0
+                        && !VALID_PTR(pvBuf)))
+        {
+            RTMemTmpFree(pvBuf);
+            Log(("vgdrvFreeBSDIOCtl: pvBuf invalid pointer %p\n", pvBuf));
+            return EINVAL;
+        }
     }
     Log(("vgdrvFreeBSDIOCtl: pSession=%p pid=%d.\n", pSession, (int)RTProcSelf()));
 
     /*
      * Process the IOCtl.
      */
-    size_t cbDataReturned;
+    size_t cbDataReturned = 0;
     rc = VGDrvCommonIoCtl(ulCmd, &g_DevExt, pSession, pvBuf, ReqWrap->cbData, &cbDataReturned);
     if (RT_SUCCESS(rc))
     {
@@ -375,12 +284,14 @@ static int vgdrvFreeBSDIOCtl(struct cdev
 
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
@@ -421,10 +332,7 @@ static int vgdrvFreeBSDDetach(device_t p
     /*
      * Reverse what we did in vgdrvFreeBSDAttach.
      */
-    if (g_vgdrvFreeBSDEHTag != NULL)
-        EVENTHANDLER_DEREGISTER(dev_clone, g_vgdrvFreeBSDEHTag);
-
-    clone_cleanup(&g_pvgdrvFreeBSDClones);
+    destroy_dev(g_pDev);
 
     vgdrvFreeBSDRemoveIRQ(pDevice, pState);
 
@@ -576,18 +484,21 @@ static int vgdrvFreeBSDAttach(device_t p
                 if (RT_SUCCESS(rc))
                 {
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
