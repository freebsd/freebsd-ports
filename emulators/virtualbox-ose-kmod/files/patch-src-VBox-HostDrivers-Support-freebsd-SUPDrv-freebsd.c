--- src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c.orig	2011-11-04 07:19:39.000000000 -0400
+++ src/VBox/HostDrivers/Support/freebsd/SUPDrv-freebsd.c	2011-11-29 17:34:56.000000000 -0500
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
