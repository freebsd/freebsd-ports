# $FreeBSD$

PORTNAME=	zope.processlifetime
PORTVERSION=	1.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope process lifetime events

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

NO_STAGE=	yes

.include <bsd.port.mk>
