# $FreeBSD$

PORTNAME=	Products.CMFUid
PORTVERSION=	2.2.1
PORTREVISION=	2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Uid product for the Zope CMF

LICENSE=	ZPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}eggtestinfo>0:devel/py-eggtestinfo
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.CMFCore>=0:devel/py-Products.CMFCore \
		${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:devel/py-Products.GenericSetup

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
