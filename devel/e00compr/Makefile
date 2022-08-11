PORTNAME=	e00compr
PORTVERSION=	1.0.1
CATEGORIES=	devel
MASTER_SITES=	http://avce00.maptools.org/dl/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library to Read/Write Compressed E00 Files

OPTIONS_DEFINE=	DOCS

USES=		gmake
WRKSRC=		${WRKDIR}/${DISTNAME}
PLIST_FILES=	bin/e00conv include/e00compr.h \
		lib/e00compr.a
PORTDOCS=	e00compr.html
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e00conv ${STAGEDIR}${PREFIX}/bin/e00conv
	${INSTALL_DATA} ${WRKSRC}/e00compr.h ${STAGEDIR}${PREFIX}/include/e00compr.h
	${INSTALL_DATA} ${WRKSRC}/e00compr.a ${STAGEDIR}${PREFIX}/lib/e00compr.a
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/e00compr.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
