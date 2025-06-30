PORTNAME=	xastir
DISTVERSIONPREFIX=	Release-
DISTVERSION=	2.2.0
PORTREVISION=	9
CATEGORIES=	comms hamradio

MAINTAINER=	carl@stagecraft.cx
COMMENT=	X Amateur Station Tracking and Information Reporting
WWW=		http://www.xastir.org/

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
		libwmflite.so:graphics/libwmf \
		libpcre2-8.so:devel/pcre2 \
		libjxl.so:graphics/libjxl \
		libjxl_threads.so:graphics/libjxl

USES=		autoreconf gmake gnome jpeg motif shebangfix xorg

USE_XORG=	ice sm x11 xext xt
USE_GNOME+=	libxml2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

SHEBANG_FILES=	scripts/gpx2shape
SHEBANG_REGEX=	./scripts/.*\.(sh|pl|py)

USE_GITHUB=	yes
GH_ACCOUNT=	Xastir
GH_PROJECT=	Xastir

SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--without-map-cache

OPTIONS_DEFINE=		CURL DAVIS ERRORPOP FESTIVAL GEOTIFF GPSMAN
OPTIONS_RADIO=		MGG
OPTIONS_RADIO_MGG=	GMAGICK IMAGICK

DAVIS_DESC=	Include Davis Weatherstation Support
CURL_DESC=	Include CURL Internet Image support
GEOTIFF_DESC=	Include GeoTIFF Support
GPSMAN_DESC=	Include GPSMAN Support
FESTIVAL_DESC=	Include Festival Voice Synthesis Support
ERRORPOP_DESC=	Send error popups to stderr
MGG_DESC=	Image library for raster map processing
IMAGICK_DESC=	ImageMagick (Version 6)
GMAGICK_DESC=	GraphicsMagick (Needs GCC to compile)

OPTIONS_DEFAULT=	CURL GMAGICK

DAVIS_CONFIGURE_ON=	--enable-davis

IMAGICK_USES=		magick:6
IMAGICK_CONFIGURE_WITH=	imagemagick

GMAGICK_LIB_DEPENDS=	libGraphicsMagickWand.so:graphics/GraphicsMagick
GMAGICK_CONFIGURE_WITH=	graphicsmagick
GMAGICK_USES=		compiler:gcc-c++11-lib

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

GEOTIFF_LIB_DEPENDS=	libgeotiff.so:graphics/libgeotiff

GPSMAN_BUILD_DEPENDS=	${LOCALBASE}/share/doc/gpsmanshp/GPSManSHP.pdf:graphics/gpsmanshp
GPSMAN_IMPLIES=		SHAPELIB
GPSMAN_CONFIGURE_WITH=	gpsman

FESTIVAL_BUILD_DEPENDS=		festival:audio/festival
FESTIVAL_CONFIGURE_WITH=	festival

#RTREE_CONFIGURE_WITH=	rtree

ERRORPOP_CONFIGURE_WITH=	errorpopups

.include <bsd.port.mk>
