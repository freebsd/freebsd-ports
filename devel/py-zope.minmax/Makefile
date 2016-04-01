# $FreeBSD$

PORTNAME=	zope.minmax
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Homogeneous values favoring maximum or minimum

LICENSE=	ZPL21

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface

USES=		python
USE_PYTHON=	distutils autoplist

post-extract:
		${CHMOD} -R a+rX ${WRKSRC}

.include <bsd.port.mk>
