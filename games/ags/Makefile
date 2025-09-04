PORTNAME=	ags
DISTVERSION=	3.6.2.12
CATEGORIES=	games
MASTER_SITES=	https://github.com/adventuregamestudio/ags/releases/download/v${PORTVERSION}/
DISTNAME=	ags_${DISTVERSION}_source

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Adventure Game Studio Engine
WWW=		https://www.adventuregamestudio.co.uk/

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++11-lang gmake localbase pkgconfig sdl tar:xz
USE_SDL=	sdl2 sound2

MAKE_ARGS=	V=1
BUILD_WRKSRC=	${WRKSRC}/Engine

PLIST_FILES=	bin/ags

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Engine/ags ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
