# New ports collection makefile for:    CMUCL
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#
#

PORTNAME=	cmucl
PORTVERSION=	18b
CATEGORIES=	lang
MASTER_SITES=	http://www2.cons.org:8000/freebsd-distfiles/ \
		ftp://ftp2.cons.org/pub/languages/lisp/cmucl/release/ \
		http://www2.cons.org:8000/ftp-area/cmucl/release/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cracauer
DISTNAME=	cmucl-18b.x86.freebsd22
EXTRACT_SUFX=	.tgz

MAINTAINER= 	cracauer@cons.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MAN1=		lisp.1 cmucl.1

do-install:
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/bin/lisp ${PREFIX}/bin
	-${MKDIR} ${PREFIX}/lib/cmucl
	(cd ${WRKDIR} && tar fc - lib) | (cd ${PREFIX}/lib/cmucl && tar fx -)
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/man/cmucl.1 \
		${PREFIX}/man/man1
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/man/lisp.1 \
		${PREFIX}/man/man1

.include <bsd.port.mk>
