# $FreeBSD$

PORTNAME=	zope.app.folder
PORTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Folder Content Type for Zope 3

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.container>=0:${PORTSDIR}/devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.app.content>=0:${PORTSDIR}/devel/py-zope.app.content

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
