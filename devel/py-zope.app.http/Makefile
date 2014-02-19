# $FreeBSD$

PORTNAME=	zope.app.http
PORTVERSION=	3.10.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	HTTP Behavior for the Zope Publisher

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.12:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:${PORTSDIR}/devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.filerepresentation>=0:${PORTSDIR}/devel/py-zope.filerepresentation

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
