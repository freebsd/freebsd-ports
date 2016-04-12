# $FreeBSD$

PORTNAME=	Persistence
PORTVERSION=	2.13.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Persistent ExtensionClass

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
