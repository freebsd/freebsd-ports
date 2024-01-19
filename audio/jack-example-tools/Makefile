PORTNAME=	jack-example-tools
DISTVERSION=	4
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	dev@submerge.ch
COMMENT=	Low latency audio server
WWW=		https://jackaudio.org/

LICENSE=	GPLv2 GPLv3+
LICENSE_COMB=	multi

LIB_DEPENDS=	libjack.so:audio/jack \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libsysinfo.so:devel/libsysinfo

USES=		compiler:c11 localbase:ldflags meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	jackaudio

CONFIGURE_ARGS=	-Djack_net=enabled \
		-Djack_netsource=enabled \
		-Djack_rec=enabled
CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=		ALSA OPUS READLINE
OPTIONS_DEFAULT=	OPUS READLINE
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib \
			libzita-alsa-pcmi.so:audio/zita-alsa-pcmi \
			libzita-resampler.so:audio/zita-resampler
ALSA_MESON_ENABLED=	alsa_in_out zalsa
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_MESON_ENABLED=	opus_support

READLINE_USES=		readline
READLINE_MESON_ENABLED=	readline_support
READLINE_LDFLAGS=	-lreadline

.include <bsd.port.mk>
