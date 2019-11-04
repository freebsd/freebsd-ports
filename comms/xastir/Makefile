# Created by: Carl Makin <carl@stagecraft.cx>
# $FreeBSD$

PORTNAME=	xastir
DISTVERSIONPREFIX=	Release-
DISTVERSION=	2.1.4
PORTREVISION=	2
CATEGORIES=	comms hamradio

MAINTAINER=	carl@stagecraft.cx
COMMENT=	X Amateur Station Tracking and Information Reporting

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xfontsel:x11-fonts/xfontsel
RUN_DEPENDS=	wget:ftp/wget
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libjasper.so:graphics/jasper \
		libjbig.so:graphics/jbigkit \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libshp.so:devel/shapelib \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libwebpmux.so:graphics/webp \
		libwmflite.so:graphics/libwmf

USES=		gettext gmake gnome jpeg motif python:run shebangfix xorg

USE_XORG=	ice sm x11 xext xt
USE_GNOME+=	libxml2
GNU_CONFIGURE=	yes

SHEBANG_FILES=	scripts/gpx2shape
SHEBANG_REGEX=	./scripts/.*\.(sh|pl|py)

USE_GITHUB=	yes
GH_ACCOUNT=	Xastir
GH_PROJECT=	Xastir

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		BDB CURL DAVIS DBFAWK ERRORPOP FESTIVAL GEOTIFF GPSMAN
OPTIONS_RADIO=		MGG
OPTIONS_RADIO_MGG=	GMAGICK IMAGICK

DAVIS_DESC=	Include Davis Weatherstation Support
DBFAWK_DESC=	Include DBFAWK Support
CURL_DESC=	Include CURL Internet Image support
GEOTIFF_DESC=	Include GeoTIFF Support
GPSMAN_DESC=	Include GPSMAN Support
FESTIVAL_DESC=	Include Festival Voice Synthesis Support
ERRORPOP_DESC=	Send error popups to stderr
BDB_DESC=	Tiger Map Caching using Berkeley DB
MGG_DESC=	Image library for raster map processing
IMAGICK_DESC=	ImageMagick (Version 6)
GMAGICK_DESC=	GraphicsMagick (Needs GCC to compile)

OPTIONS_DEFAULT=	BDB CURL DBFAWK GMAGICK

DAVIS_CONFIGURE_ON=	--enable-davis

IMAGICK_LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick6
IMAGICK_CONFIGURE_WITH=	imagemagick

GMAGICK_LIB_DEPENDS=	libGraphicsMagickWand.so:graphics/GraphicsMagick
GMAGICK_CONFIGURE_WITH=	graphicsmagick
GMAGICK_USES=		compiler:gcc-c++11-lib

DBFAWK_LIB_DEPENDS=	libpcre.so:devel/pcre
DBFAWK_CONFIGURE_WITH=	dbfawk

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

GEOTIFF_LIB_DEPENDS=	libgeotiff.so:graphics/libgeotiff

GPSMAN_BUILD_DEPENDS=	${LOCALBASE}/share/doc/gpsmanshp/GPSManSHP.pdf:graphics/gpsmanshp
GPSMAN_IMPLIES=		SHAPELIB
GPSMAN_CONFIGURE_WITH=	gpsman

FESTIVAL_BUILD_DEPENDS=		festival:audio/festival
FESTIVAL_CONFIGURE_WITH=	festival

#RTREE_CONFIGURE_WITH=	rtree

ERRORPOP_CONFIGURE_WITH=	errorpopups

BDB_USES=		bdb
BDB_CONFIGURE_ON=	--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb-libdir=${BDB_LIB_DIR}

.include <bsd.port.mk>
