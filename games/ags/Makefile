# $FreeBSD$

PORTNAME=	ags
DISTVERSIONPREFIX=	v.
DISTVERSION=	3.4.1.12
CATEGORIES=	games

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

BROKEN_powerpc64=	fails to compile: cc1plus: unrecognized command line option "-std=c++11"

USE_GITHUB=	yes
GH_ACCOUNT=	adventuregamestudio

USES=		gmake localbase pkgconfig tar:xz
USE_XORG=	x11

BUILD_WRKSRC=	${WRKSRC}/Engine

MAKE_ARGS=	V=1

PLIST_FILES=	bin/ags

post-patch:
	@${REINPLACE_CMD} 's|<endian.h>|<sys/endian.h>|' \
		${WRKSRC}/Common/core/endianness.h
	@${REINPLACE_CMD} 's|HWND editor_window_handle = NULL;|HWND editor_window_handle = 0;|g' \
		${WRKSRC}/Engine/debug/debug.cpp
	@${REINPLACE_CMD} -e 's|return cd_player|return 0; // cd_player|g' \
		-e 's|cd_exit|//cd_exit|g' \
		${WRKSRC}/Engine/platform/linux/acpllnx.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Engine/ags ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
