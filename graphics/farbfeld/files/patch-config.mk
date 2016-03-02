--- config.mk.orig	2016-02-19 12:59:50.769556000 -0600
+++ config.mk	2016-02-19 12:56:15.846580000 -0600
@@ -18,8 +18,8 @@
 
 # flags
 CPPFLAGS = -D_DEFAULT_SOURCE
-CFLAGS   = -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
+CFLAGS  += -std=c99 -pedantic -Wall -Os ${INCS} ${CPPFLAGS}
 LDFLAGS  = -s ${LIBS}
 
 # compiler and linker
-CC = cc
+CC ?= cc
