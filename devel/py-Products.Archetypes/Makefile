# $FreeBSD$

PORTNAME=	Products.Archetypes
PORTVERSION=	1.9.4
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Developers framework for rapidly implementing content types

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:${PORTSDIR}/devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.datetime>=0:${PORTSDIR}/devel/py-zope.datetime \
		${PYTHON_PKGNAMEPREFIX}zope.deferredimport>=0:${PORTSDIR}/devel/py-zope.deferredimport \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:${PORTSDIR}/devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:${PORTSDIR}/devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.tal>=0:${PORTSDIR}/textproc/py-zope.tal \
		${PYTHON_PKGNAMEPREFIX}zope.viewlet>=0:${PORTSDIR}/devel/py-zope.viewlet \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCalendar>=0:${PORTSDIR}/devel/py-Products.CMFCalendar \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>=0:${PORTSDIR}/devel/py-Products.CMFDefault \
		${PYTHON_PKGNAMEPREFIX}Products.CMFFormController>=0:${PORTSDIR}/devel/py-Products.CMFFormController \
		${PYTHON_PKGNAMEPREFIX}Products.CMFQuickInstallerTool>=0:${PORTSDIR}/devel/py-Products.CMFQuickInstallerTool \
		${PYTHON_PKGNAMEPREFIX}Products.DCWorkflow>=0:${PORTSDIR}/devel/py-Products.DCWorkflow \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.Marshall>=0:${PORTSDIR}/devel/py-Products.Marshall \
		${PYTHON_PKGNAMEPREFIX}Products.MimetypesRegistry>=2.0.3:${PORTSDIR}/devel/py-Products.MimetypesRegistry \
		${PYTHON_PKGNAMEPREFIX}Products.PlacelessTranslationService>=0:${PORTSDIR}/devel/py-Products.PlacelessTranslationService \
		${PYTHON_PKGNAMEPREFIX}Products.PortalTransforms>=0:${PORTSDIR}/devel/py-Products.PortalTransforms \
		${PYTHON_PKGNAMEPREFIX}Products.statusmessages>=0:${PORTSDIR}/devel/py-Products.statusmessages \
		${PYTHON_PKGNAMEPREFIX}Products.validation>=0:${PORTSDIR}/devel/py-Products.validation \
		${PYTHON_PKGNAMEPREFIX}plone.folder>=0:${PORTSDIR}/www/py-plone.folder \
		${PYTHON_PKGNAMEPREFIX}plone.uuid>=0:${PORTSDIR}/www/py-plone.uuid \
		${PYTHON_PKGNAMEPREFIX}plone.app.folder>=0:${PORTSDIR}/www/py-plone.app.folder \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:${PORTSDIR}/devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:${PORTSDIR}/devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}Products.ZSQLMethods>0:${PORTSDIR}/devel/py-Products.ZSQLMethods

DIST_SUBDIR=	zope
USE_PYTHON=	2
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes
USES=		zope

NO_STAGE=	yes

.include <bsd.port.mk>
