PORTNAME=	fluidsynth
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.6
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications
WWW=		https://www.fluidsynth.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe gnome pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	FluidSynth

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen \
		CMAKE_DISABLE_FIND_PACKAGE_Git

OPTIONS_DEFINE=		ALSA DBUS INSTPATCH JACK LADSPA PIPEWIRE PORTAUDIO \
			PULSEAUDIO READLINE SDL SNDFILE
OPTIONS_DEFAULT=	JACK READLINE

INSTPATCH_DESC=		Digital sample-based MIDI instrument files support
SDL3_DESC=		Simple Direct Media Layer 3 support
SNDFILE_DESC=		Support for SF3 files via libsndfile

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	enable-alsa

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	enable-dbus

INSTPATCH_LIB_DEPENDS=	libinstpatch-1.0.so:audio/libinstpatch
INSTPATCH_CMAKE_BOOL=	enable-libinstpatch

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	enable-jack

LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_USES=		localbase
LADSPA_CMAKE_BOOL=	enable-ladspa

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	enable-pipewire

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	enable-portaudio

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	enable-pulseaudio

READLINE_USES=		readline
READLINE_CMAKE_BOOL=	enable-readline

SDL_USES=		sdl
SDL_USE=		SDL=sdl3
SDL_CMAKE_BOOL=		enable-sdl3

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CMAKE_BOOL=	enable-libsndfile

.include <bsd.port.mk>
