PORTNAME=	loky
DISTVERSION=	3.6.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Robust implementation of concurrent.futures.ProcessPoolExecutor
WWW=		https://loky.readthedocs.io/ \
		https://github.com/joblib/loky

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload
TEST_ARGS+=	-k "not test_no_failure_on_large_data_send" # crashes, see https://github.com/joblib/loky/issues/665

# tests as of 3.6.0: 6 failed, 319 passed, 20 skipped, 3 deselected, 6 warnings in 215.91s (0:03:35)

.include <bsd.port.mk>
