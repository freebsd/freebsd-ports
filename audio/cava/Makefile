# $FreeBSD$

PORTNAME=	cava
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Console-based Audio Visualizer for MPD, PulseAudio, and sndio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libiniparser.so:devel/iniparser

USES=		autoreconf libtool localbase ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	karlstav

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-input-alsa
CONFIGURE_ENV=	ac_cv_lib_asound_snd_pcm_open=no \
		FONT_DIR=${DATADIR}

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/cava
PORTDOCS=	README.md
PORTEXAMPLES=	config

OPTIONS_DEFINE=		DOCS EXAMPLES PORTAUDIO PULSEAUDIO SNDIO VT
OPTIONS_DEFAULT=	PULSEAUDIO SNDIO VT
.if !exists(/usr/bin/vtfontcvt)
OPTIONS_EXCLUDE=	VT
.endif

VT_DESC=	Build with vt(4) support (installs custom font)

PORTAUDIO_LIB_DEPENDS=		libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_OFF=	--disable-input-portaudio

PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio \
				libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=	--disable-input-pulse

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_OFF=	--disable-input-sndio

VT_BUILD_DEPENDS=	psf2bdf:x11-fonts/psftools
VT_MAKE_ARGS_OFF=	cava_font__DATA=""
VT_PLIST_FILES=		${DATADIR}/cava.fnt

pre-configure:
	@${ECHO_CMD} ${DISTVERSION} > ${WRKSRC}/version

pre-build-VT-on:
	psf2bdf --fontname="-gnu-cava-medium-r-normal--16-160-75-75-c-80-iso10646-1" \
		${WRKSRC}/cava.psf > ${WRKSRC}/cava.bdf
	vtfontcvt ${WRKSRC}/cava.bdf ${WRKSRC}/cava.fnt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example_files/config ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
