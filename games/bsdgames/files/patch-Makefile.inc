--- Makefile.inc.orig	2009-09-24 10:46:30.000000000 +0200
+++ Makefile.inc	2009-11-04 20:09:49.102229343 +0100
@@ -2,14 +2,40 @@
 # $FreeBSD: /tmp/pcvs/ports/games/bsdgames/files/patch-Makefile.inc,v 1.1 2009-11-21 22:00:33 miwi Exp $
 # $DragonFly: src/games/Makefile.inc,v 1.3 2006/10/08 16:22:34 pavalos Exp $
 
-BINDIR?=	/usr/games
+PREFIX?=	/usr/local
+BINDIR?=	${PREFIX}/bin
+SHAREDIR=	${PREFIX}/share
+MANDIR=		${PREFIX}/man/man
 FILESDIR?=	${SHAREDIR}/games
 WARNS?=		6
 
 .if defined(HIDEGAME)
-ORIGBINDIR:=	${BINDIR}
-BINDIR:=	${BINDIR}/hide
-ORIGBINGRP:=	${BINGRP}
 BINGRP=		games
 BINMODE=	550
 .endif
+
+# cribbed from DragonflyBSD build system
+
+NXCC?=		${CC}
+NXCFLAGS?=	${CFLAGS:N-mtune*:N-mcpu*:N-march*}
+
+.SUFFIXES: .nx .no
+
+# .no == native object file, for helper code when cross building.
+#
+.c.no:
+	${NXCC} ${_${.IMPSRC:T}_FLAGS} ${NXCFLAGS} -c ${.IMPSRC} -o ${.TARGET}
+
+.y.no:
+	${YACC} ${YFLAGS} ${.IMPSRC}
+	${NXCC} ${NXCFLAGS} -c y.tab.c -o ${.TARGET}
+	rm -f y.tab.c
+
+.l.no:
+	${LEX} ${LFLAGS} -o${.TARGET}.c ${.IMPSRC}
+	${NXCC} ${NXCFLAGS} -c ${.TARGET}.c -o ${.TARGET}
+	rm -f ${.TARGET}.c
+
+.no.nx .c.nx:
+	${NXCC} ${_${.IMPSRC:T}_FLAGS} ${NXCFLAGS} ${NXLDFLAGS} ${.IMPSRC} \
+	    ${NXLDLIBS} -o ${.TARGET}
