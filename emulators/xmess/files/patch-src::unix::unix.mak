--- src/unix/unix.mak.orig	Fri Aug 10 07:36:22 2001
+++ src/unix/unix.mak	Wed Dec 12 11:02:58 2001
@@ -44,20 +44,20 @@
 
 # svga and ggi also use $(X11LIB) since that's where zlib often is
 LIBS.x11        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext 
-LIBS.svgalib    = $(X11LIB) -lvga -lvgagl
+LIBS.svgalib    = -L$(LOCALBASE)/lib -lvga -lvgagl
 LIBS.ggi        = $(X11LIB) -lggi
-LIBS.xgl        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext $(GLLIBS) -ljpeg
+LIBS.xgl        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext $(GLLIBS) -L$(LOCALBASE)/lib -ljpeg
 LIBS.xfx        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext -lglide2x
 LIBS.svgafx     = $(X11LIB) -lvga -lvgagl -lglide2x
 LIBS.openstep	= -framework AppKit
-LIBS.SDL	= -ldl -lSDL -lpthread -D_REENTRANT
+LIBS.SDL	= `$(SDL_CONFIG) --libs`
 LIBS.photon2	= -L/usr/lib -lph -lphrender
 
 CFLAGS.x11      = $(X11INC) $(JOY_X11_CFLAGS)
-CFLAGS.xgl      = $(X11INC) $(JOY_X11_CFLAGS) $(GLCFLAGS)
+CFLAGS.xgl      = -DGLU_VERSION_1_2 $(X11INC) $(JOY_X11_CFLAGS) $(GLCFLAGS) -I$(LOCALBASE)/include $(PTHREAD_CFLAGS)
 CFLAGS.xfx      = $(X11INC) $(JOY_X11_CFLAGS) -I/usr/include/glide
 CFLAGS.svgafx   = -I/usr/include/glide
-CFLAGS.SDL      = -D_REENTRANT
+CFLAGS.SDL      = `$(SDL_CONFIG) --cflags`
 CFLAGS.photon2	=
 
 INST.x11        = doinstall
@@ -332,7 +332,7 @@
 	
 doc/x$(TARGET)rc.dist: all src/unix/xmamerc-keybinding-notes.txt
 	./x$(TARGET).$(DISPLAY_METHOD) -noloadconfig -showconfig | \
-	 grep -v loadconfig > doc/x$(TARGET)rc.dist
+	 grep -v loadconfig | tr "\033" \# > doc/x$(TARGET)rc.dist
 	cat src/unix/xmamerc-keybinding-notes.txt >> doc/x$(TARGET)rc.dist
 	
 doc/gamelist.$(TARGET): all
@@ -341,7 +341,8 @@
 
 doc/x$(TARGET).6: all src/unix/xmame.6-1 src/unix/xmame.6-3
 	cat src/unix/xmame.6-1 > doc/x$(TARGET).6
-	./x$(TARGET).$(DISPLAY_METHOD) -manhelp >> doc/x$(TARGET).6
+	./x$(TARGET).$(DISPLAY_METHOD) -noloadconfig -manhelp | \
+	 tr "\033" \# >> doc/x$(TARGET).6
 	cat src/unix/xmame.6-3 >> doc/x$(TARGET).6
 
 install: $(INST.$(DISPLAY_METHOD)) install-man
