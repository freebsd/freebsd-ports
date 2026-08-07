PORTNAME=	ta-lib # provides Python namespace 'talib'
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # tests fail whe PYPI is used, see https://github.com/TA-Lib/ta-lib-python/issues/663
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for TA-Lib (Technical Analysis Library)
WWW=		https://ta-lib.github.io/ta-lib-python/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libta-lib.so:devel/ta-lib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}polars>0:misc/py-polars@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	TA-Lib
GH_PROJECT=	ta-lib-python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests as of 0.7.1: 46 passed in 0.60s

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/talib/_ta_lib${PYTHON_TAG}.so

.include <bsd.port.mk>
