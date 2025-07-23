PORTNAME=	mhwaveedit
PORTVERSION=	1.4.24
PORTREVISION=	8
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical program for editing sound files
WWW=		https://github.com/magnush/mhwaveedit/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	magnush

USES=		autoreconf gnome localbase pkgconfig tar:bzip2
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFIGURE_ARGS=	--without-alsalib \
		--without-arts \
		--without-esound \
		--with-build-date="-" \
		--with-build-time="-"

BROKEN_powerpc64=	fails to compile on powerpc64: convert_inc.c: conflicting types for 'C_FLOAT_PCM32SBEPM'

OPTIONS_DEFINE=		DOUBLE_SAMPLES JACK LADSPA OSS PORTAUDIO \
			PULSEAUDIO SAMPLERATE SDL SNDFILE NLS
OPTIONS_DEFAULT=	OSS SAMPLERATE SNDFILE
OPTIONS_SUB=		yes

DOUBLE_SAMPLES_DESC=	Increase quality for 24/32-bit samplerates
DOUBLE_SAMPLES_CONFIGURE_WITH=	double-samples
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_WITH=	jack
LADSPA_BUILD_DEPENDS=	ladspa>0:audio/ladspa
LADSPA_RUN_DEPENDS=	ladspa>0:audio/ladspa
LADSPA_CONFIGURE_ENV_OFF=	ac_cv_header_ladspa_h=no
OSS_CONFIGURE_WITH=	oss
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_WITH=	portaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulse
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_WITH=	libsamplerate
SDL_USES=		sdl
SDL_USE=		sdl=sdl
SDL_CONFIGURE_WITH=	sdl
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_WITH=	libsndfile
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=${PREFIX}/share/pixmaps/mhwaveedit.xpm|' \
		${WRKSRC}/share/applications/mhwaveedit.desktop

.include <bsd.port.mk>
