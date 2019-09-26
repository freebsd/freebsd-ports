# $FreeBSD$

PORTNAME=	ags
DISTVERSION=	3.4.4.1
CATEGORIES=	games
MASTER_SITES=	https://github.com/adventuregamestudio/ags/releases/download/v.${DISTVERSION}/
DISTNAME=	ags_linux_v.${DISTVERSION}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Adventure Game Studio Engine

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/License.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libaldmb.a:audio/dumb-allegro
LIB_DEPENDS=	liballeg.so:devel/allegro \
		libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis \
		libfreetype.so:print/freetype2

USES=		compiler:c++11-lang gmake localbase pkgconfig tar:xz xorg
USE_XORG=	x11

MAKE_ARGS=	V=1
BUILD_WRKSRC=	${WRKSRC}/Engine

PLIST_FILES=	bin/ags

post-patch:
	@${REINPLACE_CMD} 's|<endian.h>|<sys/endian.h>|' \
		${WRKSRC}/Common/core/endianness.h
	@${REINPLACE_CMD} -e 's|return cd_player|return 0; // cd_player|g' \
		-e 's|cd_exit|//cd_exit|g' \
		${WRKSRC}/Engine/platform/linux/acpllnx.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Engine/ags ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
