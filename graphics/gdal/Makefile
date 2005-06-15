# New ports collection makefile for:	Geospatial Data Abstraction Library
# Date created:		27 Aug 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/gdal/

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	A translator library for raster geospatial data formats

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
LIB_DEPENDS=	jasper.4:${PORTSDIR}/graphics/jasper \
		png.5:${PORTSDIR}/graphics/png

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libz=internal \
		--with-png=${LOCALBASE} \
		--with-libtiff=internal \
		--with-libgeotiff=internal \
		--with-libjpeg=internal \
		--with-libgif=internal \
		--with-jasper=${LOCALBASE} \
		--with-python
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes

MAN1=		gdaladdo.1 gdalinfo.1 gdaltindex.1 gdalwarp.1 \
		gdal-config.1 gdal_translate.1 ogrinfo.1 \
		ogrtindex.1 ogr2ogr.1

post-patch:
	@${REINPLACE_CMD} -e 's|6LIBZ|6|' ${WRKSRC}/configure

.include <bsd.port.mk>
