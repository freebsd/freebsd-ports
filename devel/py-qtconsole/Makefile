# $FreeBSD$

PORTNAME=	qtconsole
PORTVERSION=	4.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Qt-based console for Jupyter with support for rich media output

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.md

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traitlets>=0:devel/py-traitlets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_core>=0:devel/py-jupyter_core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jupyter_client>=4.1:devel/py-jupyter_client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel>=4.1:devel/py-ipykernel@${PY_FLAVOR}

USES=		pyqt:4 python
USE_PYQT=	core gui svg
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
