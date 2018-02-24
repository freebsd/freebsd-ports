# $FreeBSD$

PORTNAME=	raylib
DISTVERSION=	1.9.4
DISTVERSIONSUFFIX=	-dev
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	martinfilla@post.cz
COMMENT=	Library to learn videogames programming

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	raysan5
USE_LDCONFIG=	yes
USE_GL=		gl glu
USE_XORG=	ice sm x11 xcursor xext xrandr xi xinerama xxf86vm

CMAKE_ON=	SHARED_RAYLIB
CMAKE_OFF=	STATIC_RAYLIB BUILD_EXAMPLES BUILD_GAMES

PLIST_FILES=	include/raylib.h \
		lib/libraylib.so \
		lib/libraylib.so.1 \
		lib/libraylib.so.${DISTVERSION} \
		libdata/pkgconfig/raylib.pc

post-extract: # remove bundled files
	@${RM} -r ${WRKSRC}/src/external/glfw ${WRKSRC}/src/external/include ${WRKSRC}/src/rglfw.c

.include <bsd.port.mk>
