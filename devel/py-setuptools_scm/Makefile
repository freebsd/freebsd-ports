PORTNAME=	setuptools_scm
PORTVERSION=	6.4.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Setuptools plugin to manage your versions by scm tags

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=1.0.0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=1.0.0:textproc/py-tomli@${PY_FLAVOR}
TEST_DEPENDS=	git:devel/git \
		${PY_MERCURIAL} \
		${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

# Workaround to get a 100% working test suite.  This can be removed once
# https://github.com/pypa/setuptools_scm/issues/353 is solved.
TEST_ENV=	_PYTEST_SESSION=yes

NO_ARCH=	yes

# Skip integration tests that require a more recent version of py-virtualenv
post-extract:
	@${MV} ${WRKSRC}/testing/test_setuptools_support.py ${WRKSRC}/testing/test_setuptools_support.py.dist

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' ${WRKSRC}/testing/test_integration.py

# Note: The test suite requires at least py-pytest >= 6.2.0 due changes to the
# "monkeypatch" functionality.  Tests are fine with py-pytest 7.0.0.
do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
