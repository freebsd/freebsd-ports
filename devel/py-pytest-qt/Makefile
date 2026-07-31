PORTNAME=	pytest-qt
DISTVERSION=	4.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTest support for PyQt and PySide applications
WWW=		https://github.com/pytest-dev/pytest-qt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pluggy>=1.1:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.1:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt6-pyqt>0:devel/py-qt6-pyqt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/pytest_qt-${DISTVERSION}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} QT_QPA_PLATFORM=offscreen
TEST_ARGS=	-p no:aiomisc -p no:relaxed

do-test: # default tests run causes a lot of Python interpreter crashes for some reason
	@cd ${WRKSRC}/tests && \
		${SETENV} ${TEST_ENV} pytest ${TEST_ARGS} .

# tests as of 4.5.0 with py312-qt6-pyqt-6.11.0: 101 failed, 75 passed, 2 skipped, 204 errors in 70.42s, see https://github.com/pytest-dev/pytest-qt/issues/457

.include <bsd.port.mk>
