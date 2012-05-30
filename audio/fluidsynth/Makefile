# ports collection makefile for:   fluidsynth
# Date created:        27 Nov 2003
# Whom:                Juha Nygard <juha.nygard1@netikka.fi>
#
# $FreeBSD$
#

PORTNAME=	fluidsynth
PORTVERSION=	1.1.5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	JACK ALSA DBUS LADSPA LASH PORTAUDIO PULSEAUDIO SNDFILE
OPTIONS_DEFAULT=	JACK

USE_BZIP2=	yes
USE_GNOME=	glib20 pkgconfig
USE_CMAKE=	yes
CMAKE_ARGS=	-Denable-ladcca:BOOL=FALSE \
		-Denable-midishare:BOOL=FALSE
USE_LDCONFIG=	yes

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

MAN1=		fluidsynth.1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CMAKE_ARGS+=	-Denable-jack:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.else
CMAKE_ARGS+=	-Denable-alsa:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.else
CMAKE_ARGS+=	-Denable-dbus:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MLADSPA}
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
CMAKE_ARGS+=	-Denable-ladspa:BOOL=TRUE
.endif

.if ${PORT_OPTIONS:MLASH}
LIB_DEPENDS+=	lash:${PORTSDIR}/audio/lash
.else
CMAKE_ARGS+=	-Denable-lash:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
BUILD_DEPENDS+=	${LOCALBASE}/include/portaudio2/portaudio.h:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	${LOCALBASE}/include/portaudio2/portaudio.h:${PORTSDIR}/audio/portaudio2
CMAKE_ARGS+=	-Denable-portaudio:BOOL=TRUE
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-Denable-pulseaudio:BOOL=FALSE
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.else
CMAKE_ARGS+=	-Denable-libsndfile:BOOL=FALSE
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/Linux/s|^|#| ; \
		 /_init_lib_suffix/s|"64"|""| ; \
		 /CMAKE_C_FLAGS_RELEASE/s|-O2|| ; \
		 s|enable_midishare|enable-midishare| ; \
		 s|$${LIB_INSTALL_DIR}$${LIB_SUFFIX}/pkgconfig|$${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|share/man|man|' ${WRKSRC}/cmake_admin/DefaultDirs.cmake

.include <bsd.port.post.mk>
