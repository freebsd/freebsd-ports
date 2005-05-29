--- features/org.eclipse.platform.launchers/library/gtk/make_freebsd.mak.orig	Sun Apr 17 20:24:58 2005
+++ features/org.eclipse.platform.launchers/library/gtk/make_freebsd.mak	Sun Apr 17 20:25:45 2005
@@ -26,7 +26,7 @@
 CC=gcc
 OBJS = eclipse.o eclipseUtil.o eclipseShm.o eclipseConfig.o eclipseGtk.o
 EXEC = $(PROGRAM_OUTPUT)
-LIBS = `pkg-config --libs-only-L gtk+-2.0` -lgtk-x11-2.0 -lgdk_pixbuf-2.0 -lgobject-2.0 -lgdk-x11-2.0
+LIBS = `pkg-config --libs gtk+-2.0`
 CFLAGS = -O -s \
 	-fpic \
 	-DMOZILLA_FIX \
