# New ports collection makefile for:    CMUCL
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $FreeBSD$
#
#

PORTNAME=	cmucl
PORTVERSION=	18d
CATEGORIES=	lang
MASTER_SITES=	http://www2.cons.org/freebsd-distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	cracauer
DISTNAME=	cmucl-18d-x86-FreeBSD

MAINTAINER=	cracauer@cons.org

USE_BZIP2=	YES
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
MAN1=		lisp.1 cmucl.1

do-install:
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/bin/lisp ${PREFIX}/bin
	(cd ${WRKDIR} && tar fc - lib ) | (cd ${PREFIX} && tar fx -)
	-${MKDIR} ${PREFIX}/share/doc/cmucl
	(cd ${WRKDIR} && tar fc - doc) | (cd ${PREFIX}/share && tar fx -)
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/man/man1/cmucl.1 \
		${PREFIX}/man/man1
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} ${WRKDIR}/man/man1/lisp.1 \
		${PREFIX}/man/man1

.include <bsd.port.mk>
