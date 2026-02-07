PORTNAME=	xastir
DISTVERSIONPREFIX=	Release-
DISTVERSION=	2.2.2
CATEGORIES=	comms hamradio

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	X Amateur Station Tracking and Information Reporting
WWW=		https://github.com/Xastir/Xastir/wiki

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xfontsel:x11-fonts/xfontsel
RUN_DEPENDS=	wget:ftp/wget
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libjasper.so:graphics/jasper \
		libjbig.so:graphics/jbigkit \
		liblcms2.so:graphics/lcms2 \
		libshp.so:devel/shapelib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libwebpmux.so:graphics/webp \
		libwmflite.so:graphics/libwmf \
		libpcre2-8.so:devel/pcre2 \
		libjxl.so:graphics/libjxl \
		libjxl_threads.so:graphics/libjxl \
		libproj.so:graphics/proj \
		libGraphicsMagick.so:graphics/GraphicsMagick

USES=		autoreconf gmake gnome jpeg motif shebangfix xorg bdb:18

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

CONFIGURE_ARGS=	--with-bdb-libdir=${BDB_LIB_DIR} \
		--with-bdb-incdir=${BDB_INCLUDE_DIR} \
		--with-graphicsmagick

OPTIONS_DEFINE=		DOCS CURL DAVIS ERRORPOP FESTIVAL GEOTIFF GPSMAN

DAVIS_DESC=	Include Davis Weatherstation Support
CURL_DESC=	Include CURL Internet Image support
GEOTIFF_DESC=	Include GeoTIFF Support
GPSMAN_DESC=	Include GPSMAN Support
FESTIVAL_DESC=	Include Festival Voice Synthesis Support
ERRORPOP_DESC=	Send error popups to stderr

OPTIONS_DEFAULT=	CURL GEOTIFF

DAVIS_CONFIGURE_ON=	--enable-davis

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

GEOTIFF_LIB_DEPENDS=	libgeotiff.so:graphics/libgeotiff

GPSMAN_BUILD_DEPENDS=	${LOCALBASE}/share/doc/gpsmanshp/GPSManSHP.pdf:graphics/gpsmanshp
GPSMAN_CONFIGURE_WITH=	gpsman

FESTIVAL_BUILD_DEPENDS=		festival:audio/festival
FESTIVAL_CONFIGURE_WITH=	festival

ERRORPOP_CONFIGURE_WITH=	errorpopups

.include <bsd.port.mk>
