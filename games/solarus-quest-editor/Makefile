# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	solarus-quest-editor
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	GUI to create and modify quests for the Solarus engine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license_gpl.txt

LIB_DEPENDS=	libphysfs.so:devel/physfs \
		libmodplug.so:audio/libmodplug \
		liblua-5.1.so:lang/lua51 \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libsolarus.so:games/solarus \

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		cmake compiler:c++11-lib openal qt:5 sdl

USE_GITLAB=	yes
GL_ACCOUNT=	solarus-games
GL_COMMIT=	47ebde229b805ebe076ab6ef7f8e947a06a17451

CMAKE_ARGS+=	-DSOLARUS_USE_LUAJIT=OFF
USE_SDL=	sdl2 ttf2 image2
USE_QT=		buildtools_build concurrent core gui linguist qmake_build widgets

DESKTOP_ENTRIES=	"Solarus Quest Editor" "${COMMENT}" "${PORTNAME}" "${PORTNAME}"  \
			"Game;" false

.include <bsd.port.mk>
