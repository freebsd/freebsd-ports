PORTNAME=	pytest-qt
DISTVERSION=	4.4.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTest support for PyQt and PySide applications
WWW=		https://github.com/pytest-dev/pytest-qt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pluggy>=1.1:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test: # default tests run causes a lot of Python interpreter crashes for some reason
	@cd ${WRKSRC}/tests && \
		${SETENV} ${TEST_ENV} pytest .

# tests as of 4.4.0 with py311-qt6-pyqt-6.7.1: 3 failed, 376 passed, 2 skipped in 46.88s, see https://github.com/pytest-dev/pytest-qt/issues/457#issuecomment-2547408895

.include <bsd.port.mk>
