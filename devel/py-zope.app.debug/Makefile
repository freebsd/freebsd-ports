# $FreeBSD$

PORTNAME=	zope.app.debug
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Debug Mode

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=0:devel/py-zope.app.appsetup \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:devel/py-zope.app.publication

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
