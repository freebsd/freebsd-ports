# New ports collection makefile for:	lmms
# Date created:				04 Dec 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lmms
PORTVERSION=	0.4.13
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	rodrigo@bebik.net
COMMENT=	An all-in-one sequencer, drum machine, sampler and more

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		fluidsynth.1:${PORTSDIR}/audio/fluidsynth \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float
RUN_DEPENDS=	${LOCALBASE}/share/ladspa/rdf/caps.rdf:${PORTSDIR}/audio/caps-plugins \
		${LOCALBASE}/lib/ladspa/cmt.so:${PORTSDIR}/audio/cmt \
		${LOCALBASE}/share/ladspa/rdf/swh-plugins.rdf:${PORTSDIR}/audio/swhplugins \
		${LOCALBASE}/share/ladspa/rdf/tap-plugins.rdf:${PORTSDIR}/audio/tap-plugins \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info

OPTIONS=	JACK       "Enable JACK support"       OFF \
		PULSEAUDIO "Enable PulseAudio support" OFF \
		SDL        "Enable SDL support"        OFF

USE_LDCONFIG=	yes
USE_BZIP2=	yes
USE_XORG=	xft
USE_QT4=	corelib gui xml moc_build uic_build rcc_build \
		qmake_build
USE_CMAKE=	yes
CMAKE_ARGS=	-DWANT_ALSA:BOOL=OFF \
		-DWANT_CALF:BOOL=OFF \
		-DWANT_CAPS:BOOL=OFF \
		-DWANT_CMT:BOOL=OFF \
		-DWANT_SWH:BOOL=OFF \
		-DWANT_STK:BOOL=OFF \
		-DWANT_TAP:BOOL=OFF \
		-DWANT_VST:BOOL=OFF \
		-DHAVE_STRTOLL=ON
MAKE_JOBS_SAFE=	yes

MANCOMPRESSED=	yes
MAN1=		lmms.1

USE_DOS2UNIX=	plugins/midi_import/portsmf/allegrowr.cpp plugins/midi_import/portsmf/mfmidi.cpp

.include <bsd.port.options.mk>

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CMAKE_ARGS+=	-DWANT_JACK:BOOL=OFF
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-DWANT_PULSEAUDIO:BOOL=OFF
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
.else
CMAKE_ARGS+=	-DWANT_SDL:BOOL=OFF
.endif

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

post-install:
	@${LN} -sf ${DATADIR}/themes/default/icon.png \
		${PREFIX}/share/pixmaps/lmms.png
	@-update-mime-database ${PREFIX}/share/mime
	# make it setuid-root to be able to set realtime priority
	# (root privileges are dropped in the main routine)
	${CHMOD} u+s ${PREFIX}/bin/lmms

.include <bsd.port.mk>
