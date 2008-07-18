--- config.mk.orig	2007-07-14 20:39:41.000000000 +0200
+++ config.mk	2008-07-13 15:38:45.000000000 +0200
@@ -1,9 +1,9 @@
 # Customize to fit your system
 
 # paths
-PREFIX      = /usr/local
+PREFIX     ?= /usr/local
 BINDIR      = ${PREFIX}/bin
-MANDIR      = ${PREFIX}/share/man
+MANDIR      = ${PREFIX}/man
 MAN1DIR     = ${MANDIR}/man1
 DOCDIR      = ${PREFIX}/share/doc/ii
 
@@ -22,6 +22,6 @@
 #CFLAGS      = -g ${INCLUDES} -DVERSION=\"${VERSION}\"
 
 # compiler
-CC          = cc
-CFLAGS      = -g -O0 -W -Wall ${INCLUDES} -DVERSION=\"${VERSION}\"
-LDFLAGS     = ${LIBS}
+CC         ?= cc
+CFLAGS     += -g -O0 -W -Wall ${INCLUDES} -DVERSION=\"${VERSION}\"
+LDFLAGS    += ${LIBS}
