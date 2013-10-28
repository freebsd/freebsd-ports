# Created by: Denis Generalov <gd@rambler-co.ru>
# $FreeBSD$

PORTNAME=	pyev
PORTVERSION=	0.9.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=	source/p/pyev
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gd.workbox@gmail.com
COMMENT=	Python libev interface

LICENSE=	GPLv3

LIB_DEPENDS=	libev.so:${PORTSDIR}/devel/libev

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=yes
PYDISTUTILS_PKGVERSION=${PORTVERSION}${DISTVERSIONSUFFIX}

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

.include <bsd.port.mk>
