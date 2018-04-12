--- config.mk.orig	2018-04-11 10:59:06 UTC
+++ config.mk
@@ -5,14 +5,14 @@ VERSION = 4
 
 # paths
 PREFIX = /usr/local
-MANPREFIX = $(PREFIX)/share/man
+MANPREFIX = $(PREFIX)/man
 
 # flags
 CPPFLAGS = -D_DEFAULT_SOURCE
-CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os
-LDFLAGS  = -s
+CFLAGS   += -std=c99 -pedantic -Wall -Wextra -Os -I${LOCALBASE}/include
+LDFLAGS  = -s -L${LOCALBASE}/lib
 PNG-LDLIBS = -lpng
 JPG-LDLIBS = -ljpeg
 
 # compiler and linker
-CC = cc
+CC ?= cc
