# $FreeBSD$

PORTNAME=	Products.ZopeVersionControl
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Version Control

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}transaction>=0:devel/py-transaction \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
