PORTNAME=	recastnavigation
DISTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Art navigation mesh construction toolset for games
WWW=		https://github.com/recastnavigation/recastnavigation/

USES=		cmake compiler:c++17-lang gl openal pkgconfig sdl xorg
USE_GL=		gl
USE_SDL=	sdl2
USE_GITHUB=	yes
#GH_TUPLE=	recastnavigation:recastnavigation:6dc1667f580357e8a2154c28b7867bea7e8ad3a7

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON \
		-DRECASTNAVIGATION_DEMO=OFF \
		-DRECASTNAVIGATION_TESTS=OFF \
		-DRECASTNAVIGATION_EXAMPLES=OFF

PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
