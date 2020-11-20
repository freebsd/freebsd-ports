# $FreeBSD$

PORTNAME=	raylib
DISTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	devel education

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Library to learn videogames programming

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glfw>=3.3:graphics/glfw
LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake gl localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	raysan5
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcursor xext xi xinerama xrandr xxf86vm

CMAKE_ON=	SHARED USE_EXTERNAL_GLFW
CMAKE_OFF=	BUILD_EXAMPLES BUILD_GAMES STATIC

PLIST_FILES=	include/raylib.h \
		lib/cmake/raylib/raylib-config-version.cmake \
		lib/cmake/raylib/raylib-config.cmake \
		lib/libraylib.so \
		lib/libraylib.so.${DISTVERSION} \
		lib/libraylib.so.301 \
		libdata/pkgconfig/raylib.pc

post-extract:
	# Remove bundled files.
	@${RM} -r ${WRKSRC}/src/external/glfw ${WRKSRC}/src/external/include ${WRKSRC}/src/rglfw.c

.include <bsd.port.mk>
