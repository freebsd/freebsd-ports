# $FreeBSD$

PORTNAME=	zope.app.error
PORTVERSION=	3.5.3
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Error reporting utility management UI for Zope3

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.error>=0:devel/py-zope.error \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
