# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	slade
PORTVERSION=	3.1.1.1
CATEGORIES=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern editor for Doom-engine based games and source ports

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libsfml-system.so:devel/sfml \
		libftgl.so:graphics/ftgl \
		libfreeimage.so:graphics/freeimage

USE_GITHUB=	yes
GH_ACCOUNT=	sirjuddington
GH_PROJECT=	${PORTNAME:tu}

USES=		cmake compiler:c++11-lib pkgconfig
USE_WX=		3.0+
USE_CXXSTD=	c++11

PLIST_FILES=	bin/slade share/slade3/slade.pk3

OPTIONS_DEFINE=	FLUIDSYNTH
OPTIONS_DEFAULT=	FLUIDSYNTH

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_OFF=	-DNO_FLUIDSYNTH:BOOL=ON

post-patch:
	@${REINPLACE_CMD} -e 's,"alsa","oss",' \
		${WRKSRC}/src/Audio/MIDIPlayer.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}3
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pk3 \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}3

.include <bsd.port.mk>
