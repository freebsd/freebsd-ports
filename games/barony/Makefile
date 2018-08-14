# $FreeBSD$

PORTNAME=	barony
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.4
CATEGORIES=	games

MAINTAINER=	devnexen@gmail.com
COMMENT=	3D roguelike game

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.3.0.txt

LIB_DEPENDS=	libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libvorbisfile.so:audio/libvorbis

USES=		cmake compiler:c++11-lib openal localbase:ldflags pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	TurningWheel
GH_PROJECT=	Barony
USE_GL=		gl glu
USE_SDL=	sdl2 image2 net2 ttf2

CMAKE_ON=	OPENAL_ENABLED DATA_DIR
CMAKE_ARGS=	-DEDITOR_EXE_NAME:STRING="barony-editor"
LDFLAGS+=	-Wl,--as-needed
LLD_UNSAFE=	yes # cf. PR 226980

SUB_FILES=	barony.sh pkg-message

PLIST_FILES=	bin/barony \
		bin/barony-editor \
		libexec/barony \
		${DATADIR}/lang/en.ttf \
		${DATADIR}/lang/en.txt

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/barony ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKDIR}/barony.sh ${STAGEDIR}${PREFIX}/bin/barony

.include <bsd.port.mk>
