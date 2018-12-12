# Created by: Carl Makin <carl@stagecraft.cx>
# $FreeBSD$

PORTNAME=	xastir
DISTVERSIONPREFIX=	Release-
DISTVERSION=	2.1.0
PORTREVISION=	3
CATEGORIES=	comms hamradio

MAINTAINER=	carl@stagecraft.cx
COMMENT=	X Amateur Station Tracking and Information Reporting

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xfontsel:x11-fonts/xfontsel
RUN_DEPENDS=	wget:ftp/wget
LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libjbig.so:graphics/jbigkit \
		libwebp.so:graphics/webp \
		libwebpmux.so:graphics/webp \
		liblcms2.so:graphics/lcms2 \
		libfreetype.so:print/freetype2 \
		libjasper.so:graphics/jasper \
		libwmflite.so:graphics/libwmf

GNU_CONFIGURE=	yes
USES=		gettext gmake jpeg motif python:run shebangfix
USE_GCC=	yes
USE_XORG=	x11 xt xext sm ice
USE_GNOME+=	libxml2
SHEBANG_FILES=	scripts/gpx2shape scripts/values.pl.in
SHEBANG_REGEX=	./scripts/.*\.(sh|pl|py)

USE_GITHUB=	yes
GH_ACCOUNT=	Xastir
GH_PROJECT=	Xastir

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DAVIS SHAPELIB DBFAWK MAGICK CURL GEOTIFF GDAL GPSMAN FESTIVAL \
		RTREE ERRORPOP BDB

DAVIS_DESC=	Include Davis Weatherstation Support
SHAPELIB_DESC=	Include Shapelib support
DBFAWK_DESC=	Include DBFAWK Support
MAGICK_DESC=	Include GraphicsMagick Support
CURL_DESC=	Include CURL Internet Image support
GEOTIFF_DESC=	Include GeoTIFF Support
GDAL_DESC=	Include GDAL Support
GPSMAN_DESC=	Include GPSMAN Support
FESTIVAL_DESC=	Include Festival Voice Synthesis Support
RTREE_DESC=	Enable spatial indexing of shapefiles
ERRORPOP_DESC=	Send error popups to stderr
BDB_DESC=	Tiger Map Caching using Berkeley DB

OPTIONS_DEFAULT=	SHAPELIB DBFAWK MAGICK CURL RTREE BDB

DAVIS_CONFIGURE_ON=	--enable-davis

SHAPELIB_LIB_DEPENDS=	libshp.so:devel/shapelib
SHAPELIB_CONFIGURE_WITH=	shapelib

MAGICK_LIB_DEPENDS=	libGraphicsMagickWand.so:graphics/GraphicsMagick
MAGICK_CONFIGURE_WITH=	imagemagick graphicsmagick

DBFAWK_LIB_DEPENDS=	libpcre.so:devel/pcre
DBFAWK_CONFIGURE_WITH=	dbfawk

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

GEOTIFF_LIB_DEPENDS=	libgeotiff.so:graphics/libgeotiff

GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
GDAL_CONFIGURE_WITH=	gdal

GPSMAN_BUILD_DEPENDS=	${LOCALBASE}/share/doc/gpsmanshp/GPSManSHP.pdf:graphics/gpsmanshp
GPSMAN_IMPLIES=		SHAPELIB
GPSMAN_CONFIGURE_WITH=	gpsman

FESTIVAL_BUILD_DEPENDS=	festival:audio/festival
FESTIVAL_CONFIGURE_WITH=festival

RTREE_CONFIGURE_WITH=	rtree

ERRORPOP_CONFIGURE_WITH=	errorpopups

BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-bdb-incdir=${BDB_INCLUDE_DIR} --with-bdb-libdir=${BDB_LIB_DIR}

.include <bsd.port.mk>
