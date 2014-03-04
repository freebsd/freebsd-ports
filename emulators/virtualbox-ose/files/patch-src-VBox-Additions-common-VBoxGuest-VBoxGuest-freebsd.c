--- src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c.orig	2014-02-25 12:00:25.000000000 -0500
+++ src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c	2014-03-01 03:23:16.000000000 -0500
@@ -89,8 +89,7 @@
 /*
  * Character device file handlers.
  */
-static d_fdopen_t VBoxGuestFreeBSDOpen;
-static d_close_t  VBoxGuestFreeBSDClose;
+static d_open_t   VBoxGuestFreeBSDOpen;
 static d_ioctl_t  VBoxGuestFreeBSDIOCtl;
 static d_write_t  VBoxGuestFreeBSDWrite;
 static d_read_t   VBoxGuestFreeBSDRead;
@@ -121,8 +120,7 @@
 {
     .d_version =        D_VERSION,
     .d_flags =          D_TRACKCLOSE | D_NEEDMINOR,
-    .d_fdopen =         VBoxGuestFreeBSDOpen,
-    .d_close =          VBoxGuestFreeBSDClose,
+    .d_open =           VBoxGuestFreeBSDOpen,
     .d_ioctl =          VBoxGuestFreeBSDIOCtl,
     .d_read =           VBoxGuestFreeBSDRead,
     .d_write =          VBoxGuestFreeBSDWrite,
@@ -130,106 +128,45 @@
     .d_name =           DEVICE_NAME
 };
 
+/** Device structure. */
+static struct cdev         *g_pDev;
 /** Device extention & session data association structure. */
 static VBOXGUESTDEVEXT      g_DevExt;
-/** List of cloned device. Managed by the kernel. */
-static struct clonedevs    *g_pVBoxGuestFreeBSDClones;
-/** The dev_clone event handler tag. */
-static eventhandler_tag     g_VBoxGuestFreeBSDEHTag;
 /** Reference counter */
 static volatile uint32_t    cUsers;
 /** selinfo structure used for polling. */
 static struct selinfo       g_SelInfo;
 
-/**
- * DEVFS event handler.
- */
-static void VBoxGuestFreeBSDClone(void *pvArg, struct ucred *pCred, char *pszName, int cchName, struct cdev **ppDev)
+static void VBoxGuestFreeBSDDtr(void *pSession)
 {
-    int iUnit;
-    int rc;
-
-    Log(("VBoxGuestFreeBSDClone: pszName=%s ppDev=%p\n", pszName, ppDev));
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
-        Log(("VBoxGuestFreeBSDClone: iUnit=%d >= 256 - rejected\n", iUnit));
-        return;
-    }
-
-    Log(("VBoxGuestFreeBSDClone: pszName=%s iUnit=%d\n", pszName, iUnit));
-
-    rc = clone_create(&g_pVBoxGuestFreeBSDClones, &g_VBoxGuestFreeBSDChrDevSW, &iUnit, ppDev, 0);
-    Log(("VBoxGuestFreeBSDClone: clone_create -> %d; iUnit=%d\n", rc, iUnit));
-    if (rc)
-    {
-        *ppDev = make_dev(&g_VBoxGuestFreeBSDChrDevSW,
-                          iUnit,
-                          UID_ROOT,
-                          GID_WHEEL,
-                          0664,
-                          "vboxguest%d", iUnit);
-        if (*ppDev)
-        {
-            dev_ref(*ppDev);
-            (*ppDev)->si_flags |= SI_CHEAPCLONE;
-            Log(("VBoxGuestFreeBSDClone: Created *ppDev=%p iUnit=%d si_drv1=%p si_drv2=%p\n",
-                     *ppDev, iUnit, (*ppDev)->si_drv1, (*ppDev)->si_drv2));
-            (*ppDev)->si_drv1 = (*ppDev)->si_drv2 = NULL;
-        }
-        else
-            Log(("VBoxGuestFreeBSDClone: make_dev iUnit=%d failed\n", iUnit));
-    }
-    else
-        Log(("VBoxGuestFreeBSDClone: Existing *ppDev=%p iUnit=%d si_drv1=%p si_drv2=%p\n",
-             *ppDev, iUnit, (*ppDev)->si_drv1, (*ppDev)->si_drv2));
+    VBoxGuestCloseSession(&g_DevExt, pSession);
+    ASMAtomicDecU32(&cUsers);
 }
 
 /**
  * File open handler
  *
  */
-#if __FreeBSD_version >= 700000
-static int VBoxGuestFreeBSDOpen(struct cdev *pDev, int fOpen, struct thread *pTd, struct file *pFd)
-#else
-static int VBoxGuestFreeBSDOpen(struct cdev *pDev, int fOpen, struct thread *pTd)
-#endif
+static int VBoxGuestFreeBSDOpen(struct cdev *pDev, int fOpen, int DevType, struct thread *pTd)
 {
-    int                 rc;
-    PVBOXGUESTSESSION   pSession;
+    PVBOXGUESTSESSION pSession;
+    int rc;
 
     LogFlow((DEVICE_NAME ":VBoxGuestFreeBSDOpen\n"));
 
     /*
-     * Try grab it (we don't grab the giant, remember).
-     */
-    if (!ASMAtomicCmpXchgPtr(&pDev->si_drv1, (void *)0x42, NULL))
-        return EBUSY;
-
-    /*
      * Create a new session.
      */
     rc = VBoxGuestCreateUserSession(&g_DevExt, &pSession);
     if (RT_SUCCESS(rc))
     {
-        if (ASMAtomicCmpXchgPtr(&pDev->si_drv1, pSession, (void *)0x42))
-        {
-            Log((DEVICE_NAME ":VBoxGuestFreeBSDOpen success: g_DevExt=%p pSession=%p rc=%d pid=%d\n", &g_DevExt, pSession, rc, (int)RTProcSelf()));
+        Log((DEVICE_NAME ":VBoxGuestFreeBSDOpen success: g_DevExt=%p pSession=%p rc=%d pid=%d\n", &g_DevExt, pSession, rc, (int)RTProcSelf()));
+        rc = devfs_set_cdevpriv(pSession, VBoxGuestFreeBSDDtr);
+        if (rc)
+            VBoxGuestCloseSession(&g_DevExt, pSession);
+        else
             ASMAtomicIncU32(&cUsers);
-            return 0;
-        }
-
-        VBoxGuestCloseSession(&g_DevExt, pSession);
+        return rc;
     }
 
     LogRel((DEVICE_NAME ":VBoxGuestFreeBSDOpen: failed. rc=%d\n", rc));
@@ -237,47 +174,19 @@
 }
 
 /**
- * File close handler
- *
- */
-static int VBoxGuestFreeBSDClose(struct cdev *pDev, int fFile, int DevType, struct thread *pTd)
-{
-    PVBOXGUESTSESSION pSession = (PVBOXGUESTSESSION)pDev->si_drv1;
-    Log(("VBoxGuestFreeBSDClose: fFile=%#x pSession=%p\n", fFile, pSession));
-
-    /*
-     * Close the session if it's still hanging on to the device...
-     */
-    if (VALID_PTR(pSession))
-    {
-        VBoxGuestCloseSession(&g_DevExt, pSession);
-        if (!ASMAtomicCmpXchgPtr(&pDev->si_drv1, NULL, pSession))
-            Log(("VBoxGuestFreeBSDClose: si_drv1=%p expected %p!\n", pDev->si_drv1, pSession));
-        ASMAtomicDecU32(&cUsers);
-        /* Don't use destroy_dev here because it may sleep resulting in a hanging user process. */
-        destroy_dev_sched(pDev);
-    }
-    else
-        Log(("VBoxGuestFreeBSDClose: si_drv1=%p!\n", pSession));
-    return 0;
-}
-
-/**
  * IOCTL handler
  *
  */
 static int VBoxGuestFreeBSDIOCtl(struct cdev *pDev, u_long ulCmd, caddr_t pvData, int fFile, struct thread *pTd)
 {
-    LogFlow((DEVICE_NAME ":VBoxGuestFreeBSDIOCtl\n"));
+    PVBOXGUESTSESSION pSession;
+    int rc;
 
-    int rc = 0;
+    LogFlow((DEVICE_NAME ":VBoxGuestFreeBSDIOCtl\n"));
 
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
@@ -361,12 +270,14 @@
 
 static int VBoxGuestFreeBSDPoll (struct cdev *pDev, int fEvents, struct thread *td)
 {
-    int fEventsProcessed;
+    PVBOXGUESTSESSION pSession;
+    int fEventsProcessed, rc;
 
     LogFlow((DEVICE_NAME "::Poll: fEvents=%d\n", fEvents));
 
-    PVBOXGUESTSESSION pSession = (PVBOXGUESTSESSION)pDev->si_drv1;
-    if (RT_UNLIKELY(!VALID_PTR(pSession))) {
+    rc = devfs_get_cdevpriv((void **)&pSession);
+    if (rc)
+    {
         Log((DEVICE_NAME "::Poll: no state data for %s\n", devtoname(pDev)));
         return (fEvents & (POLLHUP|POLLIN|POLLRDNORM|POLLOUT|POLLWRNORM));
     }
@@ -407,10 +318,7 @@
     /*
      * Reverse what we did in VBoxGuestFreeBSDAttach.
      */
-    if (g_VBoxGuestFreeBSDEHTag != NULL)
-        EVENTHANDLER_DEREGISTER(dev_clone, g_VBoxGuestFreeBSDEHTag);
-
-    clone_cleanup(&g_pVBoxGuestFreeBSDClones);
+    destroy_dev(g_pDev);
 
     VBoxGuestFreeBSDRemoveIRQ(pDevice, pState);
 
@@ -562,18 +470,21 @@
                 if (RT_SUCCESS(rc))
                 {
                     /*
-                     * Configure device cloning.
+                     * Configure device.
                      */
-                    clone_setup(&g_pVBoxGuestFreeBSDClones);
-                    g_VBoxGuestFreeBSDEHTag = EVENTHANDLER_REGISTER(dev_clone, VBoxGuestFreeBSDClone, 0, 1000);
-                    if (g_VBoxGuestFreeBSDEHTag)
+                    g_pDev = make_dev(&g_VBoxGuestFreeBSDChrDevSW,
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
-                    clone_cleanup(&g_pVBoxGuestFreeBSDClones);
+                    printf(DEVICE_NAME ": make_dev failed\n");
                     VBoxGuestFreeBSDRemoveIRQ(pDevice, pState);
                 }
                 else
