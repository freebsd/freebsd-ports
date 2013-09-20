# $FreeBSD$

PORTNAME=	five.globalrequest
PORTVERSION=	1.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope 2 integration for zope.globalrequest

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.globalrequest>=0:${PORTSDIR}/devel/py-zope.globalrequest

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
#USE_ZOPE=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
