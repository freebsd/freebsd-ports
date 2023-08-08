--- raypaint/Makefile.SH.orig	1992-02-10 03:03:47 UTC
+++ raypaint/Makefile.SH
@@ -55,11 +55,11 @@ YFLAGS = -d
 
 #
 # If using X11, use:
-#GRAPHICSLIB = -lX11
+GRAPHICSLIB = -lX11
 
 #
 # If you are using GL, use:
-GRAPHICSLIB = -lgl_s
+#GRAPHICSLIB = -lgl_s
 
 LIBRAY = $(LIBRAYDIR)/libray.a
 LIBSHADE = $(LIBSHADEDIR)/libshade.a
