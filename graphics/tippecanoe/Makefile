PORTNAME=	tippecanoe
DISTVERSION=	2.26.1
CATEGORIES=	graphics

MAINTAINER=	darcy@dbitech.ca
COMMENT=	Builds vector tilesets from large (or small) collections GEO features
WWW=		https://github.com/felt/tippecanoe

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
BUILD_DEPENDS=	bash:shells/bash

USES=		gmake
USE_GITHUB=	yes

GH_ACCOUNT=	felt

PLIST_FILES=	bin/tile-join bin/tippecanoe bin/tippecanoe-decode \
		bin/tippecanoe-enumerate bin/tippecanoe-json-tool \
		man/man1/tippecanoe.1.gz

.include <bsd.port.options.mk>

# Suppress a clang-16 error on 32-bit arch:
#  non-constant-expression cannot be narrowed from type 'uint64_t'
.if ${ARCH} == i386
CXXFLAGS+=	-Wno-narrowing
.endif

do-install:
.for file in tile-join tippecanoe tippecanoe-decode tippecanoe-enumerate tippecanoe-json-tool
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR$}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/man/tippecanoe.1 ${STAGEDIR}${PREFIX}/man/man1/tippecanoe.1

.include <bsd.port.mk>
