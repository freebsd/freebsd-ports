PORTNAME=	jconvolver
DISTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Real-time convolution engine
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libclthreads.so:devel/clthreads \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libsndfile.so:audio/libsndfile \
		libzita-convolver.so:audio/zita-convolver

USES=		gmake localbase:ldflags tar:bz2

WRKSRC_SUBDIR=	source

EXES=		bin/fconvolver \
		bin/jconvolver \
		bin/makemulti

PLIST_FILES=	${EXES}

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} ${EXES}

.include <bsd.port.mk>
