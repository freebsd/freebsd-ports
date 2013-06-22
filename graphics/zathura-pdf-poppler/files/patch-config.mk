--- config.mk.orig	2013-05-12 23:21:06.000000000 +0200
+++ config.mk	2013-06-21 13:16:15.646661467 +0200
@@ -12,7 +12,7 @@
 
 # paths
 PREFIX ?= /usr
-LIBDIR ?= ${PREFIX}/lib
+LIBDIR = ${PREFIX}/lib
 DESKTOPPREFIX ?= ${PREFIX}/share/applications
 
 # libs
@@ -26,10 +26,7 @@
 GIRARA_LIB ?= $(shell pkg-config --libs girara-gtk${ZATHURA_GTK_VERSION})
 
 ZATHURA_INC ?= $(shell pkg-config --cflags zathura)
-PLUGINDIR ?= $(shell pkg-config --variable=plugindir zathura)
-ifeq (,${PLUGINDIR})
 PLUGINDIR = ${LIBDIR}/zathura
-endif
 
 INCS = ${CAIRO_INC} ${PDF_INC} ${ZATHURA_INC} ${GIRARA_INC}
 LIBS = ${GIRARA_LIB} ${CAIRO_LIB} ${PDF_LIB}
