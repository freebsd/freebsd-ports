--- source/darkplaces/makefile.inc.orig	2023-04-30 08:22:32 UTC
+++ source/darkplaces/makefile.inc
@@ -197,7 +197,7 @@ OPTIM_DEBUG=$(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O3 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
-OPTIM_RELEASE=-O3 -fno-strict-aliasing -fno-math-errno -fno-trapping-math $(CPUOPTIMIZATIONS)
+OPTIM_RELEASE=${CFLAGS} -fno-strict-aliasing -fno-math-errno -fno-trapping-math $(CPUOPTIMIZATIONS)
 # NOTE: *never* *ever* use the -ffast-math or -funsafe-math-optimizations flag
 # Also, since gcc 5, -ffinite-math-only makes NaN and zero compare equal inside engine code but not inside QC, which causes error spam for seemingly valid QC code like if (x != 0) return 1 / x;
 
