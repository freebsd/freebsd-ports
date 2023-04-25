PORTNAME=	zita-at1
DISTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Autotuner Jack application
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/zita-at1-doc/quickguide.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	fftw3>=0:math/fftw3
LIB_DEPENDS=	libclthreads.so:devel/clthreads \
		libclxclient.so:devel/clxclient \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libpng16.so:graphics/png \
		libzita-resampler.so:audio/zita-resampler

USES=		gmake gnome localbase:ldflags pkgconfig tar:bz2 xorg
USE_GNOME=	cairo
USE_XORG=	x11 xft

WRKSRC_SUBDIR=	source

# zita-at1 crashes when compiled with clang-11.0.1 with -march=native which is now patched out

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
