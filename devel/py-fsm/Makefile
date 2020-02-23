# $FreeBSD$

PORTNAME=	fsm
PORTVERSION=	0.01
PORTREVISION=	2
CATEGORIES=	devel python

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Pure Python Implementation of a Finite State Machine

LICENSE=	BSD3CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USE_GITHUB=	yes
GH_ACCOUNT=	oozie
GH_PROJECT=	python-fsm
GH_TAGNAME=	bf888123

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygraphviz>=1.0:graphics/py-pygraphviz@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
