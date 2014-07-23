# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Shapely
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Package for Manipulation 2D Geospatial Geometry

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libgeos_c.so:${PORTSDIR}/graphics/geos

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
