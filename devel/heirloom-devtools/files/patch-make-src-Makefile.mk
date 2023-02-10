--- make/src/Makefile.mk.orig	2023-01-13 17:38:46 UTC
+++ make/src/Makefile.mk
@@ -1,4 +1,4 @@
-HDRSDIR = $(PREFIX)/share/lib/make
+HDRSDIR ?= $(PREFIX)/share/lib/make
 
 OBJ = ar.o depvar.o dist.o dmake.o doname.o dosys.o files.o globals.o \
 	implicit.o macro.o main.o make.o misc.o nse.o nse_printdep.o \
