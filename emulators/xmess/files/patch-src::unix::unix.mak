--- src/unix/unix.mak.orig	Mon Dec 31 09:19:03 2001
+++ src/unix/unix.mak	Thu Oct 31 15:25:37 2002
@@ -51,14 +51,14 @@
 LIBS.xfx        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext -lglide2x
 LIBS.svgafx     = $(X11LIB) -lvga -lvgagl -lglide2x
 LIBS.openstep	= -framework AppKit
-LIBS.SDL	= `sdl-config --libs`
+LIBS.SDL	= $(X11LIB) `$(SDL_CONFIG) --libs`
 LIBS.photon2	= -L/usr/lib -lph -lphrender
 
 CFLAGS.x11      = $(X11INC) $(JOY_X11_CFLAGS)
 CFLAGS.xgl      = $(X11INC) $(JOY_X11_CFLAGS) $(GLCFLAGS)
 CFLAGS.xfx      = $(X11INC) $(JOY_X11_CFLAGS) -I/usr/include/glide
 CFLAGS.svgafx   = -I/usr/include/glide
-CFLAGS.SDL      = -D_REENTRANT
+CFLAGS.SDL      = $(X11INC) `$(SDL_CONFIG) --cflags` -D_REENTRANT
 CFLAGS.photon2	=
 
 INST.x11        = doinstall
@@ -210,8 +210,17 @@
 endif
 ifdef JOY_USB
 CONFIG += -DUSB_JOYSTICK
+ifeq ($(ARCH), freebsd)
+ifeq ($(shell test -f /usr/include/libusbhid.h && echo have_usbhid), have_usbhid)
+CONFIG += -DHAVE_USBHID_H
+MY_LIBS += -lusbhid
+else
 MY_LIBS += -lusb
 endif
+else
+MY_LIBS += -lusb
+endif
+endif
 
 ifdef EFENCE
 MY_LIBS += -lefence
@@ -340,7 +349,7 @@
 	
 doc/x$(TARGET)rc.dist: all src/unix/xmamerc-keybinding-notes.txt
 	./x$(TARGET).$(DISPLAY_METHOD) -noloadconfig -showconfig | \
-	 grep -v loadconfig > doc/x$(TARGET)rc.dist
+	 grep -v loadconfig | tr "\033" \# > doc/x$(TARGET)rc.dist
 	cat src/unix/xmamerc-keybinding-notes.txt >> doc/x$(TARGET)rc.dist
 	
 doc/gamelist.$(TARGET): all
@@ -349,7 +358,8 @@
 
 doc/x$(TARGET).6: all src/unix/xmame.6-1 src/unix/xmame.6-3
 	cat src/unix/xmame.6-1 > doc/x$(TARGET).6
-	./x$(TARGET).$(DISPLAY_METHOD) -manhelp >> doc/x$(TARGET).6
+	./x$(TARGET).$(DISPLAY_METHOD) -noloadconfig -manhelp | \
+	 tr "\033" \# >> doc/x$(TARGET).6
 	cat src/unix/xmame.6-3 >> doc/x$(TARGET).6
 
 install: $(INST.$(DISPLAY_METHOD)) install-man
