# New ports collection Makefile for:	mapserver
# Date created:				2004-05-20
# Whom:					Douglas K. Rand <rand@meridian-enviro.com>
#
# $FreeBSD$
#

PORTNAME=		mapserver
PORTVERSION=		4.0.2
PORTREVISION?=		2
CATEGORIES=		graphics www misc
MASTER_SITES=		http://cvs.gis.umn.edu/dist/

MAINTAINER=		rand@meridian-enviro.com
COMMENT=		System for developing web-based GIS applications

LIB_DEPENDS=		gd.4:${PORTSDIR}/graphics/gd \
			proj.3:${PORTSDIR}/graphics/proj

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-runpath \
			--with-gd=${LOCALBASE} \
			--with-proj=${LOCALBASE}

OPTIONS=		TIFF "Support for TIFF (but not GeoTIFF) files" off \
			MING "Support for Macromedia Flash output" off \
			PDF "Support for PDF output via pdflib" off \
			GDAL "Support for a number of input raster formats" off \
			POSTGRESQL "Support for PostgreSQL" off \
			PHP "Support for MapScript/PHP" off \
			WMS "Support for web map service server and client" off \
			WFS "Support for web feature service" off \
			DEBUG "Enable debugging output" off

.include <bsd.port.pre.mk>

.if defined(WITH_TIFF)
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if defined(WITH_MING)
LIB_DEPENDS+=		ming.3:${PORTSDIR}/graphics/ming
CONFIGURE_ARGS+=	--with-ming=${LOCALBASE}
.endif

.if defined(WITH_PDF)
LIB_DEPENDS+=		pdf.6:${PORTSDIR}/print/pdflib
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE}
.endif

.if defined(WITH_WMS)
WITH_CURL=		YES
CONFIGURE_ARGS+=	--with-wms --with-wmsclient
.endif

.if defined(WITH_WFS)
WITH_CURL=		YES
WITH_GDAL=		YES
CONFIGURE_ARGS+=	--with-wfs --with-wfsclient
.endif

.if defined(WITH_GDAL)
BUILD_DEPENDS+=		gdal-config:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--with-gdal=${LOCALBASE}/bin/gdal-config \
			--with-ogr=${LOCALBASE}/bin/gdal-config
.endif

.if defined(WITH_POSTGRESQL)
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgis=${LOCALBASE}/bin/pg_config
.endif

.if defined(WITH_PHP)
BUILD_DEPENDS+=		mod_php4:${PORTSDIR}/www/mod_php4:
CONFIGURE_ARGS+=	--with-php=${LOCALBASE}
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=		curl.3:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE}
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

PROG_FILES=		mapserv legend scalebar shp2img shp2pdf shptree shptreetst shptreevis sortshp

do-install:
.for f in ${PROG_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${LOCALBASE}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/shp2mysql.pl ${LOCALBASE}/bin/shp2mysql

.include <bsd.port.post.mk>
