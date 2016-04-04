# $FreeBSD$

PORTNAME=	Products.MimetypesRegistry
PORTVERSION=	2.0.8
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	MIME type handling for Zope

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

USES=		python:2 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
