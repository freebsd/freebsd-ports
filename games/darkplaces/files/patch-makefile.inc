--- makefile.inc.orig	Sun Apr 16 23:23:11 2006
+++ makefile.inc	Sun Jul 23 16:34:36 2006
@@ -1,5 +1,4 @@
 # Choose the compiler you want to use
-CC=gcc
 
 # athlon optimizations
 #CPUOPTIMIZATIONS=-march=athlon
@@ -137,13 +136,19 @@
 
 # Compilation
 # CFLAGS_COMMON=-MD -Wall -Werror
-CFLAGS_COMMON=-MD -Wall -Wsign-compare
+CFLAGS_COMMON=-DQ1DIR='\"$(Q1DIR)\"' -MD -Wall -Wsign-compare
 CFLAGS_DEBUG=-ggdb
 CFLAGS_PROFILE=-g -pg -ggdb
 CFLAGS_RELEASE=
 
+ifeq ($(WITH_OPTIMIZED_CFLAGS),YES)
 OPTIM_DEBUG=$(CPUOPTIMIZATIONS)
-OPTIM_RELEASE=-O2 -fno-strict-aliasing -ffast-math -funroll-loops $(CPUOPTIMIZATIONS)
+OPTIM_RELEASE=-O2 -fno-strict-aliasing -funroll-loops $(CPUOPTIMIZATIONS)
+
+ifneq ($(shell uname -p),alpha)
+OPTIM_RELEASE+=-ffast-math
+endif
+endif
 
 DO_CC=$(CC) $(CFLAGS) -c $< -o $@
 
@@ -159,9 +164,9 @@
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o $(OBJ_SOUND) $(OBJ_CD) $(OBJ_COMMON)
 
 LDFLAGS_UNIXCOMMON=-lm
-LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
+LDFLAGS_UNIXCL=-L$(X11BASE)/lib -lX11 -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
 
-LDFLAGS_UNIXSDL=`sdl-config --libs`
+LDFLAGS_UNIXSDL=`$(SDL_CONFIG) --libs`
 EXE_UNIXCL=darkplaces-glx
 EXE_UNIXSV=darkplaces-dedicated
 EXE_UNIXSDL=darkplaces-sdl
@@ -193,7 +198,7 @@
 # Link
 LDFLAGS_MACOSXCL=$(LDFLAGS_UNIXCOMMON) -ldl -framework Carbon $(LIB_SOUND)
 LDFLAGS_MACOSXSV=$(LDFLAGS_UNIXCOMMON) -ldl
-LDFLAGS_MACOSXSDL=$(LDFLAGS_UNIXCOMMON) -ldl `sdl-config --static-libs`
+LDFLAGS_MACOSXSDL=$(LDFLAGS_UNIXCOMMON) -ldl `$(SDL_CONFIG) --static-libs`
 
 OBJ_AGL= builddate.c sys_linux.o vid_agl.o $(OBJ_SOUND) $(OBJ_CD) $(OBJ_COMMON)
 
@@ -240,7 +245,7 @@
 LDFLAGS_WINCOMMON=-lwinmm -lwsock32
 LDFLAGS_WINCL=$(LDFLAGS_WINCOMMON) -mwindows -luser32 -lgdi32 -ldxguid -ldinput -lcomctl32
 LDFLAGS_WINSV=$(LDFLAGS_WINCOMMON) -mconsole
-LDFLAGS_WINSDL=$(LDFLAGS_WINCOMMON) `sdl-config --libs`
+LDFLAGS_WINSDL=$(LDFLAGS_WINCOMMON) `$(SDL_CONFIG) --libs`
 EXE_WINCL=darkplaces.exe
 EXE_WINSV=darkplaces-dedicated.exe
 EXE_WINSDL=darkplaces-sdl.exe
@@ -357,40 +362,40 @@
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
 	strip $(EXE)
 
 vid_glx.o: vid_glx.c
-	$(DO_CC) -I/usr/X11R6/include
+	$(DO_CC) -I$(X11BASE)/include
 
 vid_sdl.o: vid_sdl.c
-	$(DO_CC) `sdl-config --cflags`
+	$(DO_CC) `$(SDL_CONFIG) --cflags`
 
 sys_sdl.o: sys_sdl.c
-	$(DO_CC) `sdl-config --cflags`
+	$(DO_CC) `$(SDL_CONFIG) --cflags`
 
 snd_sdl.o: snd_sdl.c
-	$(DO_CC) `sdl-config --cflags`
+	$(DO_CC) `$(SDL_CONFIG) --cflags`
 
 cd_sdl.o: cd_sdl.c
-	$(DO_CC) `sdl-config --cflags`
+	$(DO_CC) `$(SDL_CONFIG) --cflags`
 
 darkplaces.o: %.o : %.rc
 	windres -o $@ $<
