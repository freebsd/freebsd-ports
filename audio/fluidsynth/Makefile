# Created by: Juha Nygard <juha.nygard1@netikka.fi>
# $FreeBSD$

PORTNAME=	fluidsynth
PORTVERSION=	1.1.6
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	JACK ALSA DBUS LADSPA LASH PORTAUDIO PULSEAUDIO READLINE \
		SNDFILE SNDIO
OPTIONS_DEFAULT=	JACK READLINE

USES=		cmake pkgconfig tar:bzip2
USE_GNOME=	glib20
CMAKE_ARGS=	-Denable-ladcca:BOOL=FALSE \
		-Denable-midishare:BOOL=FALSE
USE_LDCONFIG=	yes

LDFLAGS+=	-lpthread

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
	@${REINPLACE_CMD} -e \
		'/Linux/s|^|#| ; \
		 /_init_lib_suffix/s|"64"|""| ; \
		 /CMAKE_C_FLAGS_RELEASE/s|-O2|| ; \
		 s|enable_midishare|enable-midishare| ; \
		 s|$${LIB_INSTALL_DIR}$${LIB_SUFFIX}/pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/cmake_admin/DefaultDirs.cmake

.include <bsd.port.mk>
