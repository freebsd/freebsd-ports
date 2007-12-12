--- makefile.inc.orig	Sat Nov 10 06:34:18 2007
+++ makefile.inc	Thu Nov 29 16:39:58 2007
@@ -1,5 +1,5 @@
 # Choose the compiler you want to use
-CC=gcc
+CC?=gcc
 
 # athlon optimizations
 #CPUOPTIMIZATIONS=-march=athlon
@@ -172,7 +172,7 @@
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o $(OBJ_SOUND) $(OBJ_CD) $(OBJ_COMMON)
 
 LDFLAGS_UNIXCOMMON=-lm
-LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXpm -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
+LDFLAGS_UNIXCL=-L$(LOCALBASE)/lib -lX11 -lXpm -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
 LDFLAGS_UNIXCL_PRELOAD=-lz -ljpeg -lpng -lvorbis -lvorbisfile -lcurl
 LDFLAGS_UNIXSV_PRELOAD=-lz -lcurl
 LDFLAGS_UNIXSDL_PRELOAD=-lz -ljpeg -lpng -lvorbis -lvorbisfile -lcurl
@@ -376,28 +376,28 @@
 	@echo "========== $(EXE) (debug) =========="
 	$(MAKE) $(EXE) \
 		DP_MAKE_TARGET=$(DP_MAKE_TARGET) DP_SOUND_API=$(DP_SOUND_API) \
-		CFLAGS="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_DEBUG) $(OPTIM_DEBUG)"\
-		LDFLAGS="$(LDFLAGS_DEBUG) $(LDFLAGS_COMMON)"
+		CFLAGS+="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_DEBUG) $(OPTIM_DEBUG)"\
+		LDFLAGS+="$(LDFLAGS_DEBUG) $(LDFLAGS_COMMON)"
 
 bin-profile :
 	@echo
 	@echo "========== $(EXE) (profile) =========="
 	$(MAKE) $(EXE) \
 		DP_MAKE_TARGET=$(DP_MAKE_TARGET) DP_SOUND_API=$(DP_SOUND_API) \
-		CFLAGS="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_PROFILE) $(OPTIM_RELEASE)"\
-		LDFLAGS="$(LDFLAGS_PROFILE) $(LDFLAGS_COMMON)"
+		CFLAGS+="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_PROFILE) $(OPTIM_RELEASE)"\
+		LDFLAGS+="$(LDFLAGS_PROFILE) $(LDFLAGS_COMMON)"
 
 bin-release :
 	@echo
 	@echo "========== $(EXE) (release) =========="
 	$(MAKE) $(EXE) \
 		DP_MAKE_TARGET=$(DP_MAKE_TARGET) DP_SOUND_API=$(DP_SOUND_API) \
-		CFLAGS="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_RELEASE) $(OPTIM_RELEASE)"\
-		LDFLAGS="$(LDFLAGS_RELEASE) $(LDFLAGS_COMMON)"
+		CFLAGS+="$(CFLAGS_COMMON) $(CFLAGS_EXTRA) $(CFLAGS_RELEASE) $(OPTIM_RELEASE)"\
+		LDFLAGS+="$(LDFLAGS_RELEASE) $(LDFLAGS_COMMON)"
 	$(STRIP) $(EXE)
 
 vid_glx.o: vid_glx.c
-	$(DO_CC) -I/usr/X11R6/include
+	$(DO_CC) -I$(LOCALBASE)/include
 
 vid_sdl.o: vid_sdl.c
 	$(DO_CC) $(CFLAGS_SDL)
