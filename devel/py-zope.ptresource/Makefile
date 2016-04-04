# $FreeBSD$

PORTNAME=	zope.ptresource
PORTVERSION=	3.9.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Page template resource plugin for zope.browserresource

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.browserresource>=0:devel/py-zope.browserresource \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:devel/py-zope.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
