# New ports collection makefile for:	gofer
# Version required:     2.30
# Date created:         Wed Feb  1 01:51:59 PST 1995
# Whom:                 hsu
#
# $Id: Makefile,v 1.7 1996/10/19 05:56:26 max Exp $
#

DISTNAME =	gofer230a
PKGNAME =	gofer-2.30a
CATEGORIES+=	lang
MASTER_SITES =	ftp://cs.nott.ac.uk/nott-fp/languages/haskell/gofer/

WRKSRC = ${WRKDIR}/src
LIBDIR = ${PREFIX}/lib/Gofer

do-install:
	${MKDIR} -p ${LIBDIR}
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
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/gofer.1
.endif
	${MKDIR} -p ${LIBDIR}/docs
	${INSTALL_DATA} ${WRKDIR}/docs/* ${LIBDIR}/docs

.include <bsd.port.mk>
