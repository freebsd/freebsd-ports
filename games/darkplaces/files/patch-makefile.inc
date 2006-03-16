--- makefile.inc.orig	Thu Aug 18 21:30:57 2005
+++ makefile.inc	Sun Jan 15 17:16:57 2006
@@ -1,5 +1,4 @@
 # Choose the compiler you want to use
-CC=gcc
 
 # athlon optimizations
 #CPUOPTIMIZATIONS=-march=athlon
@@ -135,13 +134,19 @@
 
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
 
@@ -157,14 +162,14 @@
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o $(OBJ_SOUND) $(OBJ_CD) $(OBJ_COMMON)
 
 LDFLAGS_UNIXCOMMON=-lm
-#LDFLAGS_UNIXCL=-L/usr/X11R6/lib -lX11 -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
+#LDFLAGS_UNIXCL=-L$(X11BASE)/lib -lX11 -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
 ifeq ($(DP_MAKE_TARGET), sunos)
 	LDFLAGS_UNIXCL=-R$(UNIX_X11LIBPATH) -L$(UNIX_X11LIBPATH) -lX11 -lXext -lXxf86vm $(LIB_SOUND)
 else
 	LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
 endif
 
-LDFLAGS_UNIXSDL=`sdl-config --libs`
+LDFLAGS_UNIXSDL=`$(SDL_CONFIG) --libs`
 EXE_UNIXCL=darkplaces-glx
 EXE_UNIXSV=darkplaces-dedicated
 EXE_UNIXSDL=darkplaces-sdl
@@ -195,7 +200,7 @@
 # Link
 LDFLAGS_MACOSXCL=$(LDFLAGS_UNIXCOMMON) -ldl $(LDFLAGS_UNIXCL)
 LDFLAGS_MACOSXSV=$(LDFLAGS_UNIXCOMMON) -ldl
-LDFLAGS_MACOSXSDL=$(LDFLAGS_UNIXCOMMON) -ldl `sdl-config --static-libs`
+LDFLAGS_MACOSXSDL=$(LDFLAGS_UNIXCOMMON) -ldl `$(SDL_CONFIG) --static-libs`
 
 OBJ_AGL= builddate.c sys_linux.o vid_agl.o $(OBJ_SOUND) $(OBJ_CD) $(OBJ_COMMON)
 
@@ -238,7 +243,7 @@
 LDFLAGS_WINCOMMON=-lwinmm -lwsock32
 LDFLAGS_WINCL=$(LDFLAGS_WINCOMMON) -mwindows -luser32 -lgdi32 -ldxguid -ldinput -lcomctl32
 LDFLAGS_WINSV=$(LDFLAGS_WINCOMMON) -mconsole
-LDFLAGS_WINSDL=$(LDFLAGS_WINCOMMON) `sdl-config --libs`
+LDFLAGS_WINSDL=$(LDFLAGS_WINCOMMON) `$(SDL_CONFIG) --libs`
 EXE_WINCL=darkplaces.exe
 EXE_WINSV=darkplaces-dedicated.exe
 EXE_WINSDL=darkplaces-sdl.exe
@@ -330,40 +335,40 @@
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
