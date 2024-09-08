PORTNAME=	xdoctest
DISTVERSION=	1.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI # has no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python package for executing tests in documentation strings
WWW=		https://github.com/Erotemic/xdoctest

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codecov>=2.0.15:devel/py-codecov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=2.0.15:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=3.0.0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest # 2 tests fail

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test: # 2 tests fail, see https://github.com/Erotemic/xdoctest/issues/131; more failures w/out the below arguments to pytest
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -k '' -p pytester -rs -v -o addopts=

alt-test: # tests using the xdoctest executable - all tests pass this way
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${STAGEDIR}${PREFIX}/bin/xdoctest -m xdoctest

.include <bsd.port.mk>
