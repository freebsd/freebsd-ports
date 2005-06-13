--- src/tpb.h.orig	Mon Jun 13 14:32:31 2005
+++ src/tpb.h	Mon Jun 13 14:44:47 2005
@@ -70,6 +70,7 @@
   unsigned int ac_state;            /* ac connected */
   unsigned int powermgt_ac;         /* power management mode ac */
   unsigned int powermgt_battery;    /* power management mode battery */
+  unsigned int bluetooth_toggle;    /* bluetooth toggle */
 } t_thinkpad_state;
 
 #endif /* __TPB_H__*/
