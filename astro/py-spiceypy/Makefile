PORTNAME=	spiceypy
DISTVERSIONPREFIX=	v
DISTVERSION=	8.1.0
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for the NAIF C SPICE Toolkit
WWW=		https://github.com/AndrewAnnex/SpiceyPy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR}
LIB_DEPENDS=	libcspice.so:astro/cspice
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.23.5:math/py-numpy@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	autoplist cython pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	AndrewAnnex
GH_PROJECT=	SpiceyPy

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# Tests as of 8.1.0: many tests fail because they require SPICE kernels downloaded at runtime
# The test infrastructure has issues running offline, only test import during build
# See https://github.com/AndrewAnnex/SpiceyPy for details

.include <bsd.port.mk>
