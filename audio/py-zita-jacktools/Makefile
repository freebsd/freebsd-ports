PORTNAME=	zita-jacktools
DISTVERSION=	1.7.2
CATEGORIES=	audio python
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Audio tools running as a Jack client
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	zita-jclient>0:audio/zita-jclient
LIB_DEPENDS=	libjack.so:audio/jack \
		libfftw3f.so:math/fftw3-float \
		libsndfile.so:audio/libsndfile \
		libzita-convolver.so:audio/zita-convolver \
		libzita-resampler.so:audio/zita-resampler
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zita-audiotools>0:audio/py-zita-audiotools@${PY_FLAVOR}

USES=		localbase python tar:bz2
USE_PYTHON=	autoplist distutils

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/zita_jacktools/*.so

.include <bsd.port.mk>
