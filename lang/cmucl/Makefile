# New ports collection makefile for:    CMUCL
# Version required:     18a
# Date created:         Jul, 15, 1997
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $Id: Makefile,v 1.5 1997/07/15 13:35:10 cracauer Exp $
#
#

DISTNAME=	cmucl-18a.x86.FreeBSD21
PKGNAME=	cmucl-18a
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp2.cons.org/pub/languages/lisp/cmucl/binaries/

MAINTAINER= 	cracauer@cons.org

NO_CONFIGURE=	yes
NO_BUILD=	yes
MAN1=		lisp.1 cmucl.1

do-install:
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} work/bin/lisp ${PREFIX}/bin
	-$(MKDIR) ${PREFIX}/lib/cmucl
	(cd work && tar fc - lib) | (cd ${PREFIX}/lib/cmucl && tar fx -)
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} work/README.1st \
		${PREFIX}/lib/cmucl
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} work/man/man1/cmucl.1 \
		${PREFIX}/man/man1
	${INSTALL} -c -o ${BINOWN} -g ${BINGRP} work/man/man1/lisp.1 \
		${PREFIX}/man/man1

.include <bsd.port.mk>

