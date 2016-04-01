# $FreeBSD$

PORTNAME=	Products.Archetypes
PORTVERSION=	1.9.10
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Developers framework for rapidly implementing content types

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.datetime>=0:devel/py-zope.datetime \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:devel/py-zope.deferredimport \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:textproc/py-zope.tal \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCalendar>=0:devel/py-Products.CMFCalendar \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>=0:devel/py-Products.CMFDefault \
		${PYTHON_PKGNAMEPREFIX}Products.CMFFormController>=0:devel/py-Products.CMFFormController \
		${PYTHON_PKGNAMEPREFIX}Products.CMFQuickInstallerTool>=0:devel/py-Products.CMFQuickInstallerTool \
		${PYTHON_PKGNAMEPREFIX}Products.DCWorkflow>=0:devel/py-Products.DCWorkflow \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.Marshall>=0:devel/py-Products.Marshall \
		${PYTHON_PKGNAMEPREFIX}Products.MimetypesRegistry>=2.0.3:devel/py-Products.MimetypesRegistry \
		${PYTHON_PKGNAMEPREFIX}Products.PlacelessTranslationService>=0:devel/py-Products.PlacelessTranslationService \
		${PYTHON_PKGNAMEPREFIX}Products.PortalTransforms>=0:devel/py-Products.PortalTransforms \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:devel/py-Products.statusmessages \
		${PYTHON_PKGNAMEPREFIX}Products.validation>=0:devel/py-Products.validation \
		${PYTHON_PKGNAMEPREFIX}plone.folder>=0:www/py-plone.folder \
		${PYTHON_PKGNAMEPREFIX}plone.uuid>=0:www/py-plone.uuid \
		${PYTHON_PKGNAMEPREFIX}plone.app.folder>=0:www/py-plone.app.folder \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}Products.ZSQLMethods>0:devel/py-Products.ZSQLMethods

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python zope

.include <bsd.port.mk>
