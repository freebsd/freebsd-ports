--- makefile.inc.orig	2016-07-20 13:13:00 UTC
+++ makefile.inc
@@ -22,7 +22,7 @@ CC?=gcc
 # Experimental
 #CPUOPTIMIZATIONS?=-fno-math-errno -ffinite-math-only -fno-rounding-math -fno-signaling-nans -fassociative-math -freciprocal-math -fno-signed-zeros -fno-trapping-math
 # Normal
-CPUOPTIMIZATIONS?=-fno-math-errno -ffinite-math-only -fno-rounding-math -fno-signaling-nans -fno-trapping-math
+CPUOPTIMIZATIONS?=-fno-math-errno -ffinite-math-only -fno-rounding-math -fno-trapping-math
 # NOTE: *never* *ever* use the -ffast-math or -funsafe-math-optimizations flag
 
 SDL_CONFIG?=sdl2-config
@@ -193,7 +193,7 @@ OPTIM_DEBUG=$(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -fno-math-errno -fno-trapping-math -ffinite-math-only -fno-signaling-nans -fcx-limited-range -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
-OPTIM_RELEASE=-O3 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
+OPTIM_RELEASE=$(CPUOPTIMIZATIONS)
 # NOTE: *never* *ever* use the -ffast-math or -funsafe-math-optimizations flag
 
 DO_CC=$(CC) $(CFLAGS) -c $< -o $@
@@ -270,7 +270,7 @@ LDFLAGS_SUNOSSDL=$(LDFLAGS_UNIXCOMMON) -lrt -ldl -lsoc
 
 # Link
 LDFLAGS_BSDCL=$(LDFLAGS_UNIXCOMMON) -lutil $(LDFLAGS_UNIXCL)
-LDFLAGS_BSDSV=$(LDFLAGS_UNIXCOMMON) 
+LDFLAGS_BSDSV=-L$(LOCALBASE)/lib $(LDFLAGS_UNIXCOMMON)
 LDFLAGS_BSDSDL=$(LDFLAGS_UNIXCOMMON) $(LDFLAGS_UNIXSDL)
 
 
@@ -454,8 +454,8 @@ bin-release :
 	$(MAKE) prepare BUILD_DIR=build-obj/release/$(EXE)
 	$(MAKE) -C build-obj/release/$(EXE) $(EXE) \
 		DP_MAKE_TARGET=$(DP_MAKE_TARGET) DP_SOUND_API=$(DP_SOUND_API) \
-		CFLAGS='$(CFLAGS_COMMON) $(CFLAGS_FEATURES) $(CFLAGS_EXTRA) $(CFLAGS_RELEASE) $(OPTIM_RELEASE)'\
-		LDFLAGS='$(LDFLAGS_RELEASE) $(LDFLAGS_COMMON)' LEVEL=2
+		CFLAGS+='$(CFLAGS_COMMON) $(CFLAGS_FEATURES) $(CFLAGS_EXTRA) $(CFLAGS_RELEASE) $(OPTIM_RELEASE)'\
+		LDFLAGS+='$(LDFLAGS_RELEASE) $(LDFLAGS_COMMON)' LEVEL=2
 	$(STRIP) $(EXE)
 
 bin-release-profile :
@@ -485,11 +485,15 @@ world.o: world.c
 
 vid_glx.o: vid_glx.c
 	$(CHECKLEVEL2)
-	$(DO_CC) -I/usr/X11R6/include
+	$(DO_CC) -I$(LOCALBASE)/include
 
 keysym2ucs.o: keysym2ucs.c
 	$(CHECKLEVEL2)
-	$(DO_CC) -I/usr/X11R6/include
+	$(DO_CC) -I$(LOCALBASE)/include
+
+jpeg.o: jpeg.c
+	$(CHECKLEVEL2)
+	$(DO_CC) -I$(LOCALBASE)/include
 
 crypto.o: crypto.c
 	$(CHECKLEVEL2)
