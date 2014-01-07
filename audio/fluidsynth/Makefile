# Created by: Juha Nygard <juha.nygard1@netikka.fi>
# $FreeBSD$

PORTNAME=	fluidsynth
PORTVERSION=	1.1.6
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

LICENSE=	LGPL20

OPTIONS_DEFINE=	JACK ALSA DBUS LADSPA LASH PORTAUDIO PULSEAUDIO SNDFILE
OPTIONS_DEFAULT=	JACK

USE_BZIP2=	yes
USE_GNOME=	glib20
USES=		cmake pkgconfig ninja
CMAKE_ARGS=	-Denable-ladcca:BOOL=FALSE \
		-Denable-midishare:BOOL=FALSE
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CMAKE_OFF=		-Denable-jack:BOOL=FALSE

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CMAKE_OFF=		-Denable-alsa:BOOL=FALSE

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CMAKE_OFF=		-Denable-dbus:BOOL=FALSE

LADSPA_BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LADSPA_RUN_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LADSPA_CMAKE_ON=	-Denable-ladspa:BOOL=TRUE

LASH_LIB_DEPENDS=	liblash.so:${PORTSDIR}/audio/lash
LASH_CMAKE_OFF=		-Denable-lash:BOOL=FALSE

PORTAUDIO_BUILD_DEPENDS=	${LOCALBASE}/include/portaudio2/portaudio.h:${PORTSDIR}/audio/portaudio2
PORTAUDIO_RUN_DEPENDS=	${LOCALBASE}/include/portaudio2/portaudio.h:${PORTSDIR}/audio/portaudio2
PORTAUDIO_CMAKE_ON=	-Denable-portaudio:BOOL=TRUE
PORTAUDIO_CFLAGS=	-I${LOCALBASE}/include/portaudio2
PORTAUDIO_LDFLAGS=	-L${LOCALBASE}/lib/portaudio2

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CMAKE_OFF=	-Denable-pulseaudio:BOOL=FALSE

SNDFILE_LIB_DEPENDS=	libsndfile.so:${PORTSDIR}/audio/libsndfile
SNDFILE_CMAKe_OFF=	-Denable-libsndfile:BOOL=FALSE

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
