PORTNAME=	qtconsole
DISTVERSION=	5.6.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Qt-based console for Jupyter with support for rich media output
WWW=		https://qtconsole.readthedocs.io/en/stable/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel>=4.1:devel/py-ipykernel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=4.1:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>0:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>=2.4.0:devel/py-QtPy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flaky>0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-qt>0:devel/py-pytest-qt@${PY_FLAVOR}

USES=		pyqt:5 python
USE_PYQT=	pyqt5 sip
USE_PYTHON=	autoplist distutils pytest

NO_ARCH=	yes

.include <bsd.port.mk>
