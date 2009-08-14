--- src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c.old	2009-05-04 20:29:23.000000000 +0200
+++ src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c	2009-05-04 20:30:28.000000000 +0200
@@ -162,7 +162,11 @@
     if (rc)
     {
         *ppDev = make_dev(&g_VBoxGuestFreeBSDChrDevSW,
+#if __FreeBSD_version < 800062
                           unit2minor(iUnit),
+#else
+			  iUnit,
+#endif
                           UID_ROOT,
                           GID_WHEEL,
                           0644,
