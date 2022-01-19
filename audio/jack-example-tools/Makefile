PORTNAME=	jack-example-tools
DISTVERSION=	1
CATEGORIES=	audio

MAINTAINER=	dev@submerge.ch
COMMENT=	Low latency audio server

LICENSE=	GPLv2 GPLv3+
LICENSE_COMB=	multi

LIB_DEPENDS=	libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		libsamplerate.so:audio/libsamplerate \
		libsysinfo.so:devel/libsysinfo

USES=		compiler:c11 pkgconfig meson localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	jackaudio

CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include

CONFIGURE_ARGS=	-Djack_net=enabled -Djack_netsource=enabled -Djack_rec=enabled

OPTIONS_DEFINE=		ALSA READLINE OPUS
OPTIONS_DEFAULT=	READLINE OPUS
OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib \
			libzita-alsa-pcmi.so:audio/zita-alsa-pcmi \
			libzita-resampler.so:audio/zita-resampler
ALSA_MESON_ENABLED=	alsa_in_out zalsa

READLINE_USES=		readline
READLINE_MESON_ENABLED=	readline_support
READLINE_LDFLAGS=	-lreadline

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_MESON_ENABLED=	opus_support

.include <bsd.port.pre.mk>

# The alloca.h header is not available on FreeBSD. Upstream knows:
# https://github.com/jackaudio/jack-example-tools/pull/56
post-extract:
	@${TOUCH} ${WRKSRC}/tools/alloca.h

.include <bsd.port.post.mk>
