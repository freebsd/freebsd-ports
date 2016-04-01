# $FreeBSD$

PORTNAME=	zope.globalrequest
PORTVERSION=	1.1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Global way of retrieving the currently active request

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>0:devel/py-zope.traversing

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
