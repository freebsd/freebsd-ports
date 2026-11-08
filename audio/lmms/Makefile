PORTNAME=	lmms
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0-alpha.2
CATEGORIES=	audio

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	All-in-one sequencer, drum machine, sampler, and more
WWW=		https://lmms.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	32-bit support deprecated

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		${LOCALBASE}/include/exprtk.hpp:math/exprtk
LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libzix-0.so:devel/zix \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom \
		libsuil-0.so:audio/suil \
		libcarla_native-plugin.so:audio/carla \
		libstk.so:audio/stk \
		libmp3lame.so:audio/lame \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libfftw3f.so:math/fftw3-float \
		libfltk.so:x11-toolkits/fltk \
		libfluidsynth.so:audio/fluidsynth \
		libgig.so:audio/libgig \
		libsamplerate.so:audio/libsamplerate \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${LOCALBASE}/lib/ladspa/cmt.so:audio/cmt \
		${LOCALBASE}/lib/lv2/calf.lv2/calf.so:audio/calf-lv2 \
		${LOCALBASE}/share/ladspa/rdf/caps.rdf:audio/caps-plugins \
		${LOCALBASE}/share/ladspa/rdf/swh-plugins.rdf:audio/swhplugins \
		${LOCALBASE}/share/ladspa/rdf/tap-plugins.rdf:audio/tap-plugins

USES=		cmake compiler:c++20-lang desktop-file-utils gl localbase:ldflags \
		perl5 pkgconfig qt:6 shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	LMMS
GH_TUPLE=	LMMS:zynaddsubfx:66a42efcc72d4d75a70412795f1510c4297ab826:zynaddsubfx/plugins/ZynAddSubFx/zynaddsubfx \
		libgme:game-music-emu:21a064ea66a5cdf71910e207c4756095c266814f:gme/plugins/FreeBoy/game-music-emu \
		adplug:adplug:3ed6617ec00022dfab574c27710d9071a6032c87:adplug/plugins/OpulenZ/adplug \
		JohannesLorenz:ringbuffer:1c46ef34a28d4637b43fb6d5ebb31d38c05f4bd8:ringbuffer/src/3rdparty/ringbuffer \
		libsidplayfp:resid:ef72462f5fa0682d099413512b764ae479e77f9b:resid/plugins/Sid/resid/resid \
		LostRobotMusic:hiir:4a9a1e67fa6f8ce7688e1c0c8a2b017cecd206a3:hiir/src/3rdparty/hiir/hiir \
		portsmf:portsmf:081261bcfd8faca4cee8560010de34831c0dea97:portsmf/plugins/MidiImport/portsmf

USE_GL=		opengl

USE_PERL5=	build

USE_QT=		base svg

USE_XORG=	xrender xcursor xfixes xext xft xinerama

CMAKE_ON=	WANT_QT6
CMAKE_OFF=	WANT_CALF WANT_CAPS WANT_CMT WANT_SWH WANT_TAP WANT_VST WANT_SOUNDIO WANT_WEAKJACK

OPTIONS_DEFINE=		ALSA JACK OSS PORTAUDIO PULSEAUDIO SDL SNDIO
OPTIONS_DEFAULT=	OSS

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	WANT_ALSA

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	WANT_JACK

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	WANT_PORTAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	WANT_PULSEAUDIO

SDL_USES=		sdl
SDL_USE=		sdl=sdl2
SDL_CMAKE_OFF=		WANT_SDL

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	WANT_SNDIO

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} 's|/usr|${LOCALBASE}|g' ${WRKSRC}/src/core/ConfigManager.cpp
	@${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/core/LadspaManager.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions && \
		${INSTALL_DATA} ${WRKSRC}/doc/bash-completion/lmms ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	@${RLN} ${STAGEDIR}${DATADIR}/themes/default/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/lmms.png

.include <bsd.port.mk>
