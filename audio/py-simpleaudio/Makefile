PORTNAME=	simpleaudio
DISTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	audio
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple, asynchronous audio playback for Python 3
WWW=		https://github.com/hamiltron/py-simple-audio

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libasound.so:audio/alsa-lib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyaudio>0:audio/py-pyaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	hamiltron
GH_PROJECT=	py-simple-audio

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/simpleaudio/_simpleaudio${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
