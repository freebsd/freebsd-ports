PORTNAME=	qtconsole
PORTVERSION=	5.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Qt-based console for Jupyter with support for rich media output

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipykernel5>=5.1:devel/py-ipykernel5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-client>=4.1:devel/py-jupyter-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter-core>=0:devel/py-jupyter-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=17.1:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython_genutils>=0:devel/py-ipython_genutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}QtPy>0:devel/py-QtPy@${PY_FLAVOR}

USES=		pyqt:5 python:3.7+

USE_PYQT=	sip pyqt5
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
