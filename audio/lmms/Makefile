# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lmms
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	v
PORTEPOCH=	2
CATEGORIES=	audio

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	All-in-one sequencer, drum machine, sampler, and more

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LIB_DEPENDS=	libFLAC.so:audio/flac \
		libfluidsynth.so:audio/fluidsynth \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libsamplerate.so:audio/libsamplerate \
		libfltk.so:x11-toolkits/fltk
RUN_DEPENDS=	${LOCALBASE}/share/ladspa/rdf/caps.rdf:audio/caps-plugins \
		${LOCALBASE}/lib/ladspa/cmt.so:audio/cmt \
		${LOCALBASE}/share/ladspa/rdf/swh-plugins.rdf:audio/swhplugins \
		${LOCALBASE}/share/ladspa/rdf/tap-plugins.rdf:audio/tap-plugins

OPTIONS_DEFINE=	JACK PULSEAUDIO SDL

USE_LDCONFIG=	yes
USE_XORG=	xft
USE_QT4=	corelib gui xml moc_build uic_build rcc_build \
		qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	LMMS
USES=		cmake desktop-file-utils dos2unix pkgconfig shared-mime-info
CMAKE_ARGS=	-DWANT_ALSA:BOOL=OFF \
		-DWANT_CALF:BOOL=OFF \
		-DWANT_CAPS:BOOL=OFF \
		-DWANT_CMT:BOOL=OFF \
		-DWANT_SWH:BOOL=OFF \
		-DWANT_STK:BOOL=OFF \
		-DWANT_TAP:BOOL=OFF \
		-DWANT_VST:BOOL=OFF \
		-DHAVE_STRTOLL=ON

DOS2UNIX_FILES=	CMakeLists.txt

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_OFF=		-DWANT_JACK:BOOL=OFF

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_OFF=	-DWANT_PULSEAUDIO:BOOL=OFF

SDL_USE=		SDL=sdl
SDL_CMAKE_OFF=		-DWANT_SDL:BOOL=OFF

post-patch:
.for file in data/lmms.desktop
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*$$|=lmms|g ; \
		 /^Exec/s|=.*$$|=lmms|g ; \
		 /^Categories/s|$$|;|g ; \
		 /^MimeType/s|$$|;|g' ${WRKSRC}/${file}
.endfor
.for filename in data/lmms src/core/config_mgr.cpp
	@${REINPLACE_CMD} -e \
		's|/usr|${PREFIX}|g' ${WRKSRC}/${filename}
.endfor
.for filename in src/core/ladspa_manager.cpp
	@${REINPLACE_CMD} -e \
		'/\/usr\/lib/d ; \
		 s|/usr/local|${PREFIX}|g' ${WRKSRC}/${filename}
.endfor
	@${REINPLACE_CMD} -e 's/lib64/lib/' \
		${WRKSRC}/cmake/modules/DetectMachine.cmake

post-install:
	@${LN} -sf ${DATADIR}/themes/default/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/lmms.png
	# make it setuid-root to be able to set realtime priority
	# (root privileges are dropped in the main routine)

.include <bsd.port.mk>
