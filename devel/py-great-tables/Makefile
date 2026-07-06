PORTNAME=	great-tables
DISTVERSION=	0.21.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	great_tables-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generate information-rich, publication-quality tables from Python
WWW=		https://github.com/posit-dev/great-tables

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.13.1:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}commonmark>=0.9.1:textproc/py-commonmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}faicons>=0.2.2:devel/py-faicons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}htmltools>=0.4.1:www/py-htmltools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-resources>0:devel/py-importlib-resources@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10.0.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}syrupy>0:devel/py-syrupy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKDIR=	${WRKSRC}/tests

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKDIR} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -p no:xdist -m 'no_pandas' \
		--ignore=${TEST_WRKDIR}/test_shiny.py

# tests as of 0.21.0: 2 passed, 2 failed (no_pandas tests fail when pandas is installed locally)

.include <bsd.port.mk>
