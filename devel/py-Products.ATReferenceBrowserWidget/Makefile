# $FreeBSD$

PORTNAME=	Products.ATReferenceBrowserWidget
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Reference widget for Archetypes

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}archetypes.referencebrowserwidget>=0:devel/py-archetypes.referencebrowserwidget@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=0:devel/py-zope.deprecation@${FLAVOR}

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
