# New ports collection Makefile for:	mapserver
# Date created:				2004-05-20
# Whom:					Douglas K. Rand <rand@meridian-enviro.com>
#
# $FreeBSD$
#

PORTNAME=		mapserver
PORTVERSION=		4.0.2
PORTREVISION?=	1
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

.if defined(WITH_TIFF)
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff=${LOCALBASE}
.endif

.if defined(WITH_MING)
LIB_DEPENDS+=		ming.3:${PORTSDIR}/graphics/ming
CONFIGURE_ARGS+=	--with-ming=${LOCALBASE}
.endif

.if defined(WITH_PDF)
LIB_DEPENDS+=		pdf.6:${PORTSDIR}/graphics/pdflib
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE}
.endif

.if defined(WITH_WMS)
LIB_DEPENDS+=		curl.3:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--wmsclient
.endif

.if defined(WITH_GDAL)
LIB_DEPENDS+=		gdal.1.1:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--with-gdal=${LOCALBASE}
.endif

.if defined(WITH_POSTGRESQL)
POSTGRESQL_PORT?=	databases/postgresql-client
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgis=${LOCALBASE}/bin/pg_config
.endif

.if defined(WITH_PHP)
BUILD_DEPENDS+=		mod_php4:${PORTSDIR}/www/mod_php4:
CONFIGURE_ARGS+=	--with-php=${LOCALBASE}
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

.include <bsd.port.mk>
