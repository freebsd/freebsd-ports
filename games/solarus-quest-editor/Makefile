PORTNAME=	solarus-quest-editor
PORTVERSION=	2.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	GUI to create and modify quests for the Solarus engine
WWW=		https://www.solarus-games.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license_gpl.txt

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libmodplug.so:audio/libmodplug \
		libvorbisfile.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libsolarus.so:games/solarus \
		libqlementine.so:devel/qlementine

USES=		cmake compiler:c++11-lib gl localbase:ldflags openal qt:6 sdl

USE_GITLAB=	yes
GL_ACCOUNT=	solarus-games
GL_PROJECT=	solarus
GL_TAGNAME=	e70e3df7369d690615fc4c9b3f8dfa00066c5e87

USE_GL=		opengl
USE_QT=		base svg tools:build
USE_SDL=	sdl2 ttf2 image2

CMAKE_ARGS+=	-DSOLARUS_FETCHCONTENT=OFF

DESKTOP_ENTRIES=	"Solarus Quest Editor" "${COMMENT}" \
			"${PREFIX}/share/pixmaps/org.solarus-games.solarus-editor.png" \
			"solarus-editor" "Game;" false

WRKSRC_SUBDIR=	editor

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
