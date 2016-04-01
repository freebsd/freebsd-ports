# $FreeBSD$

PORTNAME=	zope.browsermenu
PORTVERSION=	3.9.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Browser menu implementation for Zope

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.browser>=0:devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.component>=3.7:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=3.7:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=3.5:devel/py-zope.pagetemplate

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
