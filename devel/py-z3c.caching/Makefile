# $FreeBSD$

PORTNAME=	z3c.caching
PORTVERSION=	2.0a1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Caching infrastructure for web apps

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>=0:devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
