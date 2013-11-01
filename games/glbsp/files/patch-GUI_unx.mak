--- ./GUI_unx.mak.orig	2005-09-16 02:29:39.000000000 -0300
+++ ./GUI_unx.mak	2013-11-01 20:56:43.000000000 -0200
@@ -8,16 +8,16 @@
 
 PROGNAME=glBSPX
 
-FLTK_PREFIX=../fltk-1.1.6
-FLTK_CFLAGS=-I$(FLTK_PREFIX) -I$(FLTK_PREFIX)/zlib
-FLTK_LIBS=-L$(FLTK_PREFIX)/lib -lfltk_images -lfltk_png -lfltk_z -lfltk_jpeg \
-          -lfltk -lX11 -lXext
+FLTK_PREFIX=${LOCALBASE}
+FLTK_CFLAGS=`fltk-config --use-images --cflags`
+FLTK_LIBSTMP=$(shell fltk-config --use-images --ldflags)
+FLTK_LIBS=$(subst -R,-L,$(FLTK_LIBSTMP))
 
-CC=gcc
-CXX=g++
+CC?=gcc
+CXX?=g++
 CFLAGS=-O2 -Wall -DGLBSP_GUI -DUNIX -DINLINE_G=inline $(FLTK_CFLAGS)
 CXXFLAGS=$(CFLAGS)
-LDFLAGS=-L/usr/X11R6/lib
+LDFLAGS?=-L/usr/X11R6/lib
 LIBS=-lm $(FLTK_LIBS)
 
 OBJS=$(SYSDIR)/main.o     \
