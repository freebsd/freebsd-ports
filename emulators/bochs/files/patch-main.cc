--- main.cc.orig	Thu May 16 04:26:43 2002
+++ main.cc	Thu May 16 04:26:55 2002
@@ -1174,7 +1174,7 @@
   BX_MEM(0)->load_ROM(bx_options.vgarom.Opath->getptr (), 0xc0000);
   BX_CPU(0)->init (BX_MEM(0));
 #if BX_SUPPORT_APIC
-  BX_CPU(0)->local_apic.set_id (i);
+  BX_CPU(0)->local_apic.set_id (0);
 #endif
   BX_CPU(0)->reset(BX_RESET_HARDWARE);
 #else
