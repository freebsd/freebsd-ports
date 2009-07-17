--- common.mak.orig	2009-07-12 03:27:25.000000000 +0400
+++ common.mak	2009-07-16 22:27:20.000000000 +0400
@@ -8,7 +8,6 @@
 VERSION = 0.2.1
 
 # These may be overridden by config.mak
-DATADIR = data
 #UNIVERSAL = 1
 #UNIXSTYLE = 1
 
@@ -43,8 +42,8 @@
 ifeq ($(MACHINE),SunOS)
 LIBS += -lnsl -lsocket -lresolv
 endif
-FLAGS_SDL = $(shell sdl-config --cflags)
-LIBS_SDL = $(shell sdl-config --libs) -lSDL_image -lSDL_ttf
+FLAGS_SDL = $(shell ${SDL_CONFIG} --cflags)
+LIBS_SDL = $(shell ${SDL_CONFIG} --libs) -lSDL_image -lSDL_ttf
 ifeq ($(NOSOUND),)
 LIBS_SDL += -lSDL_mixer
 endif
@@ -60,7 +59,7 @@
 ifeq ($(MACHINE),Windows)
 LIBS_GL = -lopengl32
 else
-LIBS_GL = -L/usr/X11/lib/ -lGL
+LIBS_GL = -L${LOCALBASE}/lib/ -lGL
 endif
 endif
 
@@ -68,12 +67,6 @@
 
 CFLAGS += -Wall
 
-ifeq ($(DEBUG),1)
-CFLAGS += -g -O0
-else
-CFLAGS += -O2
-endif
-
 LDFLAGS += $(CFLAGS)
 CFLAGS += $(FLAGS_GL) $(INCLUDES)
 ifeq ($(MACHINE),Windows)
