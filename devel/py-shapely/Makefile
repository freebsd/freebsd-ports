# New ports collection makefile for:	py-shapely
# Date created:				10 July 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Shapely
PORTVERSION=	1.0.14
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Package for Manipulation 2D Geospatial Geometry

LIB_DEPENDS=	geos_c.7:${PORTSDIR}/graphics/geos

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
