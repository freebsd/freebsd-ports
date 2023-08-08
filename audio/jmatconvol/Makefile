PORTNAME=	jmatconvol
DISTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Real-time convolution engine for dense matrix of short convolutions
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile

USES=		gmake localbase:ldflags tar:bz2

WRKSRC_SUBDIR=	source

EXES=		bin/fmatconvol \
		bin/jmatconvol

PLIST_FILES=	${EXES}

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${EXES}

.include <bsd.port.mk>
