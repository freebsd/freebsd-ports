$FreeBSD$

--- ../../hotspot/src/os_cpu/bsd_amd64/vm/globals_bsd_amd64.hpp.orig	Thu Jun 15 17:58:02 2006
+++ ../../hotspot/src/os_cpu/bsd_amd64/vm/globals_bsd_amd64.hpp	Thu Jun 15 17:59:02 2006
@@ -12,7 +12,7 @@
 //
 define_pd_global(bool, DontYieldALot,            false);
 //define_pd_global(intx, ThreadStackSize,	 0); // 0 => use system default
-define_pd_global(intx, ThreadStackSize,		 256);
+define_pd_global(intx, ThreadStackSize,		 1024);
 define_pd_global(intx, VMThreadStackSize,	 1024);
 define_pd_global(intx, CompilerThreadStackSize,  0);
 define_pd_global(intx, SurvivorRatio,            8);
