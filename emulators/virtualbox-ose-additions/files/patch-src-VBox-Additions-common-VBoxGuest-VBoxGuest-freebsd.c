--- src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c.orig	2011-04-21 10:29:52.000000000 +0000
+++ src/VBox/Additions/common/VBoxGuest/VBoxGuest-freebsd.c	2011-04-27 20:52:04.000000000 +0000
@@ -177,7 +177,7 @@
                           iUnit,
                           UID_ROOT,
                           GID_WHEEL,
-                          0644,
+                          0664,
                           "vboxguest%d", iUnit);
         if (*ppDev)
         {
