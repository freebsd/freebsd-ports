PORTNAME=	ebumeter
DISTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Real-time audio level metering according to the EBU R-128
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/ebumeter-doc/quickguide.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libclthreads.so:devel/clthreads \
		libclxclient.so:devel/clxclient \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libpng16.so:graphics/png \
		libsndfile.so:audio/libsndfile \
		libzita-resampler.so:audio/zita-resampler

USES=		gmake localbase:ldflags pkgconfig tar:bz2 xorg
USE_XORG=	x11 xft

WRKSRC_SUBDIR=	source

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		bin/ebumeter \
		bin/ebur128

.include <bsd.port.mk>
