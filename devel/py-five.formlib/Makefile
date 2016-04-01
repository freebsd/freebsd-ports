# $FreeBSD$

PORTNAME=	five.formlib
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	zope.formlib integration for Zope 2

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zope.app.form>=0:devel/py-zope.app.form \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=0:devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
