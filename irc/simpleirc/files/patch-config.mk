--- config.mk.orig	2008-12-24 21:33:04.000000000 +0100
+++ config.mk	2008-12-24 21:34:33.000000000 +0100
@@ -4,17 +4,17 @@
 # Customize below to fit your system
 
 # paths
-PREFIX = /usr/local
-MANPREFIX = ${PREFIX}/share/man
+PREFIX ?= /usr/local
+MANPREFIX = ${PREFIX}/man
 
 # includes and libs
 INCS = -I. -I/usr/include
 LIBS = -L/usr/lib -lc
 
 # flags
-CPPFLAGS = -DVERSION=\"${VERSION}\" -D_GNU_SOURCE
-CFLAGS = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
-LDFLAGS = -s ${LIBS}
+CPPFLAGS += -DVERSION=\"${VERSION}\" -D_GNU_SOURCE
+CFLAGS += -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
+LDFLAGS += -s ${LIBS}
 
 # compiler and linker
-CC = cc
+CC ?= cc
