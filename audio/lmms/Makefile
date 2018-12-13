# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmms
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0-rc7
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	audio

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	All-in-one sequencer, drum machine, sampler, and more

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libFLAC.so:audio/flac \
		libfluidsynth.so:audio/fluidsynth \
		libfontconfig.so:x11-fonts/fontconfig \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libfltk.so:x11-toolkits/fltk
RUN_DEPENDS=	${LOCALBASE}/share/ladspa/rdf/caps.rdf:audio/caps-plugins \
		${LOCALBASE}/lib/ladspa/cmt.so:audio/cmt \
		${LOCALBASE}/share/ladspa/rdf/swh-plugins.rdf:audio/swhplugins \
		${LOCALBASE}/share/ladspa/rdf/tap-plugins.rdf:audio/tap-plugins

USES=		cmake:outsource desktop-file-utils localbase:ldflags pkgconfig \
		qt:5 shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	LMMS
GH_TUPLE=	rampantpixels:rpmalloc:1.3.1:rpmalloc/src/3rdparty/rpmalloc/rpmalloc \
		lukas-w:qt5-x11embed:ec77d4ba40bebc0c53a016adb646b6fa65dd5faf:qt5x11embed/src/3rdparty/qt5-x11embed
USE_LDCONFIG=	yes
USE_QT=		core gui widgets x11extras xml buildtools_build linguisttools_build qmake_build
USE_XORG=	xcursor xext xfixes xft xinerama xrender

CMAKE_OFF=	WANT_ALSA WANT_CALF WANT_CAPS WANT_CMT WANT_SWH WANT_STK \
		WANT_TAP WANT_VST
CMAKE_ON=	WANT_QT5

OPTIONS_DEFINE=		OSS JACK PULSEAUDIO PORTAUDIO SDL SNDIO
OPTIONS_DEFAULT=	OSS

JACK_CMAKE_BOOL=	WANT_JACK
JACK_LIB_DEPENDS=	libjack.so:audio/jack

PULSEAUDIO_CMAKE_BOOL=	WANT_PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

PORTAUDIO_CMAKE_BOOL=	WANT_PORTAUDIO
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

SDL_CMAKE_OFF=		WANT_SDL
SDL_USE=		SDL=sdl

SNDIO_CMAKE_BOOL=	WANT_SNDIO
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio

post-patch:
	@${REINPLACE_CMD} 's|/usr|${LOCALBASE}|g' ${WRKSRC}/src/core/ConfigManager.cpp
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/core/LadspaManager.cpp
	@${REINPLACE_CMD} -e 's/lib64/lib/' \
		${WRKSRC}/cmake/modules/DetectMachine.cmake
	@${REINPLACE_CMD} 's,share/man/,man/,g' ${WRKSRC}/src/CMakeLists.txt

post-patch-OSS-off:
	@${REINPLACE_CMD} \
		-e 's|SET(LMMS_HAVE_OSS TRUE)|SET(LMMS_HAVE_OSS FALSE)|; \
		    s|SET(STATUS_OSS "OK")|SET(STATUS_OSS "<disabled>")|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${RLN} ${STAGEDIR}${DATADIR}/themes/default/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/lmms.png

.include <bsd.port.mk>
