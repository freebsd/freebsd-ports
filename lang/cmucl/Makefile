# New ports collection makefile for:    CMUCL
# Version required:     18a, build 19970824
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $Id: Makefile,v 1.5 1997/10/06 08:33:05 cracauer Exp $
#
#

DISTNAME=	18a-FreeBSD_22
PKGNAME=	cmucl-18a
CATEGORIES=	lang
MASTER_SITES=	http://www2.cons.org:8000/freebsd-distfiles/ \
		ftp://ftp2.cons.org/pub/languages/lisp/cmucl/binaries/ \
		http://www2.cons.org:8000/ftp-area/cmucl/binaries/

MAINTAINER= 	cracauer@cons.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MAN1=		lisp.1 cmucl.1

do-install:
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/bin/lisp ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/lib/cmucl
	(cd ${WRKDIR} && tar fc - lib) | (cd ${PREFIX}/lib/cmucl && tar fx -)
	-${RMDIR} ${PREFIX}/lib/cmucl/lib/subsystems
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/README \
		${PREFIX}/lib/cmucl
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/man/man1/cmucl.1 \
		${PREFIX}/man/man1
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/man/man1/lisp.1 \
		${PREFIX}/man/man1

.include <bsd.port.mk>
