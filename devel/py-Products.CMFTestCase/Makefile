# New ports collection makefile for:	py-Products.CMFTestCase
# Date created:				20 December 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	Products.CMFTestCase
PORTVERSION=	0.9.11
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Integration testing framework for CMF

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCalendar>=0:${PORTSDIR}/devel/py-Products.CMFCalendar \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.CMFDefault>=0:${PORTSDIR}/devel/py-Products.CMFDefault \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3

DIST_SUBDIR=	zope
USE_PYTHON=	2.6+
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
