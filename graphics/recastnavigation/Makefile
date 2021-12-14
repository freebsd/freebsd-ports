PORTNAME=	recastnavigation
PORTVERSION=	1.5.1
CATEGORIES=	graphics

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Art navigation mesh construction toolset for games

USES=		cmake compiler:c++17-lang gl openal pkgconfig sdl xorg
USE_GL=		gl
USE_SDL=	sdl2
USE_GITHUB=	yes
GH_TUPLE=	recastnavigation:recastnavigation:e75adf86f91eb3082220085e42dda62679f9a3ea

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON \
		-DRECASTNAVIGATION_DEMO=OFF \
		-DRECASTNAVIGATION_TESTS=OFF \
		-DRECASTNAVIGATION_EXAMPLES=OFF

.include <bsd.port.mk>
