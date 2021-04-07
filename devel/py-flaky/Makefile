PORTNAME=	flaky
DISTVERSION=	3.7.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Plugin for nose or pytest that automatically reruns flaky tests

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}genty>0:devel/py-genty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && \
		${PYTHON_CMD} -m nose -v --no-flaky-report \
	       		--with-flaky --exclude="test_nose_options_example" test/test_nose/ && \
		${PYTHON_CMD} -m pytest -v -rs --no-flaky-report \
			-k 'example and not options' -n 1 test/test_pytest && \
		${PYTHON_CMD} -m pytest -v -rs \
	       		-p no:flaky test/test_pytest/test_flaky_pytest_plugin.py && \
		${PYTHON_CMD} -m nose -v --no-flaky-report \
	       		--with-flaky --force-flaky --max-runs 2 test/test_nose/test_nose_options_example.py && \
		${PYTHON_CMD} -m pytest -v -rs --no-flaky-report \
			--force-flaky --max-runs 2 test/test_pytest/test_pytest_options_example.py

.include <bsd.port.mk>
