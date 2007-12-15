# New ports collection makefile for:	Geospatial Data Abstraction Library
# Date created:		27 Aug 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.4.4
CATEGORIES=	graphics geography
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/gdal/ \
		http://www.gdal.org/dl/ \
		http://dl.maptools.org/dl/gdal/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	A translator library for geospatial data formats

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
LIB_DEPENDS=	jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		geotiff.1:${PORTSDIR}/graphics/libgeotiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libz=/usr \
		--with-jasper=${LOCALBASE} \
		--with-libgeotiff=${LOCALBASE} \
		--with-libgif=${LOCALBASE} \
		--with-libjpeg=${LOCALBASE} \
		--with-libtiff=${LOCALBASE} \
		--with-png=${LOCALBASE} \
		--with-python
MAKEFILE=	GNUmakefile

MAN1=		gdal-config.1 gdal_contour.1 gdal_translate.1 \
		gdal_utilities.1 gdaladdo.1 gdalinfo.1 gdaltindex.1 \
		gdalwarp.1 ogr2ogr.1 ogr_utilities.1 ogrinfo.1 ogrtindex.1 \
		gdal_merge.1 gdal_rasterize.1 pct2rgb.1 rgb2pct.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|lgif|lungif|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
