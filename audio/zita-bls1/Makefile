PORTNAME=	zita-bls1
DISTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Blumlein Shuffler converter of binaural signals to stereo speaker pair
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/zita-bls1-doc/quickguide.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libclthreads.so:devel/clthreads \
		libclxclient.so:devel/clxclient \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libpng16.so:graphics/png \
		libzita-convolver.so:audio/zita-convolver

USES=		gmake gnome localbase:ldflags pkgconfig tar:bz2 xorg
USE_GNOME=	cairo
USE_XORG=	x11 xft

WRKSRC_SUBDIR=	source

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
