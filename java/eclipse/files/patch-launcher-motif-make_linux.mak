--- plugins/platform-launcher/library/motif/make_linux.mak.orig	Sun Jun 20 12:51:29 2004
+++ plugins/platform-launcher/library/motif/make_linux.mak	Sun Jun 20 12:53:01 2004
@@ -21,7 +21,7 @@
 #    X11_HOME   - X11 includes and libraries
 #    MOTIF_HOME - Motif include and libraries if not the same as X11_HOME
 X11_HOME = /usr/X11R6
-MOTIF_HOME = /bluebird/teamswt/swt-builddir/motif21
+MOTIF_HOME = $(X11_HOME)
 
 # Define the object modules to be compiled and flags.
 OBJS = eclipse.o eclipseUtil.o eclipseShm.o eclipseMotif.o \
