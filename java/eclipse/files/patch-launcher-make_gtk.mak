--- plugins/platform-launcher/library/gtk/make_gtk.mak.orig	Sun Jun 13 22:31:21 2004
+++ plugins/platform-launcher/library/gtk/make_gtk.mak	Sun Jun 13 22:31:38 2004
@@ -26,7 +26,7 @@
 # Define the object modules to be compiled and flags.
 OBJS = eclipse.o eclipseUtil.o eclipseShm.o eclipseGtk.o
 EXEC = $(PROGRAM_OUTPUT)
-LIBS = `pkg-config ?libs-only-L gtk+-2.0` -lgtk-x11-2.0 -lgdk_pixbuf-2.0
+LIBS = `pkg-config --libs-only-L gtk+-2.0` -lgtk-x11-2.0 -lgdk_pixbuf-2.0
 
 CFLAGS = -O -s \
 	-DMOZILLA_FIX \
