# $FreeBSD$

PORTNAME=	zope.ramcache
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope RAM Cache

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:devel/py-zope.testing \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
