--- config.mk.orig	2016-03-15 17:46:09 UTC
+++ config.mk
@@ -18,8 +18,8 @@ LIBS = -L${PNGLIB} -L${JPGLIB} -lpng -lj
 
 # flags
 CPPFLAGS = -D_DEFAULT_SOURCE
-CFLAGS   = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
+CFLAGS   += -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
 LDFLAGS  = -s ${LIBS}
 
 # compiler and linker
-CC = cc
+CC ?= cc
