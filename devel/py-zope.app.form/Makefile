# $FreeBSD$

PORTNAME=	zope.app.form
PORTVERSION=	4.0.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	The Original Zope 3 Form Framework

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=4.0:devel/py-zope.formlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=1.1:devel/py-zope.browser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>=3.10.1:devel/py-zope.browserpage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browsermenu>=0:devel/py-zope.browsermenu@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.datetime>=0:devel/py-zope.datetime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:devel/py-zope.exceptions@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:net/py-zope.proxy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>=3.5.1:security/py-zope.security@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
