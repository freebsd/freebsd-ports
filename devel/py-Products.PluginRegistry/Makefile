# $FreeBSD$

PORTNAME=	Products.PluginRegistry
PORTVERSION=	1.3
PORTEPOCH=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Configure application plugins based on interfaces

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Products.GenericSetup>=0:${PORTSDIR}/devel/py-Products.GenericSetup

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
#USE_ZOPE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
