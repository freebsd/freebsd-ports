# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	slade
DISTVERSION=	3.1.1_b2
CATEGORIES=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern editor for Doom-engine based games and source ports

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	libfluidsynth.so:${PORTSDIR}/audio/fluidsynth \
		libsfml-system.so:${PORTSDIR}/devel/sfml \
		libftgl.so:${PORTSDIR}/graphics/ftgl \
		libfreeimage.so:${PORTSDIR}/graphics/freeimage

USE_GITHUB=	yes
GH_ACCOUNT=	sirjuddington
GH_PROJECT=	${PORTNAME:tu}

USES=		cmake compiler:c++11-lib pkgconfig
USE_WX=		3.0+
USE_CXXSTD=	c++11

PLIST_FILES=	bin/slade share/slade3/slade.pk3

post-patch:
	@${REINPLACE_CMD} -e 's,"alsa","oss",' ${WRKSRC}/src/MIDIPlayer.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}3
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.pk3 \
		${STAGEDIR}${PREFIX}/share/${PORTNAME}3

.include <bsd.port.mk>
