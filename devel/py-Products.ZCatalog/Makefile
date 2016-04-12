# $FreeBSD$

PORTNAME=	Products.ZCatalog
PORTVERSION=	2.13.27
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope2's indexing and search solution

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=0:security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>=0:devel/py-DocumentTemplate \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}Missing>=0:devel/py-Missing \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:devel/py-Persistence \
		${PYTHON_PKGNAMEPREFIX}Products.ZCTextIndex>=0:devel/py-Products.ZCTextIndex \
		${PYTHON_PKGNAMEPREFIX}Record>=0:devel/py-Record \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:security/py-RestrictedPython \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:devel/py-zExceptions \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
