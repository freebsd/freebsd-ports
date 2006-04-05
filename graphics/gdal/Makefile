# New ports collection makefile for:	Geospatial Data Abstraction Library
# Date created:		27 Aug 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.3.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/gdal/ \
		http://www.gdal.org/dl/ \
		http://dl.maptools.org/dl/gdal/

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	A translator library for geospatial data formats

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
LIB_DEPENDS=	jasper.4:${PORTSDIR}/graphics/jasper \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		geotiff.1:${PORTSDIR}/graphics/libgeotiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libz=/usr \
		--with-png=${LOCALBASE} \
		--with-libtiff=${LOCALBASE} \
		--with-libgeotiff=${LOCALBASE} \
		--with-libjpeg=${LOCALBASE} \
		--with-libgif=${LOCALBASE} \
		--with-jasper=${LOCALBASE} \
		--with-python
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes

MAN1=		gdal-config.1 gdal_utilities.1 gdalwarp.1 ogrtindex.1 \
		gdal_contour.1 gdaladdo.1 ogr2ogr.1 pct2rgb.py.1 \
		gdal_merge.py.1 gdalinfo.1 ogr_utilities.1 rgb2pct.py.1 \
		gdal_translate.1 gdaltindex.1 ogrinfo.1

post-patch:
		@${REINPLACE_CMD} -e 's|6LIBZ|6|;;s|lgif|lungif|' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=--without-pcraster
.endif

.include <bsd.port.post.mk>
