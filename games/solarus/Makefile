PORTNAME=	solarus
PORTVERSION=	1.6.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Zelda-like 2D game engine
WWW=		https://www.solarus-games.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license.txt

LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libmodplug.so:audio/libmodplug \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg
RUN_DEPENDS=	glm>0:math/glm
BUILD_DEPENDS=	glm>0:math/glm

USES=		cmake:noninja compiler:c++11-lib gl openal qmake qt:5 sdl xorg

USE_GITLAB=	yes
GL_ACCOUNT=	solarus-games
GL_TAGNAME=	21a378a7858460809ffef1c96a07a493d709730c

MAKE_ARGS+=	DESTDIR=${STAGEDIR}
USE_QT=		buildtools:build core gui linguisttools:build widgets
USE_SDL=	sdl2 ttf2 image2
USE_GL=		gl glu
USE_LDCONFIG=	yes

CXXFLAGS+=	-DGLM_ENABLE_EXPERIMENTAL  # GLM_GTX_matrix_transform_2d is an experimental extension

OPTIONS_DEFINE=	LUAJIT
OPTIONS_DEFAULT_amd64=	LUAJIT
OPTIONS_DEFAULT_i386=	LUAJIT
OPTIONS_DEFAULT_powerpc=	LUAJIT
OPTIONS_DEFAULT_powerpc64=	LUAJIT
OPTIONS_DEFAULT_powerpc64le=	LUAJIT

LUAJIT_CMAKE_BOOL=	SOLARUS_USE_LUAJIT
LUAJIT_DESC=	Use LuaJIT instead of standard Lua
LUAJIT_USES=	luajit
LUAJIT_USES_OFF=	lua:51

.include <bsd.port.mk>
