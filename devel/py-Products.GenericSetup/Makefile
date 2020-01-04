# $FreeBSD$

PORTNAME=	Products.GenericSetup
PORTVERSION=	1.8.2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Read Zope configuration state from profile dirs / tarballs

DEPRECATED=	Outdated, uses EOLed python27
EXPIRATION_DATE=	2020-02-05

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eggtestinfo>0:devel/py-eggtestinfo@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}five.localsitemanager>=0:devel/py-five.localsitemanager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.formlib>=0:devel/py-zope.formlib@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
