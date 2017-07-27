--- plugin.h.orig	2017-07-27 21:00:33.547902000 +0000
+++ plugin.h	2017-07-27 21:01:01.818005000 +0000
@@ -264,7 +264,11 @@
   ((eth_pktmover_c*)bx_devices.pluginNetModCtl->init_module(a,(void*)b,(void*)c,d))
 
 ///////// Gameport macro
+#if BX_SUPPORT_GAMEPORT
 #define DEV_gameport_set_enabled(a) bx_devices.pluginGameport->set_enabled(a)
+#else
+#define DEV_gameport_set_enabled(a)
+#endif
 
 
 #if BX_HAVE_DLFCN_H
