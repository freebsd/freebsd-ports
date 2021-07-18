PORTNAME=	minimp3
PORTVERSION=	g20210120
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ single-header, minimalistic library for decoding MP3

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	lieff
GH_TAGNAME=	ef9e212

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/minimp3.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/minimp3.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
