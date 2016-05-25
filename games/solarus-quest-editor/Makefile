# Created by: Danilo Egea Gondolfo <danilo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	solarus-quest-editor
PORTVERSION=	1.4.5
DISTVERSIONPREFIX=	v
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
		libsolarus.so:games/solarus

USE_GITHUB=	yes
GH_ACCOUNT=	christopho

CMAKE_ARGS+=	-DSOLARUS_USE_LUAJIT=OFF
USE_SDL=	sdl2 ttf2 image2
USE_QT5=	buildtools core gui linguist qmake widgets
USES=		cmake compiler:c++11-lib openal

DESKTOP_ENTRIES=	"Solarus Quest Editor" "${COMMENT}" "${PORTNAME}" "${PORTNAME}"  \
			"Game;" false

PLIST_FILES=	bin/solarus-quest-editor \
		share/pixmaps/${PORTNAME}.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/solarus-quest-editor ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/logo/sqe-logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
