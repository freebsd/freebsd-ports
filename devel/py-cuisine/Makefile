# $FreeBSD$

PORTNAME=	cuisine
PORTVERSION=	0.7.13
PORTREVISION=	1
#PORTEPOCH=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Chef-like functionality for Fabric

LICENSE=	BSD3CLAUSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fabric1>=1.7,1:devel/py-fabric1@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
