# $FreeBSD$

PORTNAME=	Products.CMFCore
PORTVERSION=	2.2.10
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Content Management Framework core components

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eggtestinfo>0:devel/py-eggtestinfo@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:devel/py-five.localsitemanager@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZSQLMethods>0:devel/py-Products.ZSQLMethods@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>0:devel/py-zope.app.publication@${FLAVOR}

NO_ARCH=	yes
#USES=		zope # cyclic dependency
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
