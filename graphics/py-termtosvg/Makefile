# $FreeBSD$

PORTNAME=	termtosvg
PORTVERSION=	1.0.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Record terminal sessions as SVG animations

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}svgwrite>=0:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyte>=0:devel/py-pyte@${PY_FLAVOR}

USES=		python:3.3+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
