# $FreeBSD$

PORTNAME=	zope.app.exception
PORTVERSION=	3.6.3
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope 3 exception views

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.12:devel/py-zope.publisher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.authentication>=0:security/py-zope.authentication@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=1.2:devel/py-zope.browser@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>=3.11.0:devel/py-zope.browserpage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
