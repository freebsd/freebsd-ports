# $FreeBSD$

PORTNAME=	raylib
DISTVERSION=	2.0.0
DISTVERSIONSUFFIX=	-dev
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Library to learn videogames programming

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libglfw.so:graphics/glfw

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	raysan5
USE_LDCONFIG=	yes
USE_GL=		gl glu
USE_XORG=	ice sm x11 xcursor xext xrandr xi xinerama xxf86vm

CMAKE_ON=	SHARED USE_EXTERNAL_GLFW
CMAKE_OFF=	STATIC BUILD_EXAMPLES BUILD_GAMES

PLIST_FILES=	include/raylib.h \
		lib/libraylib.so \
		lib/libraylib.so.1 \
		lib/libraylib.so.${DISTVERSION} \
		libdata/pkgconfig/raylib.pc

post-patch: # the equivalent of https://github.com/raysan5/raylib/pull/558 for the -dev branch
	@${REINPLACE_CMD} -e 's|if(NOT glfw3_FOUND)|if(NOT glfw3_FOUND AND NOT USE_EXTERNAL_GLFW)|' ${WRKSRC}/src/CMakeLists.txt

post-extract: # remove bundled files
	@${RM} -r ${WRKSRC}/src/external/glfw ${WRKSRC}/src/external/include ${WRKSRC}/src/rglfw.c

.include <bsd.port.mk>
