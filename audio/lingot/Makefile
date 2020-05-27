# Created by: Bartoletti <lbartoletti@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lingot
PORTVERSION=	1.0.1
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Musical instrument tuner

LICENSE=	GPLv2

USES=		gmake gnome pkgconfig
USE_GNOME=	gtk30 gdkpixbuf2 cairo intltool
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	DATADIRNAME="share"
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALLS_ICONS=		YES

OPTIONS_DEFINE=		DOCS NLS FFTW
OPTIONS_GROUP=		SOUND
OPTIONS_GROUP_SOUND=	ALSA JACK PULSEAUDIO
OPTIONS_DEFAULT=	JACK NLS FFTW
OPTIONS_SUB=		YES

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins
ALSA_CONFIGURE_ENABLE=	alsa

JACK_LIB_DEPENDS=	libjack.so:audio/jack \
			libsamplerate.so:audio/libsamplerate
JACK_CONFIGURE_ENABLE=	jack

FFTW_LIB_DEPENDS=	libfftw3f.so:math/fftw3-float
FFTW_CONFIGURE_ENABLE=	libfftw

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
