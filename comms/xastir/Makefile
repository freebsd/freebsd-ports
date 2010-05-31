# New ports collection makefile for:	xastir
# Date created:				17th June 2004
# Whom:					Carl Makin <carl@stagecraft.cx>
#
# $FreeBSD$
#

PORTNAME=	xastir
PORTVERSION=	1.9.8
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stable/${PORTNAME}-${PORTVERSION}

MAINTAINER=	carl@stagecraft.cx
COMMENT=	X Amateur Station Tracking and Information Reporting

BUILD_DEPENDS=	xfontsel:${PORTSDIR}/x11-fonts/xfontsel
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_MOTIF=	yes
USE_GETTEXT=	yes

MAN1=		xastir.1 \
		callpass.1 \
		testdbfawk.1 \
		xastir_udp_client.1

SUB_FILES=	pkg-message

OPTIONS=	SHAPELIB "Include Shapelib support" On \
		DBFAWK "Include DBFAWK Support" On \
		MAGICK "Include [Image|Graphics]Magick Support" On \
		GRAPHICK "Use GraphicsMagick instead of ImageMagick" Off \
		CURL "Include CURL Internet Image support" On \
		GEOTIFF "Include GeoTIFF Support" Off \
		GDAL "Include GDAL Support" Off \
		GPSMAN "Include GPSMAN Support" Off \
		FESTIVAL "Include Festival Voice Synthesis Support" Off \
		RTREE "Enable spatial indexing of shapefiles" On \
		ERRORPOP "Send error popups to stderr" Off \
		BDB "Tiger Map Caching using Berkeley DB" On \
		OPTCFLAGS "Use optimized CFLAGS (-O2 -pipe)" Off

.include <bsd.port.pre.mk>

.if defined(WITH_SHAPELIB)
LIB_DEPENDS+=	shp.1:${PORTSDIR}/devel/shapelib
.else
CONFIGURE_ARGS+=	--without-shapelib
.endif

.if defined(WITHOUT_MAGICK)
CONFIGURE_ARGS+=	--without-imagemagick --without-graphicsmagick
.else
.if defined(WITH_GRAPHICK)
LIB_DEPENDS+=	GraphicsMagickWand.3:${PORTSDIR}/graphics/GraphicsMagick
.else
LIB_DEPENDS+=	MagickWand.3:${PORTSDIR}/graphics/ImageMagick
CONFIGURE_ARGS+=	--without-graphicsmagick
.endif
.endif

.if defined(WITHOUT_DBFAWK)
CONFIGURE_ARGS+=	--without-dbfawk
.else
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.endif

.if !defined(WITHOUT_CURL)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

.if defined(WITH_GEOTIFF)
LIB_DEPENDS+=	geotiff:${PORTSDIR}/graphics/libgeotiff
.endif

.if defined(WITH_GDAL)
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
.else
CONFIGURE_ARGS+=	--without-gdal
.endif

.if defined(WITH_GPSMAN)
BUILD_DEPENDS+=	${LOCALBASE}/share/doc/gpsmanshp/GPSManSHP.pdf:${PORTSDIR}/graphics/gpsmanshp
WITH_SHAPELIB=	true
.undef WITHOUT_SHAPELIB
.else
CONFIGURE_ARGS+=	--without-gpsman
.endif

.if defined(WITH_FESTIVAL)
BUILD_DEPENDS+=	festival:${PORTSDIR}/audio/festival
.else
CONFIGURE_ARGS+=	--without-festival
.endif

.if defined(WITH_RTREE)
CONFIGURE_ARGS+=	--with-rtree
.endif

.if defined(WITH_ERRORPOP)
CONFIGURE_ARGS+=	--with-errorpopups
.endif

.if defined(WITH_BDB)
USE_BDB=		41+
WITH_BDB_HIGHEST=	${TRUE}
INVALID_BDB_VER=	2 3 40
CONFIGURE_ARGS+=	--with-bdb-incdir=${BDB_INCLUDE_DIR} --with-bdb-libdir=${BDB_LIB_DIR}
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
WITH_OPTCFLAGS=	true
.endif

# OPTIMIZED_CFLAGS is too big for the OPTIONS variable to draw on the screen.
.if defined(WITH_OPTCFLAGS)
CFLAGS+=	-O2 -pipe
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
