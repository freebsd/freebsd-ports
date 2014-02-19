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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=0:${PORTSDIR}/devel/py-zope.app.appsetup \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:${PORTSDIR}/devel/py-zope.app.publication

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
