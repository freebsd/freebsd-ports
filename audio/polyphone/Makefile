# $FreeBSD$

PORTNAME=	polyphone
DISTVERSION=	2.1.3
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical user interface for editing soundfont (sf2 and sfz) files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libjack.so:audio/jack \
		libogg.so:audio/libogg \
		libportaudio.so:audio/portaudio \
		librtmidi.so:audio/rtmidi \
		libstk.so:audio/stk \
		libvorbisfile.so:audio/libvorbis

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl gnome pkgconfig qmake:outsource qt:5 shared-mime-info ssl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	davy7125
DOS2UNIX_FILES=	polyphone.pro
USE_GL=		gl
USE_QT=		core concurrent gui network printsupport svg widgets buildtools_build qmake_build
USE_GNOME=	glib20
USE_CXXSTD=	c++11
QMAKE_ARGS=	DEFINES=USE_LOCAL_QCUSTOMPLOT
CXXFLAGS+=	-D__UNIX_JACK__
LIBS+=		-lssl -lcrypto

WRKSRC_SUBDIR=	sources

PLIST_FILES=	bin/polyphone \
		share/applications/polyphone.desktop \
		share/mime/packages/polyphone.xml \
		share/pixmaps/polyphone.png

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/resources/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop  ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xml  ${STAGEDIR}${PREFIX}/share/mime/packages

.include <bsd.port.mk>
