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
@@ -248,27 +248,20 @@
 ifdef JOY_PS2
 CONFIG += -DPS2_JOYSTICK
 endif
+
 ifdef JOY_USB
 CONFIG += -DUSB_JOYSTICK
-ifeq ($(ARCH), netbsd)
 ifeq ($(shell test -f /usr/include/usbhid.h && echo have_usbhid), have_usbhid)
 CONFIG += -DHAVE_USBHID_H
 MY_LIBS += -lusbhid
 else
-MY_LIBS += -lusb
-endif
-else
-ifeq ($(ARCH), freebsd)
-ifeq ($(shell test -f /usr/include/libusbhid.h && echo have_usbhid), have_usbhid)
-CONFIG += -DHAVE_USBHID_H
+ifeq ($(shell test -f /usr/include/libusbhid.h && echo have_libusbhid), have_libusbhid)
+CONFIG += -DHAVE_LIBUSBHID_H
 MY_LIBS += -lusbhid
-else
-MY_LIBS += -lusb
+endif
 endif
 else
 MY_LIBS += -lusb
-endif
-endif
 endif
 
 ifdef EFENCE
