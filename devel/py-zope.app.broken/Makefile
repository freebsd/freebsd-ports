# $FreeBSD$

PORTNAME=	zope.app.broken
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Broken (ZODB) Object Support

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:devel/py-zope.annotation@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.broken>=0:devel/py-zope.broken@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:devel/py-zope.processlifetime@${FLAVOR} \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
