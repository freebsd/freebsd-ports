--- src/tpb.h.orig	2005-07-18 14:15:59 UTC
+++ src/tpb.h
@@ -70,6 +70,7 @@ typedef struct {
   unsigned int ac_state;            /* ac connected */
   unsigned int powermgt_ac;         /* power management mode ac */
   unsigned int powermgt_battery;    /* power management mode battery */
+  unsigned int bluetooth_toggle;    /* bluetooth toggle */
 } t_thinkpad_state;
 
 #endif /* __TPB_H__*/
