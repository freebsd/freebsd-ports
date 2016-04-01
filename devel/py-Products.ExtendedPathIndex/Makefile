# $FreeBSD$

PORTNAME=	Products.ExtendedPathIndex
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope catalog index for paths

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>0:security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}transaction>0:devel/py-transaction \
		zodb${PYTHON_PKGNAMESUFFIX}>0:databases/zodb3

USES=		python zope zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
