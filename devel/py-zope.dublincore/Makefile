# $FreeBSD$

PORTNAME=	zope.dublincore
PORTVERSION=	3.8.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Dublin Core implementation

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
