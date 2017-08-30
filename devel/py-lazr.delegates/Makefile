# $FreeBSD$

PORTNAME=	lazr.delegates
PORTVERSION=	2.0.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Easily write objects that delegate behavior

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}nose>=1.3.7:devel/py-nose

USES=		python:3
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
