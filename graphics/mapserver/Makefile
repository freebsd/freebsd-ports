# New ports collection Makefile for:	mapserver
# Date created:				2004-05-20
# Whom:					Douglas K. Rand <rand@meridian-enviro.com>
#
# $FreeBSD$
#

PORTNAME=		mapserver
PORTVERSION=		6.0.3
CATEGORIES=		graphics www geography
MASTER_SITES=		http://download.osgeo.org/mapserver/

MAINTAINER=		wen@FreeBSD.org
COMMENT=		System for developing web-based GIS applications

LIB_DEPENDS=		gd:${PORTSDIR}/graphics/gd \
			proj:${PORTSDIR}/graphics/proj \
			png15:${PORTSDIR}/graphics/png \
			jpeg:${PORTSDIR}/graphics/jpeg \
			gif:${PORTSDIR}/graphics/giflib

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-runpath \
			--with-gd=${LOCALBASE} \
			--with-png=${LOCALBASE} \
			--with-jpeg=${LOCALBASE} \
			--with-gif=${LOCALBASE} \
			--with-proj=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		AGG TIFF PDF GDAL GEOS MING MYGIS POSTGIS PHP PERL PYTHON \
			WMS WFS MAPSERV FASTCGI DEBUG
OPTIONS_DEFAULT=	GDAL GEOS MAPSERV
AGG_DESC=		AGG image rendering support
GDAL_DESC=		GDAL library support
MING_DESC=		Macromedia Flash output support
MYGIS_DESC=		MyGIS support
WMS_DESC=		Web map service server and client support
WFS_DESC=		Web feature service support
MAPSERV_DESC=		Mapserv cgi interface support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAGG}
LIB_DEPENDS+=		agg:${PORTSDIR}/graphics/agg
CONFIGURE_ARGS+=	--with-agg=${LOCALBASE} --with-freetype=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=		tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-tiff
.endif

.if ${PORT_OPTIONS:MMING}
LIB_DEPENDS+=		ming:${PORTSDIR}/graphics/ming
CONFIGURE_ARGS+=	--with-ming=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MPDF}
LIB_DEPENDS+=		pdf:${PORTSDIR}/print/pdflib \
			tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-pdf=${LOCALBASE} --with-tiff=${LOCALBASE} --with-png=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MWMS}
WITH_CURL=		yes
CONFIGURE_ARGS+=	--with-wms --with-wmsclient
.endif

.if ${PORT_OPTIONS:MWFS}
WITH_CURL=		yes
WITH_GDAL=		yes
CONFIGURE_ARGS+=	--with-wfs --with-wfsclient
.endif

.if ${PORT_OPTIONS:MGDAL}
LIB_DEPENDS+=		gdal:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--with-gdal=${LOCALBASE}/bin/gdal-config \
			--with-ogr=${LOCALBASE}/bin/gdal-config
.endif

.if ${PORT_OPTIONS:MGEOS}
LIB_DEPENDS+=		geos:${PORTSDIR}/graphics/geos
CONFIGURE_ARGS+=	--with-geos=${LOCALBASE}/bin/geos-config
.endif

.if ${PORT_OPTIONS:MMYGIS}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mygis=${LOCALBASE}/bin/mysql_config
.endif

.if ${PORT_OPTIONS:MPOSTGIS}
BUILD_DEPENDS+=		${LOCALBASE}/lib/libpgport.a:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
USE_PGSQL=		yes
DEFAULT_PGSQL_VER=	83
CONFIGURE_ARGS+=	--with-postgis=${LOCALBASE}/bin/pg_config
.endif

.if ${PORT_OPTIONS:MPHP}
EXTRA_PATCHES=		${FILESDIR}/extra-patch-mapscript-php-image.c \
			${FILESDIR}/extra-patch-mapscript-php-php_mapscript.c \
			${FILESDIR}/extra-patch-mapscript-php-php_mapscript_util.c
BUILD_DEPENDS+=		${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php5
RUN_BUILDS=		${BUILD_DEPENDS}
CONFIGURE_ARGS+=	--with-php=${LOCALBASE}/include/php/
PHP_EXTENSION_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e 's,/usr/local/,,'
PLIST_SUB+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
PLIST_SUB+=		WITH_PHP=""
.else
PLIST_SUB+=		WITH_PHP="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=yes
PLIST_SUB+=		WITH_PERL=""
.else
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
BUILD_DEPENDS+=		${LOCALBASE}/bin/python:${PORTSDIR}/lang/python26
PLIST_SUB+=		WITH_PYTHON=""
.include <../../Mk/bsd.python.mk>
MAP_EGG=		MapScript-${PORTVERSION}-${PYTHON_VERSION:S/thon//}
PLIST_SUB+=		MAP_EGG=${MAP_EGG}
.else
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMAPSERV}
USE_APACHE=		22+
.include "${PORTSDIR}/Mk/bsd.apache.mk"
PLIST_SUB+=		WITH_MAPSERV=""
PLIST_DIRSTRY=		www/cgi-bin
.else
PLIST_SUB+=		WITH_MAPSERV="@comment "
.endif

.if ${PORT_OPTIONS:MFASTCGI}
BUILD_DEPENDS+=		${LOCALBASE}/bin/cgi-fcgi:${PORTSDIR}/www/fcgi
CONFIGURE_ARGS+=	--with-fastcgi=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

PROG_FILES=		legend scalebar shp2img shptree shptreetst shptreevis sortshp

post-patch:
.if defined(WITH_MING)
	${REINPLACE_CMD} -e 's#with_ming/include#with_ming/include/ming#g' \
		${WRKSRC}/configure
.endif

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
	${INSTALL_PROGRAM} ${WRKSRC}/mapscript/php/php_mapscript.so ${LOCALBASE}/${PHP_EXTENSION_DIR}/
.endif

.if defined(WITH_PERL)
	(cd ${WRKSRC}/mapscript/perl && make install)
.endif

.if defined(WITH_PYTHON)
	(cd ${WRKSRC}/mapscript/python && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install)
.endif

post-install:
.if defined(WITH_PHP)
	@${ECHO_MSG} "Please add the line extension=php_mapscript.so to ${LOCALBASE}/etc/php/extensions.ini"
.endif

.include <bsd.port.mk>
