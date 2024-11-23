PORTNAME=	fluidsynth
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications
WWW=		https://www.fluidsynth.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe gnome pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	FluidSynth
USE_GNOME=	glib20
USE_LDCONFIG=	yes

LDFLAGS+=	-lpthread

# would require unreleased libinstpatch >= 1.1.0
CMAKE_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen \
		enable-dsound \
		enable-libinstpatch \
		enable-midishare \
		enable-waveout \
		enable-winmidi

OPTIONS_DEFINE=		ALSA DBUS JACK LADSPA PIPEWIRE PORTAUDIO \
			PULSEAUDIO READLINE SDL SNDFILE
OPTIONS_DEFAULT=	JACK READLINE

SNDFILE_DESC=		Support for SF3 files via libsndfile

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	enable-alsa
ALSA_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_ALSA:BOOL=True

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	enable-dbus
DBUS_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_DBus1:BOOL=True

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	enable-jack
JACK_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_Jack:BOOL=True

LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_USES=		localbase
LADSPA_CMAKE_BOOL=	enable-ladspa

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	enable-pipewire
PIPEWIRE_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_PipeWire:BOOL=True

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	enable-portaudio
PORTAUDIO_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_PortAudio:BOOL=True

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	enable-pulseaudio
PULSEAUDIO_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_PulseAudio:BOOL=True

READLINE_USES=		readline
READLINE_CMAKE_BOOL=	enable-readline
READLINE_CMAKE_OFF=	-DCMAKE_DISABLE_FIND_PACKAGE_Readline:BOOL=True

SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CMAKE_BOOL=		enable-sdl2
SDL_CMAKE_OFF=		-DCMAKE_DISABLE_FIND_PACKAGE_SDL2:BOOL=True

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CMAKE_BOOL=	enable-libsndfile

.include <bsd.port.mk>
