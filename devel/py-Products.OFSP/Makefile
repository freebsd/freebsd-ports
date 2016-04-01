# $FreeBSD$

PORTNAME=	Products.OFSP
PORTVERSION=	2.13.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	General Zope 2 help screens

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=0:security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:devel/py-Persistence

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
