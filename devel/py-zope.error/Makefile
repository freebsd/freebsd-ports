# $FreeBSD$

PORTNAME=	zope.error
PORTVERSION=	3.7.4
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Error reporting utility for Zope3

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.exceptions>=0:${PORTSDIR}/devel/py-zope.exceptions \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:${PORTSDIR}/devel/py-zope.location \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
