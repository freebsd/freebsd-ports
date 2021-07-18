PORTNAME=	supertuxkart
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/supertuxkart/SuperTuxKart/${PORTVERSION}
DISTNAME=	SuperTuxKart-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free 3D kart racing game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libcurl.so:ftp/curl

BROKEN_FreeBSD_12_i386=	does not build (error: this directive must appear between .cfi_startproc and .cfi_endproc directives)
BROKEN_i386=	ld: error: cannot preempt symbol: alcOpenDevice

USES=		alias cmake compiler:c++11-lib pkgconfig tar:xz
CMAKE_OFF=	USE_WIIUSE \
		BUILD_RECORDER \
		USE_SYSTEM_ENET \
		USE_SYSTEM_SQUISH
CMAKE_ON=	USE_SYSTEM_GLEW

PORTDATA=	*

CXXFLAGS+=	-DNO_IRR_COMPILE_WITH_JOYSTICK_EVENTS_ \
		-D__FREE_BSD_

OPTIONS_DEFINE=	NETTLE SERVER_ONLY
OPTIONS_DEFAULT=NETTLE

NETTLE_DESC=		Use Nettle instead of OpenSSL for cryptography
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NETTLE_USES_OFF=	ssl
NETTLE_CMAKE_BOOL_OFF=	USE_CRYPTO_OPENSSL

SERVER_ONLY_DESC=	Build server only
SERVER_ONLY_CMAKE_BOOL=	SERVER_ONLY
SERVER_ONLY_LIB_DEPENDS_OFF= \
			libvorbisfile.so:audio/libvorbis \
			libogg.so:audio/libogg \
			libpng.so:graphics/png \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz
SERVER_ONLY_USES_OFF=	gettext gl jpeg openal:al sdl xorg
SERVER_ONLY_USE_OFF=	GL=gl,glu,glew SDL=sdl2 XORG=x11,xrandr

# make sure that bundled libraries are not used
post-extract:
.for bundled in glew wiiuse
	@${RM} -rf ${WRKSRC}/lib/${bundled}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|Icon=.*|Icon=${PREFIX}/share/icons/hicolor/128x128/apps/supertuxkart.png|' \
		${WRKSRC}/data/${PORTNAME}.desktop

.include <bsd.port.mk>
