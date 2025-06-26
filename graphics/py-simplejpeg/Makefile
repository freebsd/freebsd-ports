PORTNAME=	simplejpeg
DISTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple package for fast JPEG encoding and decoding
WWW=		https://gitlab.com/jfolz/simplejpeg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	autoplist cython3 pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test

post-extract: # force cythonization because pre-cythonized _jpeg.c fails to compile
	@${RM} ${WRKSRC}/simplejpeg/_jpeg.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/simplejpeg/_jpeg${PYTHON_TAG}.so

# tests as of 1.8.0: 61 passed in 10.57s

.include <bsd.port.mk>
