PORTNAME=	${GH_PROJECT:tl}
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.1
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Free music composition & notation software

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
		buildtools_build linguisttools_build qmake_build uitools_build

USE_GITHUB=	yes
GH_PROJECT=	MuseScore

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
ALSA_CMAKE_BOOL=	BUILD_ALSA
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	BUILD_JACK
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	BUILD_PORTAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	BUILD_PULSEAUDIO
WEBENGINE_USE=		qt=webengine
WEBENGINE_CMAKE_BOOL=	BUILD_WEBENGINE

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-inconsistent-missing-override
.endif

.include <bsd.port.post.mk>
