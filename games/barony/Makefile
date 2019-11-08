# $FreeBSD$

PORTNAME=	barony
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.2
PORTREVISION=	3
CATEGORIES=	games

MAINTAINER=	devnexen@gmail.com
COMMENT=	3D roguelike game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.3.0.txt

LIB_DEPENDS=	libogg.so:audio/libogg \
		libphysfs.so:devel/physfs \
		libpng.so:graphics/png \
		libvorbisfile.so:audio/libvorbis

USES=		cmake:insource compiler:c++11-lib dos2unix gl localbase:ldflags \
		openal pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	TurningWheel
GH_PROJECT=	Barony
USE_GL=		gl glu
USE_SDL=	sdl2 image2 net2 ttf2

CMAKE_ON=	OPENAL_ENABLED DATA_DIR
CMAKE_ARGS=	-DEDITOR_EXE_NAME:STRING="barony-editor"
DOS2UNIX_FILES=	src/menu.cpp
LDFLAGS+=	-Wl,--as-needed
LLD_UNSAFE=	yes # cf. PR 226980

SUB_FILES=	pkg-message

PLIST_FILES=	bin/barony \
		bin/barony-editor \
		${DATADIR}/lang/en.ttf \
		${DATADIR}/lang/en.txt

.include <bsd.port.mk>
