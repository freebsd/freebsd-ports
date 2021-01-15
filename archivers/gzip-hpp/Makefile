# $FreeBSD$

PORTNAME=	gzip-hpp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-1
DISTVERSIONSUFFIX=	-g7546b35
CATEGORIES=	archivers devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for gzip compression and decompression

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes
GH_ACCOUNT=	mapbox

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/gzip/compress.hpp \
		include/gzip/config.hpp \
		include/gzip/decompress.hpp \
		include/gzip/utils.hpp \
		include/gzip/version.hpp

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} gzip ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
