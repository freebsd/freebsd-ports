PORTNAME=	nanosvg
DISTVERSION=	g20221204
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple C++ header-only SVG parser
WWW=		https://github.com/memononen/nanosvg

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	memononen
GH_TAGNAME=	9da543e

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/nanosvg.h include/nanosvgrast.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/nanosvg.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/nanosvgrast.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
