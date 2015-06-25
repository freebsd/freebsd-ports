# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rgdal
DISTVERSION=	1.0-4
CATEGORIES=	graphics
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Bindings for the Geospatial Data Abstraction Library

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal \
		libproj.so:${PORTSDIR}/graphics/proj
RUN_DEPENDS=	R-cran-sp>=1.1.0:${PORTSDIR}/math/R-cran-sp

USES=	cran:auto-plist

R_POSTCMD_INSTALL_OPTIONS+=	--configure-args="--with-proj-lib=${LOCALBASE}/lib"

.include <bsd.port.mk>
