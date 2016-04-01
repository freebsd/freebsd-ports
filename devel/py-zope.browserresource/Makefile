# $FreeBSD$

PORTNAME=	zope.browserresource
PORTVERSION=	3.10.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Browser resources implementation for Zope

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=3.8.0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.8:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>3.7:devel/py-zope.traversing

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
