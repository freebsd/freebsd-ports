--- ./makefile.inc.orig	Tue Jul  4 17:01:40 2006
+++ ./makefile.inc	Mon Aug 21 18:10:16 2006
@@ -1,5 +1,5 @@
 # Choose the compiler you want to use
-CC=gcc
+CC?=gcc
 
 # athlon optimizations
 #CPUOPTIMIZATIONS=-march=athlon
@@ -138,14 +138,19 @@
 
 
 # Compilation
-CFLAGS_COMMON=$(CFLAGS_MAKEDEP) $(CFLAGS_FS) -Wall -Wsign-compare
+CFLAGS_COMMON=$(CFLAGS_MAKEDEP) $(CFLAGS_FS) -Wall -Wsign-compare -DDP_FS_BASEDIR='\"$(Q1DIR)\"'
 CFLAGS_DEBUG=-ggdb
 CFLAGS_PROFILE=-g -pg -ggdb
 CFLAGS_RELEASE=
 CFLAGS_SDL=`$(SDL_CONFIG) --cflags`
 
+ifeq ($(WITH_OPTIMIZED_CFLAGS),YES)
 OPTIM_DEBUG=$(CPUOPTIMIZATIONS)
-OPTIM_RELEASE=-O2 -fno-strict-aliasing -ffast-math -funroll-loops $(CPUOPTIMIZATIONS)
+OPTIM_RELEASE=-O2 -fno-strict-aliasing -funroll-loops $(CPUOPTIMIZATIONS)
+  ifneq ($(ARCH),alpha)
+OPTIM_RELEASE+=-ffast-math
+  endif
+endif
 
 DO_CC=$(CC) $(CFLAGS) -c $< -o $@
 
@@ -161,7 +166,7 @@
 OBJ_GLX= builddate.c sys_linux.o vid_glx.o $(OBJ_SOUND) $(OBJ_CD) $(OBJ_COMMON)
 
 LDFLAGS_UNIXCOMMON=-lm
-LDFLAGS_UNIXCL=-L$(UNIX_X11LIBPATH) -lX11 -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
+LDFLAGS_UNIXCL=-L$(X11BASE)/lib -lX11 -lXext -lXxf86dga -lXxf86vm $(LIB_SOUND)
 
 LDFLAGS_UNIXSDL=`$(SDL_CONFIG) --libs`
 EXE_UNIXCL=darkplaces-glx
@@ -359,28 +364,28 @@
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
 	$(DO_CC) $(CFLAGS_SDL)
