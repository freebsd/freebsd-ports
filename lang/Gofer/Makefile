# New ports collection makefile for:	gofer
# Version required:     2.30
# Date created:         Wed Feb  1 01:51:59 PST 1995
# Whom:                 hsu
#
# $FreeBSD$
#

DISTNAME=	gofer230a
PKGNAME=	gofer-2.30a
CATEGORIES=	lang
MASTER_SITES=	ftp://cs.nott.ac.uk/nott-fp/languages/haskell/gofer/

MAINTAINER=	hsu@FreeBSD.org

WRKSRC=		${WRKDIR}/src
LIBDIR=		${PREFIX}/lib/Gofer
MAN1=		gofer.1

do-install:
	${MKDIR} ${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/*.prelude ${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/src/prelude.h ${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/src/gofc.h ${LIBDIR}
	/usr/bin/perl -pi -e "s|#include \"prelude.h\"|#include \"${LIBDIR}/prelude.h\"|" ${LIBDIR}/gofc.h
	${INSTALL_DATA} ${WRKDIR}/src/runtime.o ${LIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/gofer ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/goferc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/src/gofer ${LIBDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/src/gofc ${LIBDIR}
	${INSTALL_MAN} ${WRKDIR}/docs/gofer.1 ${PREFIX}/man/man1
	${MKDIR} ${LIBDIR}/docs
	${INSTALL_DATA} ${WRKDIR}/docs/* ${LIBDIR}/docs

.include <bsd.port.mk>
