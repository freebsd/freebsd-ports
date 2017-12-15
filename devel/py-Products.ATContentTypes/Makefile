# $FreeBSD$

PORTNAME=	Products.ATContentTypes
PORTVERSION=	2.1.18
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Default Content Types for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}archetypes.referencebrowserwidget>=0:devel/py-archetypes.referencebrowserwidget@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.i18n>=0:www/py-plone.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.memoize>=0:www/py-plone.memoize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plone.app.folder>=0:www/py-plone.app.folder@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.Archetypes>=0:devel/py-Products.Archetypes@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.ATReferenceBrowserWidget>=0:devel/py-Products.ATReferenceBrowserWidget@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDynamicViewFTI>=0:devel/py-Products.CMFDynamicViewFTI@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>=0:devel/py-Products.CMFDefault@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.MimetypesRegistry>=0:devel/py-Products.MimetypesRegistry@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.PortalTransforms>=0:devel/py-Products.PortalTransforms@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Products.validation>=0:devel/py-Products.validation@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zconfig>=0:devel/py-zconfig@${FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python:2.7 zope

.include <bsd.port.mk>
