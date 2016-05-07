# $FreeBSD$

PORTNAME=	fsm
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	python-${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Pure Python Implementation of a Finite State Machine

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.0:graphics/py-pygraphviz

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_EGGINFO=	python_${PORTNAME}-${PORTVERSION:C/\.0/./}-py${PYTHON_VER}.egg-info

.include <bsd.port.mk>
