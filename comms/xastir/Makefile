# Created by: Carl Makin <carl@stagecraft.cx>
# $FreeBSD$

PORTNAME=	xastir
PORTVERSION=	2.0.6
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	carl@stagecraft.cx
COMMENT=	X Amateur Station Tracking and Information Reporting

BUILD_DEPENDS=	xfontsel:${PORTSDIR}/x11-fonts/xfontsel
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng.so:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USES=		gettext gmake jpeg motif

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	SHAPELIB DBFAWK MAGICK CURL GEOTIFF GDAL GPSMAN FESTIVAL \
		    RTREE ERRORPOP BDB OPTCFLAGS

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
OPTCFLAGS_DESC=	Use optimized CFLAGS (-O2 -pipe)

OPTIONS_DEFAULT=	SHAPELIB DBFAWK MAGICK CURL RTREE BDB

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSHAPELIB}
LIB_DEPENDS+=	libshp.so:${PORTSDIR}/devel/shapelib
.else
CONFIGURE_ARGS+=	--without-shapelib
.endif

.if ${PORT_OPTIONS:MMAGICK}
LIB_DEPENDS+=	libGraphicsMagickWand.so:${PORTSDIR}/graphics/GraphicsMagick
.else
CONFIGURE_ARGS+=	--without-imagemagick --without-graphicsmagick
.endif

.if ${PORT_OPTIONS:MDBFAWK}
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--without-dbfawk
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
.endif

.if ${PORT_OPTIONS:MGEOTIFF}
LIB_DEPENDS+=	libgeotiff.so:${PORTSDIR}/graphics/libgeotiff
.endif

.if ${PORT_OPTIONS:MGDAL}
LIB_DEPENDS+=	libgdal.so:${PORTSDIR}/graphics/gdal
.else
CONFIGURE_ARGS+=	--without-gdal
.endif

.if ${PORT_OPTIONS:MGPSMAN}
BUILD_DEPENDS+=	${LOCALBASE}/share/doc/gpsmanshp/GPSManSHP.pdf:${PORTSDIR}/graphics/gpsmanshp
SHAPELIB=	true
.else
CONFIGURE_ARGS+=	--without-gpsman
.endif

.if ${PORT_OPTIONS:MFESTIVAL}
BUILD_DEPENDS+=	festival:${PORTSDIR}/audio/festival
.else
CONFIGURE_ARGS+=	--without-festival
.endif

.if ${PORT_OPTIONS:MRTREE}
CONFIGURE_ARGS+=	--with-rtree
.endif

.if ${PORT_OPTIONS:MERRORPOP}
CONFIGURE_ARGS+=	--with-errorpopups
.endif

.if ${PORT_OPTIONS:MBDB}
USE_BDB=		41+
WITH_BDB_HIGHEST=	${TRUE}
INVALID_BDB_VER=	2 3 40
CONFIGURE_ARGS+=	--with-bdb-incdir=${BDB_INCLUDE_DIR} --with-bdb-libdir=${BDB_LIB_DIR}
.endif

.if ${PORT_OPTIONS:MOPTCFLAGS}
CFLAGS+=	-O2 -pipe
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
