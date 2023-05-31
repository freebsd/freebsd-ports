PORTNAME=	tippecanoe
DISTVERSION=	2.6.3
CATEGORIES=	graphics

MAINTAINER=	darcy@dbitech.ca
COMMENT=	Builds vector tilesets from large (or small) collections GEO features
WWW=		https://github.com/felt/tippecanoe

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	felt

PLIST_FILES=	bin/tile-join bin/tippecanoe bin/tippecanoe-decode \
 		bin/tippecanoe-enumerate bin/tippecanoe-json-tool \
		man/man1/tippecanoe.1.gz

do-install:
.for file in tile-join tippecanoe tippecanoe-decode tippecanoe-enumerate tippecanoe-json-tool
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR$}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/tippecanoe.1 ${STAGEDIR}${PREFIX}/man/man1/tippecanoe.1

.include <bsd.port.mk>
