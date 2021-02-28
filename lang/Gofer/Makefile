# Created by: hsu
# $FreeBSD$

PORTNAME=	gofer
PORTVERSION=	2.30b
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://web.cecs.pdx.edu/~mpj/goferarc/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Lazy functional language

DEPRECATED=	Old, unmaintained language
EXPIRATION_DATE=2021-03-28

WRKSRC=		${WRKDIR}/src

USES=		readline

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DUSE_READLINE=1" \
		LDFLAGS="${LDFLAGS} -lm -lreadline" OPTFLAGS=""

DOCSDIR=	${PREFIX}/share/doc/Gofer
LIBDIR=		${PREFIX}/lib/Gofer

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKDIR}/scripts/gofer \
		${WRKDIR}/scripts/goferc

do-install:
	${MKDIR} ${STAGEDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/*.prelude ${STAGEDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/src/prelude.h ${STAGEDIR}${LIBDIR}
	${REINPLACE_CMD} -e "s|#include \"prelude.h\"|#include \"${LIBDIR}/prelude.h\"|" ${WRKDIR}/src/gofc.h
	${INSTALL_DATA} ${WRKDIR}/src/gofc.h ${STAGEDIR}${LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/src/runtime.o ${STAGEDIR}${LIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/gofer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/goferc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/src/gofer ${STAGEDIR}${LIBDIR}
	${INSTALL_PROGRAM} ${WRKDIR}/src/gofc ${STAGEDIR}${LIBDIR}
	${INSTALL_MAN} ${WRKDIR}/docs/gofer.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/docs/* ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${LIBDIR}/runtime.o

.include <bsd.port.mk>
