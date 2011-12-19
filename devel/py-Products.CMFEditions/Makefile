# New ports collection makefile for:	py-Products.CMFEditions
# Date created:				20 December 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	Products.CMFEditions
PORTVERSION=	2.2.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Versioning for Plone

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:${PORTSDIR}/devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:${PORTSDIR}/textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=2.1:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDiffTool>=0:${PORTSDIR}/devel/py-Products.CMFDiffTool \
		${PYTHON_PKGNAMEPREFIX}Products.CMFUid>=0:${PORTSDIR}/devel/py-Products.CMFUid \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=1.4.0:${PORTSDIR}/devel/py-Products.GenericSetup \
		${PYTHON_PKGNAMEPREFIX}Products.ZopeVersionControl>=0:${PORTSDIR}/devel/py-Products.ZopeVersionControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:${PORTSDIR}/devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:${PORTSDIR}/devel/py-transaction \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}plone.app.blob>=0:${PORTSDIR}/www/py-plone.app.blob

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
#USE_ZOPE=	yes

.include <bsd.port.mk>
