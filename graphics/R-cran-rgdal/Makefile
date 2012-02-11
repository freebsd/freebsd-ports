# New ports collection makefile for:	R-cran-rgdal
# Date created:		2012-01-04
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rgdal
DISTVERSION=	0.7-8
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Bindings for the Geospatial Data Abstraction Library

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	gdal.16:${PORTSDIR}/graphics/gdal \
		proj.6:${PORTSDIR}/graphics/proj
RUN_DEPENDS=	R-cran-sp>=0.9.60:${PORTSDIR}/math/R-cran-sp

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

.include <bsd.port.mk>
