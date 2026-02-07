PORTNAME=	zita-mu1
DISTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple Jack app used to organise stereo monitoring
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/zita-mu1-doc/quickguide.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libclthreads.so:devel/clthreads \
		libclxclient.so:devel/clxclient \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libpng16.so:graphics/png

USES=		gmake gnome localbase:ldflags pkgconfig tar:bz2 xorg
USE_GNOME=	cairo
USE_XORG=	x11 xft

WRKSRC_SUBDIR=	source

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
