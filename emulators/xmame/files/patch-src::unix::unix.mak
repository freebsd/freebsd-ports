--- src/unix/unix.mak.orig	Wed Feb 12 05:13:26 2003
+++ src/unix/unix.mak	Wed Feb 12 10:04:04 2003
@@ -31,7 +31,7 @@
 LIBS.macosx	   = -framework CoreAudio
 #LIBS.openbsd       = -lossaudio
 LIBS.nto	   = -lsocket -lasound
-LIBS.beos          = `sdl-config --libs`
+LIBS.beos          = `$(SDL_CONFIG) --libs`
 
 ##############################################################################
 # **** Display dependent settings.
@@ -219,8 +219,8 @@
 endif
 
 ifdef SOUND_SDL
-CONFIG  += -DSYSDEP_DSP_SDL `sdl-config --cflags`
-MY_LIBS += `sdl-config --libs`
+CONFIG  += -DSYSDEP_DSP_SDL `$(SDL_CONFIG) --cflags`
+MY_LIBS += `$(SDL_CONFIG) --libs`
 endif
 
 ifdef SOUND_WAVEOUT
