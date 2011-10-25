--- makefile.inc.orig	2011-06-01 14:47:42.000000000 +0400
+++ makefile.inc	2011-10-23 00:50:35.000000000 +0400
@@ -201,8 +201,8 @@
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -ffast-math -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -fno-math-errno -fno-trapping-math -ffinite-math-only -fno-signaling-nans -fcx-limited-range -funroll-loops $(CPUOPTIMIZATIONS)
 #OPTIM_RELEASE=-O2 -fno-strict-aliasing -funroll-loops $(CPUOPTIMIZATIONS)
-#OPTIM_RELEASE=-O2 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
-OPTIM_RELEASE=-O3 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
+OPTIM_RELEASE=$(CPUOPTIMIZATIONS)
+#OPTIM_RELEASE=-O3 -fno-strict-aliasing $(CPUOPTIMIZATIONS)
 # NOTE: *never* *ever* use the -ffast-math or -funsafe-math-optimizations flag
 
 DO_CC=$(CC) $(CFLAGS) -c $< -o $@
@@ -219,7 +219,7 @@
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o thread_pthread.o keysym2ucs.o $(OBJ_SOUND) $(OBJ_CD) $(OBJ_COMMON)
 
 LDFLAGS_UNIXCOMMON=-lm $(LIB_ODE) $(LIB_JPEG) $(LIB_CRYPTO) $(LIB_CRYPTO_RIJNDAEL)
-LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXpm -lXext -lXxf86dga -lXxf86vm -pthread $(LIB_SOUND)
+LDFLAGS_UNIXCL=-L$(LOCALBASE)/lib -lX11 -lXpm -lXext -lXxf86dga -lXxf86vm -pthread $(LIB_SOUND)
 LDFLAGS_UNIXCL_PRELOAD=-lz -ljpeg -lpng -logg -ltheora -lvorbis -lvorbisenc -lvorbisfile -lcurl -lmodplug
 LDFLAGS_UNIXSV_PRELOAD=-lz -ljpeg -lpng -lcurl
 LDFLAGS_UNIXSDL_PRELOAD=-lz -ljpeg -lpng -logg -ltheora -lvorbis -lvorbisenc -lvorbisfile -lcurl -lmodplug
@@ -453,8 +453,8 @@
 	@echo "========== $(EXE) (debug) =========="
 	$(MAKE) $(EXE) \
 		DP_MAKE_TARGET=$(DP_MAKE_TARGET) DP_SOUND_API=$(DP_SOUND_API) \
-		CFLAGS="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_DEBUG) $(OPTIM_DEBUG)"\
-		LDFLAGS="$(LDFLAGS_DEBUG) $(LDFLAGS_COMMON)" LEVEL=2
+		CFLAGS+="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_DEBUG) $(OPTIM_DEBUG)"\
+		LDFLAGS+="$(LDFLAGS_DEBUG) $(LDFLAGS_COMMON)" LEVEL=2
 
 bin-profile :
 	$(CHECKLEVEL1)
@@ -462,8 +462,8 @@
 	@echo "========== $(EXE) (profile) =========="
 	$(MAKE) $(EXE) \
 		DP_MAKE_TARGET=$(DP_MAKE_TARGET) DP_SOUND_API=$(DP_SOUND_API) \
-		CFLAGS="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_PROFILE) $(OPTIM_RELEASE)"\
-		LDFLAGS="$(LDFLAGS_PROFILE) $(LDFLAGS_COMMON)" LEVEL=2
+		CFLAGS+="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_PROFILE) $(OPTIM_RELEASE)"\
+		LDFLAGS+="$(LDFLAGS_PROFILE) $(LDFLAGS_COMMON)" LEVEL=2
 
 bin-release :
 	$(CHECKLEVEL1)
@@ -471,8 +471,8 @@
 	@echo "========== $(EXE) (release) =========="
 	$(MAKE) $(EXE) \
 		DP_MAKE_TARGET=$(DP_MAKE_TARGET) DP_SOUND_API=$(DP_SOUND_API) \
-		CFLAGS="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_RELEASE) $(OPTIM_RELEASE)"\
-		LDFLAGS="$(LDFLAGS_RELEASE) $(LDFLAGS_COMMON)" LEVEL=2
+		CFLAGS+="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_RELEASE) $(OPTIM_RELEASE)"\
+		LDFLAGS+="$(LDFLAGS_RELEASE) $(LDFLAGS_COMMON)" LEVEL=2
 	$(STRIP) $(EXE)
 
 bin-release-profile :
@@ -496,11 +496,11 @@
 
 vid_glx.o: vid_glx.c
 	$(CHECKLEVEL2)
-	$(DO_CC) -I/usr/X11R6/include
+	$(DO_CC) -I$(LOCALBASE)/include
 
 keysym2ucs.o: keysym2ucs.c
 	$(CHECKLEVEL2)
-	$(DO_CC) -I/usr/X11R6/include
+	$(DO_CC) -I$(LOCALBASE)/include
 
 vid_sdl.o: vid_sdl.c
 	$(CHECKLEVEL2)
