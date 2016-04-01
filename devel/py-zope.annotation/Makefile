# $FreeBSD$

PORTNAME=	zope.annotation
PORTVERSION=	3.5.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Object annotation mechanism

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=0:net/py-zope.proxy \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
