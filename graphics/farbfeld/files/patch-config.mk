--- config.mk.orig	2018-04-11 10:59:06 UTC
+++ config.mk
@@ -9,10 +9,10 @@ CPPFLAGS = -D_DEFAULT_SOURCE
 
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
