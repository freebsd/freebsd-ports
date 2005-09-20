--- GUI_unx.mak.orig
+++ GUI_unx.mak
@@ -8,16 +8,16 @@
 
 PROGNAME=glBSPX
 
-FLTK_PREFIX=../fltk-1.1.6
-FLTK_CFLAGS=-I$(FLTK_PREFIX) -I$(FLTK_PREFIX)/zlib
-FLTK_LIBS=-L$(FLTK_PREFIX)/lib -lfltk_images -lfltk_png -lfltk_z -lfltk_jpeg \
+FLTK_PREFIX=${X11BASE}
+FLTK_CFLAGS=-I$(FLTK_PREFIX)/include
+FLTK_LIBS=-L$(FLTK_PREFIX)/lib -lfltk_images \
           -lfltk -lX11 -lXext
 
-CC=gcc
-CXX=g++
-CFLAGS=-O2 -Wall -DGLBSP_GUI -DUNIX -DINLINE_G=inline $(FLTK_CFLAGS)
+CC?=gcc
+CXX?=g++
+CFLAGS+=-O2 -Wall -DGLBSP_GUI -DUNIX -DINLINE_G=inline $(FLTK_CFLAGS)
 CXXFLAGS=$(CFLAGS)
-LDFLAGS=-L/usr/X11R6/lib
+LDFLAGS=-L${X11BASE}/lib
 LIBS=-lm $(FLTK_LIBS)
 
 OBJS=$(SYSDIR)/main.o     \
