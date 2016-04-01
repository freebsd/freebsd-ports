# $FreeBSD$

PORTNAME=	zope.site
PORTVERSION=	3.9.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Local registries for zope component architecture

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.component>=3.8.0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.location>=3.7.0:devel/py-zope.location

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
