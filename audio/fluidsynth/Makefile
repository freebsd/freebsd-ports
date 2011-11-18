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

OPTIONS=	JACK "Enable Jack audio support" On \
		ALSA "Enable ALSA audio support" Off \
		DBUS "Enable D-Bus support" Off \
		LADSPA "Enable LADSPA audio support" Off \
		LASH "Enable LASH audio support" Off \
		PORTAUDIO "Enable PortAudio support" Off \
		PULSEAUDIO "Enable PulseAudio support" Off \
		SNDFILE "Enable Libsndfile support" Off

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

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CMAKE_ARGS+=	-Denable-jack:BOOL=FALSE
.endif

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
.else
CMAKE_ARGS+=	-Denable-alsa:BOOL=FALSE
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.else
CMAKE_ARGS+=	-Denable-dbus:BOOL=FALSE
.endif

.if defined(WITH_LADSPA)
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
CMAKE_ARGS+=	-Denable-ladspa:BOOL=TRUE
.endif

.if defined(WITH_LASH)
LIB_DEPENDS+=	lash:${PORTSDIR}/audio/lash
.else
CMAKE_ARGS+=	-Denable-lash:BOOL=FALSE
.endif

.if defined(WITH_PORTAUDIO)
BUILD_DEPENDS+=	${LOCALBASE}/include/portaudio2/portaudio.h:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	${LOCALBASE}/include/portaudio2/portaudio.h:${PORTSDIR}/audio/portaudio2
CMAKE_ARGS+=	-Denable-portaudio:BOOL=TRUE
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-Denable-pulseaudio:BOOL=FALSE
.endif

.if defined(WITH_SNDFILE)
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
