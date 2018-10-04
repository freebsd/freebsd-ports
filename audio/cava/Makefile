# $FreeBSD$

PORTNAME=	cava
DISTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Console-based Audio Visualizer for MPD, PulseAudio, and sndio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	psf2bdf:x11-fonts/psftools
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libiniparser.so:devel/iniparser

USES=		autoreconf libtool localbase ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	karlstav

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_asound_snd_pcm_open=no \
		FONT_DIR=${DATADIR}

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/cava ${DATADIR}/cava.fnt
PORTDOCS=	README.md
PORTEXAMPLES=	config

OPTIONS_DEFINE=	DOCS EXAMPLES PULSEAUDIO SNDIO
OPTIONS_DEFAULT=PULSEAUDIO SNDIO

PULSEAUDIO_CONFIGURE_ENV_OFF=	ac_cv_lib_pulse_simple_pa_simple_new=no
PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio \
				libpulse.so:audio/pulseaudio \

SNDIO_CONFIGURE_ENV_OFF=	ac_cv_lib_sndio_sio_open=no
SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio

pre-configure:
	@${ECHO_CMD} ${DISTVERSION} > ${WRKSRC}/version

pre-build:
	psf2bdf ${WRKSRC}/cava.psf > ${WRKSRC}/cava.bdf
	vtfontcvt ${WRKSRC}/cava.bdf ${WRKSRC}/cava.fnt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example_files/config ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
