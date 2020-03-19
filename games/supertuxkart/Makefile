# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	supertuxkart
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	SF/supertuxkart/SuperTuxKart/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free 3D kart racing game

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfribidi.so:converters/fribidi \
		libraqm.so:print/libraqm \
		libsqlite3.so:databases/sqlite3

BROKEN_i386=	does not build (error: this directive must appear between .cfi_startproc and .cfi_endproc directives)

USES=		alias cmake compiler:c++11-lib gettext gl \
		jpeg openal:al pkgconfig sdl tar:xz xorg
USE_GL=		gl glu glew
USE_SDL=	sdl
USE_XORG=	x11 xrandr
CMAKE_OFF=	USE_WIIUSE BUILD_RECORDER \
		USE_SYSTEM_ENET USE_SYSTEM_SQUISH
CMAKE_ON=	USE_SYSTEM_GLEW

PORTDATA=	*

CXXFLAGS+=	-DNO_IRR_COMPILE_WITH_JOYSTICK_EVENTS_ \
		-D__FREE_BSD_

OPTIONS_DEFINE=	NETTLE WAYLAND
OPTIONS_DEFAULT=WAYLAND

NETTLE_DESC=		Use Nettle instead of OpenSSL for cryptography
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NETTLE_USES_OFF=	ssl
NETTLE_CMAKE_BOOL_OFF=	USE_CRYPTO_OPENSSL

WAYLAND_CMAKE_BOOL=	ENABLE_WAYLAND_DEVICE
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland \
			libxkbcommon.so:x11/libxkbcommon
WAYLAND_USE=		GL=egl

# make sure that bundled libraries are not used
post-extract:
.for bundled in glew jpeglib libpng libraqm wiiuse zlib
	@${RM} -rf ${WRKSRC}/lib/${bundled}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/include|${LOCALBASE}/include|' \
		${WRKSRC}/lib/irrlicht/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|Icon=.*|Icon=${PREFIX}/share/icons/hicolor/128x128/apps/supertuxkart.png|' \
		${WRKSRC}/data/${PORTNAME}.desktop

.include <bsd.port.mk>
