PORTNAME=	raylib
DISTVERSION=	6.0
CATEGORIES=	devel education

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Library to learn videogames programming
WWW=		https://www.raylib.com/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake localbase:ldflags sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	raysan5
USE_LDCONFIG=	yes
USE_SDL=	sdl3
USE_XORG=	ice sm x11 xcursor xext xi xinerama xrandr xxf86vm

CMAKE_ARGS=	-DPLATFORM=SDL
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_EXAMPLES

post-install:
# Install all parts for raylib
	${INSTALL_DATA}	${WRKSRC}/src/raylib.h \
		${WRKSRC}/src/raymath.h \
		${WRKSRC}/src/rlgl.h \
		${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
