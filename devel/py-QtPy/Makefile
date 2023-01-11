PORTNAME=	QtPy
DISTVERSION=	2.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Abstraction layer on top of the various Qt bindings
WWW=		https://github.com/spyder-ide/qtpy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}qt5-pyqt>0:devel/py-qt5-pyqt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-qt>0:devel/py-pytest-qt@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist pytest # 1 test fails, see https://github.com/spyder-ide/qtpy/issues/371

NO_ARCH=	yes

.include <bsd.port.mk>
