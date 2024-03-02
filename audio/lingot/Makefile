PORTNAME=	lingot
DISTVERSION=	1.1.1
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Musical instrument tuner
WWW=		https://www.nongnu.org/lingot/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-c.so:devel/json-c

USES=				gettext-tools gmake gnome libtool pkgconfig
USE_GNOME=			cairo gtk30 intltool
GNU_CONFIGURE=			yes
CONFIGURE_ENV=			DATADIRNAME="share"
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=			install-strip

# fix: "ld: error: undefined reference due to --no-allow-shlib-undefined: environ"
# by adding "-Wl,--allow-shlib-undefined" (not needed on 1500014 as I tested)
LDFLAGS+=	-Wl,--allow-shlib-undefined -L${LOCALBASE}/lib -lintl

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS FFTW NLS
OPTIONS_DEFAULT=	FFTW JACK
OPTIONS_GROUP=		SOUND
OPTIONS_GROUP_SOUND=	ALSA JACK PULSEAUDIO
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CONFIGURE_WITH=	alsa

FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			libfftw3f.so:math/fftw3-float
FFTW_CONFIGURE_WITH=	fftw

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_WITH=	jack

NLS_CONFIGURE_ENABLE=	nls

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio

.include <bsd.port.mk>
