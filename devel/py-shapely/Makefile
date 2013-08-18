# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Shapely
PORTVERSION=	1.2.18
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Package for Manipulation 2D Geospatial Geometry

LIB_DEPENDS=	geos_c:${PORTSDIR}/graphics/geos

CFLAGS+=	-I${LOCALBASE}/include
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
