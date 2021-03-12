# $FreeBSD$

PORTNAME=	solarus
PORTVERSION=	1.6.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Zelda-like 2D game engine

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
GL_COMMIT=	f43727b232b3ed13d98440a845e2a29e470e4f0d

MAKE_ARGS+=	DESTDIR=${STAGEDIR}
USE_QT=		buildtools_build core gui linguisttools_build widgets
USE_SDL=	sdl2 ttf2 image2
USE_GL=		gl glu
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	LUAJIT
OPTIONS_DEFAULT_amd64=	LUAJIT
OPTIONS_DEFAULT_i386=	LUAJIT
OPTIONS_DEFAULT_powerpc=	LUAJIT
OPTIONS_DEFAULT_powerpc64=	LUAJIT

LUAJIT_CMAKE_BOOL=	SOLARUS_USE_LUAJIT
LUAJIT_DESC=	Use LuaJIT instead of standard Lua
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_USES_OFF=	lua:51

CMAKE_ARGS+=	-DSOLARUS_MANUAL_INSTALL_DESTINATION:STRING="man"

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit-openresty
.endif

.include <bsd.port.mk>
