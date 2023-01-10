PORTNAME=	solarus-quest-editor
PORTVERSION=	1.6.5
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	GUI to create and modify quests for the Solarus engine
WWW=		https://www.solarus-games.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license_gpl.txt

LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libmodplug.so:audio/libmodplug \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libsolarus.so:games/solarus \

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		cmake compiler:c++11-lib openal qt:5 sdl

USE_GITLAB=	yes
GL_ACCOUNT=	solarus-games
GL_COMMIT=	c8d0835c3a62a0e60cdb32d26be8b75485a23a96

USE_SDL=	sdl2 ttf2 image2
USE_QT=		buildtools:build concurrent core gui linguist qmake:build widgets

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

DESKTOP_ENTRIES=	"Solarus Quest Editor" "${COMMENT}" "${PORTNAME}" "${PORTNAME}"  \
			"Game;" false

.include <bsd.port.mk>
