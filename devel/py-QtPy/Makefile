PORTNAME=	QtPy
DISTVERSION=	2.4.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	qtpy-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Abstraction layer on top of the various Qt bindings
WWW=		https://github.com/spyder-ide/qtpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt5-pyqt>0:devel/py-qt5-pyqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=3.0.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-qt>0:devel/py-pytest-qt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 2.4.3: 10 failed, 47 passed, 16 skipped, tests failures are due to test runners crashimng, needs to be investigated

.include <bsd.port.mk>
