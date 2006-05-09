# New ports collection makefile for:	gofer
# Date created:         Wed Feb  1 01:51:59 PST 1995
# Whom:                 hsu
#
# $FreeBSD$
#

PORTNAME=	gofer
PORTVERSION=	2.30b
CATEGORIES=	lang
MASTER_SITES=	http://www.cse.ogi.edu/~mpj/goferarc/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A lazy functional language

WRKSRC=		${WRKDIR}/src

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DUSE_READLINE=1" \
		LDFLAGS="${LDFLAGS} -lm -lreadline" OPTFLAGS=""

DOCSDIR=	${PREFIX}/share/doc/Gofer
LIBDIR=		${PREFIX}/lib/Gofer
MAN1=		gofer.1

do-install:
	@${MKDIR} ${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/*.prelude ${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/src/prelude.h ${LIBDIR}
	${REINPLACE_CMD} -e "s|#include \"prelude.h\"|#include \"${LIBDIR}/prelude.h\"|" ${WRKDIR}/src/gofc.h
	${INSTALL_DATA} ${WRKDIR}/src/gofc.h ${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/src/runtime.o ${LIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/gofer ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/goferc ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/src/gofer ${LIBDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/src/gofc ${LIBDIR}
	${INSTALL_MAN} ${WRKDIR}/docs/gofer.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
