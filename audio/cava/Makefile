PORTNAME=	cava
DISTVERSION=	0.10.2
CATEGORIES=	audio

MAINTAINER=	vendion@gmail.com
COMMENT=	Cross-platform Audio Visualizer
WWW=		https://github.com/karlstav/cava

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libiniparser.so:devel/iniparser

USES=		autoreconf compiler:c11 libtool localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	karlstav

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-input-alsa \
		--disable-input-pipewire

PLIST_FILES=	bin/cava
PORTDOCS=	README.md
PORTEXAMPLES=	config
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS EXAMPLES VT
OPTIONS_DEFAULT=	GLSL JACK NCURSES OSS PORTAUDIO PULSEAUDIO SDL SNDIO VT

OPTIONS_GROUP=		INPUT OUTPUT
OPTIONS_GROUP_INPUT=	JACK OSS PORTAUDIO PULSEAUDIO SNDIO
OPTIONS_GROUP_OUTPUT=	GLSL NCURSES SDL

GLSL_DESC=		Build with GLSL support (implies ${GLSL_IMPLIES})
GLSL_BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/ax_check_gl.m4:devel/autoconf-archive
GLSL_USES=		gl
GLSL_USE=		GL=gl
GLSL_CONFIGURE_ENABLE=	output-sdl-glsl
GLSL_IMPLIES=		SDL

JACK_DESC=		Build with JACK support
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	input-jack

NCURSES_DESC=			Build with ncurses support
NCURSES_USES=			ncurses
NCURSES_CONFIGURE_ENABLE=	output-ncurses

OSS_DESC=		Build with OSS support
OSS_CONFIGURE_ENABLE=	input-oss

PORTAUDIO_DESC=			Build with portaudio support
PORTAUDIO_LIB_DEPENDS=		libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_ENABLE=	input-portaudio

PULSEAUDIO_DESC=		Build with pulseaudio support
PULSEAUDIO_LIB_DEPENDS=		libpulse-simple.so:audio/pulseaudio \
				libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	input-pulse

SDL_DESC=		Build with SDL support
SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_CONFIGURE_ENABLE=	output-sdl

SNDIO_DESC=		Build with sndio support
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	input-sndio

VT_DESC=		Build and install custom font for vt(4)
VT_BUILD_DEPENDS=	psf2bdf:x11-fonts/psftools
VT_CONFIGURE_ENABLE=	cava-font
VT_PLIST_FILES=		${DATADIR}/cava.fnt

pre-configure:
	${ECHO_CMD} ${DISTVERSION} > ${WRKSRC}/version

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example_files/config ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
