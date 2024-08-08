PORTNAME=	ta-lib # provides Python namespace 'talib'
DISTVERSIONPREFIX=	TA_Lib-
DISTVERSION=	0.4.32
CATEGORIES=	finance python
#MASTER_SITES=	PYPI # tests fail whe PYPI is used, see https://github.com/TA-Lib/ta-lib-python/issues/663
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TA-Lib-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for TA-Lib (Technical Analysis Library)
WWW=		https://ta-lib.github.io/ta-lib-python/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libta_lib.so:devel/ta-lib
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}polars>0:misc/py-polars@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest
 
USE_GITHUB=	yes
GH_ACCOUNT=	TA-Lib
GH_PROJECT=	ta-lib-python

xWRKSRC=		${WRKDIR}/ta_lib-${DISTVERSION}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/talib/_ta_lib${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
