# $FreeBSD$

PORTNAME=	Products.CMFEditions
PORTVERSION=	2.2.19
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Versioning for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.copy>0:devel/py-zope.copy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:devel/py-zope.dottedname@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=2.1:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDiffTool>=0:devel/py-Products.CMFDiffTool@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFUid>=0:devel/py-Products.CMFUid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=1.4.0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ZopeVersionControl>=0:devel/py-Products.ZopeVersionControl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${FLAVOR}

NO_ARCH=	yes
USES=		python:2.7 zope
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
