--- config.mk.orig	2012-06-09 23:37:36.000000000 +0200
+++ config.mk	2012-08-20 18:26:30.000000000 +0200
@@ -11,7 +11,7 @@
 
 # paths
 PREFIX ?= /usr
-LIBDIR ?= ${PREFIX}/lib
+LIBDIR = ${PREFIX}/lib
 
 # libs
 CAIRO_INC ?= $(shell pkg-config --cflags cairo)
@@ -27,10 +27,7 @@
 GIRARA_LIB ?= $(shell pkg-config --libs girara-gtk2)
 
 ZATHURA_INC ?= $(shell pkg-config --cflags zathura)
-PLUGINDIR ?= $(shell pkg-config --variable=plugindir zathura)
-ifeq (,${PLUGINDIR})
 PLUGINDIR = ${LIBDIR}/zathura
-endif
 
 INCS = ${GIRARA_INC} ${GLIB_INC} ${DJVU_INC} ${ZATHURA_INC}
 LIBS = ${GIRARA_LIB} ${GLIB_LIB} ${DJVU_LIB}
