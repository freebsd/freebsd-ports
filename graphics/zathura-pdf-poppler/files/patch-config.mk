--- config.mk.orig	2012-05-18 21:08:57.000000000 +0200
+++ config.mk	2012-05-18 21:09:17.000000000 +0200
@@ -20,10 +20,7 @@
 GIRARA_LIB ?= $(shell pkg-config --libs girara-gtk2)
 
 ZATHURA_INC ?= $(shell pkg-config --cflags zathura)
-PLUGINDIR ?= $(shell pkg-config --variable=plugindir zathura)
-ifeq (,${PLUGINDIR})
 PLUGINDIR = ${PREFIX}/lib/zathura
-endif
 
 INCS = ${GTK_INC} ${PDF_INC} ${ZATHURA_INC} ${GIRARA_INC}
 LIBS = ${GIRARA_LIB} ${GTK_LIB} ${PDF_LIB}
