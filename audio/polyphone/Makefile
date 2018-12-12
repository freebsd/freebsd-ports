# $FreeBSD$

PORTNAME=	polyphone
DISTVERSION=	1.9
DISTVERSIONSUFFIX=	-src
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://polyphone-soundfonts.com/en/download/file/76-polyphone-1-8-src-zip/latest/download?ae95d968569b61bc77f7b8559a14db4d=1/

PATCH_SITES=	https://github.com/davy7125/polyphone/commit/
PATCHFILES=	7d3e26b46cb5.patch:-p2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical user interface for editing soundfont (sf2 and sfz) files

LICENSE=	GPLv3

LIB_DEPENDS=	libjack.so:audio/jack \
		libogg.so:audio/libogg \
		libportaudio.so:audio/portaudio \
		librtmidi.so:audio/rtmidi \
		libstk-4.6.0.so:audio/stk \
		libvorbisfile.so:audio/libvorbis

USES=		compiler:c++11-lang desktop-file-utils pkgconfig qmake:outsource qt:5 shared-mime-info zip
USE_GL=		gl
USE_QT=		core concurrent gui network printsupport svg widgets buildtools_build qmake_build
USE_CXXSTD=	c++11
QMAKE_ARGS=	DEFINES=USE_LOCAL_QCUSTOMPLOT
CXXFLAGS+=	-D__UNIX_JACK__

WRKSRC=		${WRKDIR}/trunk

PLIST_FILES=	bin/polyphone \
		share/applications/polyphone.desktop \
		share/mime/packages/polyphone.xml \
		share/pixmaps/polyphone.png

post-patch:
	@${REINPLACE_CMD} -e ' \
		s| -mfpmath=387||g; \
		s|/usr/include|${LOCALBASE}/include|g; \
		s| alsa||g; \
		s|ExtraCompiler.commands = $$$${QMAKE_CXX} -fPIC|ExtraCompiler.commands = $$$${QMAKE_CXX} $$(CXXFLAGS) -fPIC|g' \
		${WRKSRC}/polyphone.pro

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/RELEASE/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ressources/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.desktop  ${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xml  ${STAGEDIR}${PREFIX}/share/mime/packages

.include <bsd.port.mk>
