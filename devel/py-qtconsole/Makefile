# $FreeBSD$

PORTNAME=	qtconsole
PORTVERSION=	4.3.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Qt-based console for Jupyter with support for rich media output

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_core>=0:devel/py-jupyter_core@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=4.1:devel/py-jupyter_client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=4.1:devel/py-ipykernel@${FLAVOR}

USES=		pyqt:4 python
USE_PYQT=	core gui svg

USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
