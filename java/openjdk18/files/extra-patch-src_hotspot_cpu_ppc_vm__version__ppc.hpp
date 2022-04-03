--- src/hotspot/cpu/ppc/vm_version_ppc.hpp.orig	2019-10-16 11:31:09.000000000 -0700
+++ src/hotspot/cpu/ppc/vm_version_ppc.hpp	2019-10-23 12:54:06.972903000 -0700
@@ -108,7 +108,7 @@
   static bool has_lqarx()   { return (_features & lqarx_m) != 0; }
   static bool has_vcipher() { return (_features & vcipher_m) != 0; }
   static bool has_vpmsumb() { return (_features & vpmsumb_m) != 0; }
-  static bool has_mfdscr()  { return (_features & mfdscr_m) != 0; }
+  static bool has_mfdscr()  { return false; }
   static bool has_vsx()     { return (_features & vsx_m) != 0; }
   static bool has_ldbrx()   { return (_features & ldbrx_m) != 0; }
   static bool has_stdbrx()  { return (_features & stdbrx_m) != 0; }
