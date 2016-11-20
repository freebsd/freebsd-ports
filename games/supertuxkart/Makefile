# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	supertuxkart
PORTVERSION=	0.9.2
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
		libfreetype.so:print/freetype2

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	fails to build: invokes x86 asm

USES=		alias cmake compiler:c++11-lib dos2unix gettext \
		gmake jpeg openal:al pkgconfig tar:xz
USE_GL=		gl glu
USE_SDL=	sdl
USE_XORG=	x11 xext sm ice
DOS2UNIX_FILES=	lib/irrlicht/source/Irrlicht/Makefile \
		lib/irrlicht/source/Irrlicht/COpenGLExtensionHandler.h
CMAKE_ARGS=	-DUSE_WIIUSE=NO \
		-DUSE_XRANDR=NO

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDATA=	*

CXXFLAGS+=	-DNO_IRR_COMPILE_WITH_JOYSTICK_EVENTS_ \
		-D__FREE_BSD_

OPTIONS_DEFINE=	FRIBIDI XRANDR
OPTIONS_DEFAULT=FRIBIDI XRANDR

FRIBIDI_DESC=		Support for right-to-left languages
FRIBIDI_CMAKE_BOOL=	USE_FRIBIDI
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi

XRANDR_DESC=		Use xrandr instead of vidmode
XRANDR_CMAKE_BOOL=	USE_XRANDR
XRANDR_USE=		XORG=xrandr
XRANDR_USE_OFF=		XORG=xxf86vm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6/include|${LOCALBASE}/include|' \
		${WRKSRC}/lib/irrlicht/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|Icon=.*|Icon=${PREFIX}/share/icons/hicolor/128x128/apps/supertuxkart.png|' \
		${WRKSRC}/data/${PORTNAME}.desktop

.include <bsd.port.mk>
