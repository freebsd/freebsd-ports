# $FreeBSD$

PORTNAME=	Products.Marshall
PORTVERSION=	2.1.4
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Configurable Marshallers for Archetypes

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}plone.uuid>=0:www/py-plone.uuid \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>0:devel/py-zope.deprecation \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass

USES=		python:2 zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
