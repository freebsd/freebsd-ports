PORTNAME=	pyqtgraph
DISTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	graphics science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/pyqtgraph/pyqtgraph/commit/
PATCHFILES=	935914143d87f28575ea9d60bd9efada57b3bdd6.patch:-p1 # Fix renderView to not use mremap on FreeBSD, see https://github.com/pyqtgraph/pyqtgraph/pull/2445/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scientific graphics and GUI library for Python
WWW=		https://www.pyqtgraph.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}colorcet>0:graphics/py-colorcet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}qt5-pyqt>0:devel/py-qt5-pyqt@${PY_FLAVOR} # PyQtGraph requires one of PyQt5, PyQt6, PySide2 or PySide6

USES=		python:3.8+
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
