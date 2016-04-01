# Created by: Juha Nygard <juha.nygard1@netikka.fi>
# $FreeBSD$

PORTNAME=	fluidsynth
PORTVERSION=	1.1.6
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	JACK ALSA DBUS LADSPA LASH PORTAUDIO PULSEAUDIO SNDFILE
OPTIONS_DEFAULT=	JACK

USE_GNOME=	glib20
USES=		cmake pkgconfig ninja tar:bzip2
CMAKE_ARGS=	-Denable-ladcca:BOOL=FALSE \
		-Denable-midishare:BOOL=FALSE
USE_LDCONFIG=	yes

LDFLAGS+=	-lpthread

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_OFF=		-Denable-jack:BOOL=FALSE

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_OFF=		-Denable-alsa:BOOL=FALSE

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_OFF=		-Denable-dbus:BOOL=FALSE

LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa
LADSPA_CMAKE_ON=	-Denable-ladspa:BOOL=TRUE

LASH_LIB_DEPENDS=	liblash.so:audio/lash
LASH_CMAKE_OFF=		-Denable-lash:BOOL=FALSE

PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_ON=	-Denable-portaudio:BOOL=TRUE

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_OFF=	-Denable-pulseaudio:BOOL=FALSE

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CMAKE_OFF=	-Denable-libsndfile:BOOL=FALSE

post-patch:
	@${REINPLACE_CMD} -e \
		'/Linux/s|^|#| ; \
		 /_init_lib_suffix/s|"64"|""| ; \
		 /CMAKE_C_FLAGS_RELEASE/s|-O2|| ; \
		 s|enable_midishare|enable-midishare| ; \
		 s|$${LIB_INSTALL_DIR}$${LIB_SUFFIX}/pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/cmake_admin/DefaultDirs.cmake

.include <bsd.port.mk>
