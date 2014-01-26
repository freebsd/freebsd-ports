# $FreeBSD$

PORTNAME=	Products.PluginRegistry
PORTVERSION=	1.3
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Configure application plugins based on interfaces

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
#USES=			zope

.include <bsd.port.mk>
