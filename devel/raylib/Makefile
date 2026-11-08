PORTNAME=	raylib
DISTVERSION=	6.2
CATEGORIES=	devel education

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Library to learn videogames programming
WWW=		https://www.raylib.com/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe localbase:ldflags sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	raysan5
USE_LDCONFIG=	yes
USE_SDL=	sdl3
USE_XORG=	ice sm x11 xcursor xext xi xinerama xrandr xxf86vm

CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR=include/${PORTNAME} -DPLATFORM=SDL
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_EXAMPLES

EXTRACT_AFTER_ARGS=	--exclude .github \
			--exclude examples \
			--no-same-owner --no-same-permissions

PLIST_SUB=	SONAME=${DISTVERSION:S|.||}0 \
		VER=${DISTVERSION}.0

.include <bsd.port.mk>
