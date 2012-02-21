- Fix compile error: 'D_PSEUDO' undeclared here on 10-CURRENT

Submitted by:	Jung-uk Kim <jkim@FreeBSD.org>

- Fix check that kernel module can not be unloaded when there
are running VMs

Submitted by:	aeichner
Reported by:	avg
--- src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c.orig	2011-11-04 12:19:39.000000000 +0100
+++ src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c	2011-12-13 12:22:44.325251163 +0100
@@ -100,7 +100,9 @@
 static struct cdevsw        g_VBoxDrvFreeBSDChrDevSW =
 {
     .d_version =        D_VERSION,
-#if __FreeBSD_version > 800061
+#if __FreeBSD_version >= 1000000
+    .d_flags =          D_TRACKCLOSE | D_NEEDMINOR,
+#elif __FreeBSD_version > 800061
     .d_flags =          D_PSEUDO | D_TRACKCLOSE | D_NEEDMINOR,
 #else
     .d_flags =          D_PSEUDO | D_TRACKCLOSE,
@@ -205,7 +207,7 @@
     Log(("VBoxDrvFreeBSDUnload:\n"));
 
     if (g_cUsers > 0)
-        return EBUSY;
+        return VERR_RESOURCE_BUSY;
 
     /*
      * Reserve what we did in VBoxDrvFreeBSDInit.
