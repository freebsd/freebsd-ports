# $FreeBSD$

PORTNAME=	Products.PortalTransforms
PORTVERSION=	2.1.10
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	MIME based content transformations

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plone.intelligenttext>=0:${PORTSDIR}/www/py-plone.intelligenttext \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.structuredtext>=0:${PORTSDIR}/textproc/py-zope.structuredtext \
		${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:${PORTSDIR}/devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.MimetypesRegistry>=0:${PORTSDIR}/devel/py-Products.MimetypesRegistry \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}markdown>=1.7:${PORTSDIR}/textproc/py-markdown

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
