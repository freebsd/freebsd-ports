# $FreeBSD$

PORTNAME=	zope.location
PORTVERSION=	3.9.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Location

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=3.8:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>3.3:net/py-zope.proxy \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=3.6:devel/py-zope.schema

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
