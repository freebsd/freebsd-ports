# New ports collection makefile for:	Geospatial Data Abstraction Library
# Date created:		27 Aug 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.1.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/gdal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A translator library for raster geospatial data formats

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_PYTHON=     yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libz=internal \
		--with-png=internal \
		--with-libtiff=internal \
		--with-libgeotiff=internal \
		--with-libjpeg=internal \
		--with-libgif=internal \
		--with-python
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
