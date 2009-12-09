--- src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c.orig	2009-12-07 12:20:44.000000000 +0100
+++ src/VBox/HostDrivers/VBoxNetAdp/freebsd/VBoxNetAdp-freebsd.c	2009-12-07 12:21:00.000000000 +0100
@@ -92,7 +92,7 @@
 DECLARE_MODULE(vboxnetadp, g_VBoxNetAdpFreeBSDModule, SI_SUB_PSEUDO, SI_ORDER_ANY);
 MODULE_VERSION(vboxnetadp, 1);
 MODULE_DEPEND(vboxnetadp, vboxdrv, 1, 1, 1);
-MODULE_DEPEND(vboxnetadp, ng_vboxnetflt, 1, 1, 1);
+MODULE_DEPEND(vboxnetadp, vboxnetflt, 1, 1, 1);
 
 /**
  * Module event handler
