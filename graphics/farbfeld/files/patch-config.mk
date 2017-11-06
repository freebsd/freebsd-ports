--- config.mk.orig	2017-07-23 04:09:50 UTC
+++ config.mk
@@ -9,10 +9,10 @@ MANPREFIX = ${PREFIX}/man
 
 # flags
 CPPFLAGS = -D_DEFAULT_SOURCE
-CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os
-LDFLAGS  = -s
+CFLAGS   += -std=c99 -pedantic -Wall -Wextra -Os -I${LOCALBASE}/include
+LDFLAGS  = -s -L${LOCALBASE}/lib
 PNG-LDFLAGS = -lpng
 JPG-LDFLAGS = -ljpeg
 
 # compiler and linker
-CC = cc
+CC ?= cc
