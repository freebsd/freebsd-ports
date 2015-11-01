# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Shapely
PORTVERSION=	1.5.13
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Package for Manipulation 2D Geospatial Geometry

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libgeos_c.so:${PORTSDIR}/graphics/geos

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
