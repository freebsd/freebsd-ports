PORTNAME=	nanosvg
DISTVERSION=	20241219 # use date because this tiny library is unlikely to ever have releases
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
GH_TAGNAME=	ea6a6ac

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/nanosvg.h include/nanosvgrast.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/nanosvg.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/src/nanosvgrast.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
