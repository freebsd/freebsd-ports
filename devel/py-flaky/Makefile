PORTNAME=	flaky
DISTVERSION=	3.8.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Plugin for nose or pytest that automatically reruns flaky tests
WWW=		https://github.com/box/flaky

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# Tests were taken from https://github.com/box/flaky/blob/v3.8.1/tox.ini#L17
# The "--no-flaky-report" parameter has also been added to make the output
# a little clearer.
do-test:
	cd ${WRKSRC} && \
		${PYTHON_CMD} -m pytest -v -rs --no-flaky-report \
			-k 'example and not options' -n 1 test/test_pytest && \
		${PYTHON_CMD} -m pytest -v -rs \
	       		-p no:flaky test/test_pytest/test_flaky_pytest_plugin.py && \
		${PYTHON_CMD} -m pytest -v -rs --no-flaky-report \
			--force-flaky --max-runs 2 test/test_pytest/test_pytest_options_example.py

.include <bsd.port.mk>
