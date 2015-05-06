--- makefile.inc.orig	2014-04-05 10:07:18 UTC
+++ makefile.inc
@@ -189,7 +189,7 @@ OPTIM_DEBUG=$(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -fno-math-errno -fno-trapping-math -ffinite-math-only -fno-signaling-nans -fcx-limited-range -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
-OPTIM_RELEASE=-O3 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
+OPTIM_RELEASE=$(CPUOPTIMIZATIONS)
 # NOTE: *never* *ever* use the -ffast-math or -funsafe-math-optimizations flag
 
 DO_CC=$(CC) $(CFLAGS) -c $< -o $@
@@ -470,8 +470,8 @@ bin-release :
 	$(MAKE) prepare BUILD_DIR=build-obj/release/$(EXE)
 	$(MAKE) -C build-obj/release/$(EXE) $(EXE) \
 		DP_MAKE_TARGET=$(DP_MAKE_TARGET) DP_SOUND_API=$(DP_SOUND_API) \
-		CFLAGS='$(CFLAGS_COMMON) $(CFLAGS_FEATURES) $(CFLAGS_EXTRA) $(CFLAGS_RELEASE) $(OPTIM_RELEASE)'\
-		LDFLAGS='$(LDFLAGS_RELEASE) $(LDFLAGS_COMMON)' LEVEL=2
+		CFLAGS+='$(CFLAGS_COMMON) $(CFLAGS_FEATURES) $(CFLAGS_EXTRA) $(CFLAGS_RELEASE) $(OPTIM_RELEASE)'\
+		LDFLAGS+='$(LDFLAGS_RELEASE) $(LDFLAGS_COMMON)' LEVEL=2
 	$(STRIP) $(EXE)
 
 bin-release-profile :
