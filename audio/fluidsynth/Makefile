# Created by: Juha Nygard <juha.nygard1@netikka.fi>
# $FreeBSD$

PORTNAME=	fluidsynth
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.8
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	FluidSynth
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CMAKE_OFF=	enable-midishare
LDFLAGS+=	-lpthread

OPTIONS_DEFINE=	JACK ALSA DBUS LADSPA LASH PORTAUDIO PULSEAUDIO READLINE \
		SNDFILE SNDIO
OPTIONS_DEFAULT=	JACK READLINE

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_BOOL=	enable-jack

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	enable-alsa

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_BOOL=	enable-dbus

LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_CMAKE_BOOL=	enable-ladspa

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CMAKE_BOOL=	enable-lash

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_BOOL=	enable-portaudio

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	enable-pulseaudio

READLINE_USES=		readline
READLINE_CMAKE_BOOL=	enable-readline

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CMAKE_BOOL=	enable-libsndfile

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CMAKE_BOOL=	enable-sndio

post-patch:
	${CP} ${FILESDIR}/fluid_sndio.c ${WRKSRC}/src/drivers/

.include <bsd.port.mk>
