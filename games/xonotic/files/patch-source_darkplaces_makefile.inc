--- source/darkplaces/makefile.inc.orig	2022-06-27 17:32:38 UTC
+++ source/darkplaces/makefile.inc
@@ -194,7 +194,7 @@ OPTIM_DEBUG=$(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -fno-math-errno -fno-trapping-math -fno-signaling-nans -fcx-limited-range -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
-OPTIM_RELEASE=-O3 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
+OPTIM_RELEASE=${CFLAGS} -fno-strict-aliasing $(CPUOPTIMIZATIONS)
 # NOTE: *never* *ever* use the -ffast-math or -funsafe-math-optimizations flag
 # Also, since gcc 5, -ffinite-math-only makes NaN and zero compare equal inside engine code but not inside QC, which causes error spam for seemingly valid QC code like if (x != 0) return 1 / x;
 
