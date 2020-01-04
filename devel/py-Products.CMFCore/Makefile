# $FreeBSD$

PORTNAME=	Products.CMFCore
PORTVERSION=	2.2.10
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Content Management Framework core components

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-05

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eggtestinfo>0:devel/py-eggtestinfo@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:devel/py-five.localsitemanager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZSQLMethods>0:devel/py-Products.ZSQLMethods@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>0:devel/py-zope.app.publication@${PY_FLAVOR}

NO_ARCH=	yes
#USES=		zope # cyclic dependency
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
