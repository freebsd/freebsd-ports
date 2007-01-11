--- ic/m68k/m68k-bus-auto.c.orig	Thu Jan 11 12:09:14 2007
+++ ic/m68k/m68k-bus-auto.c	Thu Jan 11 12:10:30 2007
@@ -156,7 +156,7 @@
 };
 
 /* the 32-bit bus router used on the 68020 and 68030: */
-static const tme_bus_lane_t tme_m68k_router_32[TME_M68K_BUS_ROUTER_SIZE(TME_BUS32_LOG2)] = {
+const tme_bus_lane_t tme_m68k_router_32[TME_M68K_BUS_ROUTER_SIZE(TME_BUS32_LOG2)] = {
 
   /* [m68k] initiator maximum cycle size: 8 bits
      [m68k] initiator A1,A0: 00
