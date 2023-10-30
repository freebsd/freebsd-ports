PORTNAME=	lzsa
DISTVERSION=	1.4.1
CATEGORIES=	archivers emulators

MAINTAINER=	makc@FreeBSD.org
COMMENT=	LZSA compression utility

WWW=		https://github.com/emmanuel-marty/lzsa

LICENSE=	CC0-1.0 ZLIB
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSE.cc0.md
LICENSE_FILE_ZLIB=	${WRKSRC}/LICENSE.zlib.md

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	emmanuel-marty

PLIST_FILES=	bin/lzsa
PORTDOCS=	BlockFormat_LZSA1.md BlockFormat_LZSA2.md README.md \
		StreamFormat.md pareto_graph.png

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/lzsa ${STAGEDIR}/${PREFIX}/bin

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} && \
	${INSTALL_DATA} ${PORTDOCS:C,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
