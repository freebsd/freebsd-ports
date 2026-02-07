PORTNAME=	${GH_PROJECT:tl}3
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.2
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Free music composition & notation software (legacy version)
WWW=		https://musescore.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

LIB_DEPENDS=	libmp3lame.so:audio/lame \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lib desktop-file-utils localbase \
		pkgconfig qt:5 shared-mime-info
USE_QT=		concurrent core declarative designer graphicaleffects gui \
		help location network opengl printsupport \
		quickcontrols2 scripttools sql svg testlib \
		webchannel widgets xml xmlpatterns \
		buildtools:build linguisttools:build qmake:build uitools:build

USE_GITHUB=	yes
GH_PROJECT=	MuseScore
GH_ACCOUNT=	musescore


# Each release gets a subdir containing the distfiles for that release,
# so hope that scanning the parent dir finds new ones.
#
# Note needs PORTVERSION:R once there is a .minor version
DATADIR=	${PREFIX}/share/mscore-${PORTVERSION:R}

ALL_TARGET=	lrelease manpages all

CMAKE_OFF=	BUILD_PORTMIDI BUILD_PCH MSCORE_UNSTABLE
CMAKE_ON=	USE_SYSTEM_FREETYPE
CMAKE_BUILD_TYPE=	release

# WebEngine is only available on i386/amd64, amd ppc64 starting FreeBSD 13.0.
# If enabled on arches that don't have WebEngine, the build breaks.
OPTIONS_DEFINE=		ALSA JACK PORTAUDIO PULSEAUDIO WEBENGINE
OPTIONS_DEFAULT=	PORTAUDIO
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE

WEBENGINE_DESC=		Use WebEngine in the welcome panel

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	BUILD_ALSA HAS_MIDI
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	BUILD_JACK
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	BUILD_PORTAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	BUILD_PULSEAUDIO
WEBENGINE_USE=		qt=webengine
WEBENGINE_CMAKE_BOOL=	BUILD_WEBENGINE

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mscore ${STAGEDIR}${PREFIX}/bin/mscore3
	${RM} ${STAGEDIR}${PREFIX}/bin/musescore
	${LN} -s mscore3 ${STAGEDIR}${PREFIX}/bin/musescore3
	${MV} ${STAGEDIR}${PREFIX}/share/man/man1/mscore.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/mscore3.1.gz
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/musescore.1.gz
	${LN} -s mscore3.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/musescore3.1.gz
	${RM} ${STAGEDIR}${DATADIR}/sound/MuseScore_General.sf3
	${INSTALL_DATA} ${DISTDIR}/MuseScore_General.sf3 ${STAGEDIR}${DATADIR}/sound/
	${FIND} ${STAGEDIR}${PREFIX} -name mscore.png -execdir ${MV} mscore.png mscore3.png \;
	${RM} ${STAGEDIR}${PREFIX}/share/applications/mscore.desktop
	${INSTALL_DATA} ${FILESDIR}/mscore3.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.pre.mk>

DISTFILES+=	MuseScore_General.sf3:sfont
MASTER_SITES+=	https://ftp.osuosl.org/pub/musescore/soundfont/MuseScore_General/:sfont
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}_GH0${EXTRACT_SUFX}

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-inconsistent-missing-override
.endif

.include <bsd.port.post.mk>
