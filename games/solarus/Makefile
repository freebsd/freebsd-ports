PORTNAME=	solarus
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Zelda-like 2D game engine
WWW=		https://www.solarus-games.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libmodplug.so:audio/libmodplug \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg
RUN_DEPENDS=	glm>0:math/glm

USES=		cmake:noninja compiler:c++11-lib gl openal sdl xorg

USE_GITLAB=	yes
GL_ACCOUNT=	solarus-games
GL_TAGNAME=	e70e3df7369d690615fc4c9b3f8dfa00066c5e87

USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_SDL=	sdl2 ttf2 image2

CXXFLAGS+=	-DGLM_ENABLE_EXPERIMENTAL  # GLM_GTX_matrix_transform_2d is an experimental extension

OPTIONS_DEFINE=	LUAJIT
OPTIONS_DEFAULT_amd64=	LUAJIT
OPTIONS_DEFAULT_i386=	LUAJIT
OPTIONS_DEFAULT_powerpc=	LUAJIT
OPTIONS_DEFAULT_powerpc64=	LUAJIT
OPTIONS_DEFAULT_powerpc64le=	LUAJIT

LUAJIT_DESC=	Use LuaJIT instead of standard Lua
LUAJIT_USES=	luajit
LUAJIT_USES_OFF=	lua:51
LUAJIT_CMAKE_BOOL=	SOLARUS_USE_LUAJIT

.include <bsd.port.mk>
