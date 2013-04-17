--- src/core.mk.orig	2013-03-21 23:45:14.000000000 +0400
+++ src/core.mk	2013-04-16 21:14:33.351621428 +0400
@@ -3,7 +3,6 @@
 APPSERVER=$(APPNAME)_server
 
 #CXXFLAGS= -ggdb3
-CXXFLAGS= -O3 -fomit-frame-pointer
 override CXXFLAGS+= -Wall -fsigned-char -fno-exceptions -fno-rtti
 
 PLATFORM= $(shell uname -s)
@@ -65,8 +64,8 @@
 CLIENT_INCLUDES= $(INCLUDES) -Iinclude
 CLIENT_LIBS= -mwindows $(STD_LIBS) -L$(WINBIN) -L$(WINLIB) -lSDL -lSDL_image -lSDL_mixer -lzlib1 -lopengl32 -lenet -lws2_32 -lwinmm
 else
-CLIENT_INCLUDES= $(INCLUDES) -I/usr/X11R6/include `sdl-config --cflags`
-CLIENT_LIBS= -Lenet/.libs -lenet -L/usr/X11R6/lib -lX11 `sdl-config --libs` -lSDL_image -lSDL_mixer -lz -lGL
+CLIENT_INCLUDES= $(INCLUDES) -I${LOCALBASE}/include `${SDL_CONFIG} --cflags`
+CLIENT_LIBS= -Lenet/.libs -lenet -L${LOCALBASE}/lib -lX11 `${SDL_CONFIG} --libs` -lSDL_image -lSDL_mixer -lz -lGL
 endif
 ifeq ($(PLATFORM),Linux)
 CLIENT_LIBS+= -lrt
