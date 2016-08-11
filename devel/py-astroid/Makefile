# $FreeBSD$

PORTNAME=	astroid
PORTVERSION=	1.4.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Extension for Python compiler.ast module

LICENSE=	LGPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wrapt>0:devel/py-wrapt \
		${PYTHON_PKGNAMEPREFIX}lazy-object-proxy>0:devel/py-lazy-object-proxy

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
