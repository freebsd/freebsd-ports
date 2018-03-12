# $FreeBSD$

PORTNAME=	cava
DISTVERSION=	0.6.0
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Console-based Audio Visualizer for ALSA, MPD, PulseAudio, and sndio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libiniparser.so:devel/iniparser

USES=		autoreconf libtool localbase ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	karlstav

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_asound_snd_pcm_open=no

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	PULSEAUDIO SNDIO
OPTIONS_DEFAULT=PULSEAUDIO

PULSEAUDIO_CONFIGURE_ENV_OFF=	ac_cv_lib_pulse_simple_pa_simple_new=no
PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio \
				libpulse.so:audio/pulseaudio \

SNDIO_CONFIGURE_ENV_OFF=	ac_cv_lib_sndio_sio_open=no
SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio

post-patch:
	@${REINPLACE_CMD} '/^cava_font/d' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} '/<alloca.h>/d' ${WRKSRC}/cava.c

pre-configure:
	@${ECHO_CMD} ${DISTVERSION} > ${WRKSRC}/version

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example_files/config ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
