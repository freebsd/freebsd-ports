# ports collection makefile for:   fluidsynth
# Date created:        27 Nov 2003
# Whom:                Juha Nygard <juha.nygard1@netikka.fi>
#
# $FreeBSD$
#

PORTNAME=	fluidsynth
PORTVERSION=	1.1.1
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH/fluid

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

OPTIONS=	JACK "Enable Jack audio support" On \
		LADSPA "Enable LADSPA audio support" Off \
		PORTAUDIO "Enable PortAudio support" Off \
		PULSEAUDIO "Enable PulseAudio support" Off \
		SNDFILE "Enable Libsndfile support" Off

USE_GNOME=	glib20 gnomehack pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-alsa-support --disable-midishare \
		--disable-coreaudio --disable-coremidi \
		--disable-dart --disable-lash \
		--disable-ladcca
USE_LDCONFIG=	yes

MAN1=		fluidsynth.1

CPPFLAGS=	${PA2_CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	${PA2_LIBS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if defined(WITH_JACK)
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack-support
.endif

.if defined(WITH_LADSPA)
BUILD_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS+=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
CONFIGURE_ARGS+=	--enable-ladspa
.endif

.if defined(WITH_PORTAUDIO)
BUILD_DEPENDS+=	${LOCALBASE}/include/portaudio2/portaudio.h:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	${LOCALBASE}/include/portaudio2/portaudio.h:${PORTSDIR}/audio/portaudio2
PA2_CFLAGS=	`pkg-config --cflags-only-I portaudio-2.0`
PA2_LIBS=	`pkg-config --libs-only-L portaudio-2.0`
.else
CONFIGURE_ARGS+=	--disable-portaudio-support
.endif

.if defined(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulse-support
.endif

.if defined(WITH_SNDFILE)
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
.else
CONFIGURE_ARGS+=	--disable-libsndfile-support
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -O2 | |g ; \
		 s|== "yes"|= "yes"|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '197 s/,/ /' ${WRKSRC}/include/fluidsynth/synth.h

.include <bsd.port.post.mk>
