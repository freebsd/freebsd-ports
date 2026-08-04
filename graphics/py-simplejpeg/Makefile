PORTNAME=	simplejpeg
DISTVERSION=	1.9.0
CATEGORIES=	graphics python
JPEG_VERSION=	3.1.2
MASTER_SITES=	PYPI :simplejpeg \
		https://codeload.github.com/libjpeg-turbo/libjpeg-turbo/tar.gz/${JPEG_VERSION}?dummy=/:libjpeg
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:simplejpeg \
		libjpeg-turbo-${JPEG_VERSION}.tar.gz:libjpeg
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple package for fast JPEG encoding and decoding
WWW=		https://gitlab.com/jfolz/simplejpeg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nasm:devel/nasm \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	autoplist cython pep517 pytest

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PYTEST_ADDOPTS="-p no:black -p no:ruff -p no:mypy -p no:flake8 -p no:cov"
TEST_WRKSRC=	${WRKSRC}/test

post-extract: # force cythonization because pre-cythonized _jpeg.c fails to compile
	@${MKDIR} ${WRKSRC}/lib
	@${CP} ${DISTDIR}/libjpeg-turbo-${JPEG_VERSION}.tar.gz ${WRKSRC}/lib/
	@${RM} ${WRKSRC}/simplejpeg/_jpeg.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/simplejpeg/_jpeg${PYTHON_TAG}.so

# tests as of 1.9.0: 70 passed in 5.98s

.include <bsd.port.mk>
