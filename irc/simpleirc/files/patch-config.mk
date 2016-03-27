--- config.mk.orig	2013-06-16 06:03:32 UTC
+++ config.mk
@@ -4,17 +4,17 @@ VERSION = 1.2
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
