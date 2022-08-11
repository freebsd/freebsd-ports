PORTNAME=	raylib
DISTVERSION=	4.0.0
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

CMAKE_ON=	BUILD_SHARED_LIBS USE_EXTERNAL_GLFW
CMAKE_OFF=	BUILD_EXAMPLES BUILD_GAMES STATIC

post-extract:
# Remove bundled files.
	${RM} -r ${WRKSRC}/src/external/glfw ${WRKSRC}/src/external/include ${WRKSRC}/src/rglfw.c

post-install:
# Install all parts for raylib
	${INSTALL_DATA}	${WRKSRC}/src/raylib.h \
		${WRKSRC}/src/raymath.h \
		${WRKSRC}/src/rlgl.h \
		${WRKSRC}/src/extras/physac.h \
		${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
