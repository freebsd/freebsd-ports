# New ports collection Makefile for:	mapserver
# Date created:				2004-05-20
# Whom:					Douglas K. Rand <rand@meridian-enviro.com>
#
# $FreeBSD$
#

PORTNAME=		mapserver
PORTVERSION=		4.4.1
PORTREVISION=		0
CATEGORIES=		graphics www misc
MASTER_SITES=		http://cvs.gis.umn.edu/dist/

MAINTAINER=		mharo@FreeBSD.org
COMMENT=		System for developing web-based GIS applications

LIB_DEPENDS=		gd.4:${PORTSDIR}/graphics/gd \
			proj.5:${PORTSDIR}/graphics/proj

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-runpath \
			--with-gd=${LOCALBASE} \
			--with-proj=${LOCALBASE}

OPTIONS=		TIFF "Support for TIFF (but not GeoTIFF) files" off \
			MING "Support for Macromedia Flash output" off \
			PDF "Support for PDF output via pdflib" off \
			GDAL "Support for a number of input raster formats" off \
			POSTGIS "Support for PostGIS" off \
			PHP "Support for MapScript/PHP" off \
			PERL "Support for MapScript/PERL" off \
			WMS "Support for web map service server and client" off \
			WFS "Support for web feature service (req: GDAL)" off \
			MAPSERV "Install mapserv cgi interface" on \
			DEBUG "Enable debugging output" off

.include <bsd.port.pre.mk>

.if defined(WITH_TIFF)
.if !defined(WITH_GDAL)
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff=${LOCALBASE}
.endif
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if defined(WITH_MING)
LIB_DEPENDS+=		ming.3:${PORTSDIR}/graphics/ming
CONFIGURE_ARGS+=	--with-ming=${LOCALBASE}
.endif

.if defined(WITH_PDF)
LIB_DEPENDS+=		pdf.7:${PORTSDIR}/print/pdflib
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
LIB_DEPENDS+=		gdal.4:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--with-gdal=${LOCALBASE}/bin/gdal-config \
			--with-ogr=${LOCALBASE}/bin/gdal-config
.endif

.if defined(WITH_POSTGIS)
POSTGRESQL_PORT?=	databases/postgis
LIB_DEPENDS+=		pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=	--with-postgis=${LOCALBASE}/bin/pg_config
.endif

.if defined(WITH_PHP)
.BEGIN:
# make sure php was built with regex=system
	@if [ `grep -q 'define REGEX 0' ${LOCALBASE}/include/php/main/php_config.h` ]; then \
		${ECHO_MSG} "This port currently requires your php to have been built specifying the"; \
		${ECHO_MSG} "flag --with-regex=system. To specify this flag when building php from ports,"; \
		${ECHO_MSG} "use 'WITH_REGEX_TYPE=system'."; \
		${ECHO_MSG} ""; \
		sleep 2; \
	fi
BUILD_DEPENDS+=		php-config:${PORTSDIR}/www/php4-cgi
CONFIGURE_ARGS+=	--with-php=${LOCALBASE}
PHP_EXTENSION_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e 's,/usr/local/,,'
PLIST_SUB+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
PLIST_SUB+=		WITH_PHP=""
.else
PLIST_SUB+=		WITH_PHP="@comment "
.endif

.if defined(WITH_PERL)
USE_PERL5=yes
PLIST_SUB+=		WITH_PERL=""
.else
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=		curl.3:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE}
.endif

.if defined(WITH_MAPSERV)
USE_APACHE=		YES
PLIST_SUB+=		WITH_MAPSERV=""
.else
PLIST_SUB+=		WITH_MAPSERV="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

PROG_FILES=		legend scalebar shp2img shp2pdf shptree shptreetst shptreevis sortshp

post-build:
.if defined(WITH_PERL)
	(cd ${WRKSRC}/mapscript/perl && ${PERL5} Makefile.PL && make)
.endif

do-install:
.for f in ${PROG_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/shp2mysql.pl ${PREFIX}/bin/shp2mysql
.if defined(WITH_MAPSERV)
	${MKDIR} ${LOCALBASE}/www/cgi-bin/
	${INSTALL_PROGRAM} ${WRKSRC}/mapserv ${LOCALBASE}/www/cgi-bin/mapserv
.endif
.if defined(WITH_PHP)
	@${MKDIR} ${LOCALBASE}/${PHP_EXTENSION_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/mapscript/php3/php_mapscript.so ${LOCALBASE}/${PHP_EXTENSION_DIR}/
	${ECHO} "extension=php_mapscript.so" >> ${LOCALBASE}/etc/php/extensions.ini
.endif
.if defined(WITH_PERL)
	(cd ${WRKSRC}/mapscript/perl && make install)
.endif

.include <bsd.port.post.mk>
