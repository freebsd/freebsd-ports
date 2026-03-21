PORTNAME=	e3_testsuite
DISTVERSION=	27.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	agh@riseup.net
COMMENT=	Generic testsuite framework in Python
WWW=		https://pypi.org/project/e3-testsuite/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}e3-core>0:devel/py-e3-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}e3-core>0:devel/py-e3-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

EXTRACT_AFTER_ARGS=	${_DIST_EXCLUDES:S,^,--exclude ,}

NO_ARCH=	yes

# Conflicts with ${LOCALBASE}/lib/python3.11/site-packages/e3/py.typed from
# devel/py-e3-core, it can be inherited via devel/py-e3-core ${RUN_DEPENDS}
_DIST_EXCLUDES=	src/e3/py.typed

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PATH=${STAGEDIR}${PREFIX}/bin/:${PATH}
DO_MAKE_TEST=	${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m ${TEST_TARGET}
TEST_TARGET=	pytest

.include <bsd.port.mk>
