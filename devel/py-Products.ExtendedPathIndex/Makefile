# $FreeBSD$

PORTNAME=	Products.ExtendedPathIndex
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope catalog index for paths

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>0:${PORTSDIR}/security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}transaction>0:${PORTSDIR}/devel/py-transaction \
		zodb${PYTHON_PKGNAMESUFFIX}>0:${PORTSDIR}/databases/zodb3

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_ZIP=		yes
USES=			zope

.include <bsd.port.mk>
