# $FreeBSD$

PORTNAME=	cq-editor
DISTVERSION=	0.1.2
PORTREVISION=	6
CATEGORIES=	cad
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	CadQuery GUI editor based on PyQT

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cadquery>=0:cad/py-cadquery@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/spyder/__init__.py:devel/py-spyder

USES=		pyqt:5 python:3.6+
USE_PYTHON=	autoplist distutils
USE_PYQT=	core gui widgets

USE_GITHUB=	yes
GH_ACCOUNT=	CadQuery
GH_PROJECT=	CQ-editor

.include <bsd.port.mk>
