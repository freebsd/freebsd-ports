
$FreeBSD$

--- GUI.mak.orig
+++ GUI.mak
@@ -8,14 +8,14 @@
 
 PROGNAME=glBSPX
 
-FLTK_CFLAGS=-I/usr/local/lib
+FLTK_CFLAGS=-I${X11BASE}/include
 FLTK_LIBS=-lfltk_images -lfltk -lX11 -lXext -lpng -ljpeg
 
-CC=gcc
-CXX=g++
-CFLAGS=-O2 -Wall -DGLBSP_GUI -DUNIX -DINLINE_G=inline $(FLTK_CFLAGS)
+CC?=gcc
+CXX?=g++
+CFLAGS+=-O2 -Wall -DGLBSP_GUI -DUNIX -DINLINE_G=inline $(FLTK_CFLAGS)
 CXXFLAGS=$(CFLAGS)
-LDFLAGS=-L/usr/X11R6/lib
+LDFLAGS=-L${X11BASE}/lib -L${LOCALBASE}/lib
 LIBS=-lm $(FLTK_LIBS)
 
 OBJS=$(SYSDIR)/main.o     \
