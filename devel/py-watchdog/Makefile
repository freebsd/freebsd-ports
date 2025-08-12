PORTNAME=	watchdog
DISTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python API library to monitor file system events
WWW=		https://github.com/gorakhargosh/watchdog

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.42.0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libinotify.so:devel/libinotify
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=3.10:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eventlet>0:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=5.13.2:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>=1.8.0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>=0.9.6_1:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-pyyaml>=6.0.12.12:devel/py-types-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

# FileNotFoundError: [Errno 2] No such file or directory: /tmp/tmp*
# src/watchdog/utils/dirsnapshot.py:318: FileNotFoundError
PYTEST_BROKEN_TESTS=	test_observers_polling
# NotImplementedError: unsupported platform
# site-packages/trio/_core/_run.py:2843: NotImplementedError
PYTEST_IGNORED_TESTS=	test_eventlet_monkey_patching
# tests: 147 passed, 13 skipped, 2 deselected
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}

post-build-DOCS-on:
	(cd ${WRKSRC}/docs ; ${MAKE_CMD} SPHINXBUILD=sphinx-build-${PYTHON_VER} html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/build/html ; \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -name .buildinfo")

.include <bsd.port.mk>
