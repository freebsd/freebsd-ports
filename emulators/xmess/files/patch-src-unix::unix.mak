--- src/unix/unix.mak.orig	Sun Jul 28 18:47:11 2002
+++ src/unix/unix.mak	Sun Jul 28 18:54:26 2002
@@ -45,20 +45,20 @@
 
 # svga and ggi also use $(X11LIB) since that's where zlib often is
 LIBS.x11        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext 
-LIBS.svgalib    = $(X11LIB) -lvga -lvgagl
+LIBS.svgalib    = $(LOCALBASE)/lib -lvga -lvgagl
 LIBS.ggi        = $(X11LIB) -lggi
-LIBS.xgl        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext $(GLLIBS) -ljpeg
+LIBS.xgl        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext $(GLLIBS) -L$(LOCALBASE)/lib -ljpeg
 LIBS.xfx        = $(X11LIB) $(JOY_X11_LIBS) -lX11 -lXext -lglide2x
 LIBS.svgafx     = $(X11LIB) -lvga -lvgagl -lglide2x
 LIBS.openstep	= -framework AppKit
-LIBS.SDL	= `sdl-config --libs`
+LIBS.SDL	= `$(SDL_CONFIG) --libs`
 LIBS.photon2	= -L/usr/lib -lph -lphrender
 
 CFLAGS.x11      = $(X11INC) $(JOY_X11_CFLAGS)
-CFLAGS.xgl      = $(X11INC) $(JOY_X11_CFLAGS) $(GLCFLAGS)
+CFLAGS.xgl      = -DGLU_VERSION_1_2 $(X11INC) $(JOY_X11_CFLAGS) $(GLCFLAGS) -I$(LOCALBASE)/include $(PTHREAD_CFLAGS)
 CFLAGS.xfx      = $(X11INC) $(JOY_X11_CFLAGS) -I/usr/include/glide
 CFLAGS.svgafx   = -I/usr/include/glide
-CFLAGS.SDL      = -D_REENTRANT
+CFLAGS.SDL      = $(X11INC) `$(SDL_CONFIG) --cflags`
 CFLAGS.photon2	=
 
 INST.x11        = doinstall
