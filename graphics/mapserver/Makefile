# Created by: Douglas K. Rand <rand@meridian-enviro.com>
# $FreeBSD$

PORTNAME=		mapserver
PORTVERSION=		6.2.1
CATEGORIES=		graphics www geography
MASTER_SITES=		http://download.osgeo.org/mapserver/

MAINTAINER=		wen@FreeBSD.org
COMMENT=		System for developing web-based GIS applications

LIB_DEPENDS=		gd:${PORTSDIR}/graphics/gd \
			proj:${PORTSDIR}/graphics/proj \
			png15:${PORTSDIR}/graphics/png \
			jpeg:${PORTSDIR}/graphics/jpeg \
			gif:${PORTSDIR}/graphics/giflib \
			curl:${PORTSDIR}/ftp/curl

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-proj=${LOCALBASE} \
			--with-gd=${LOCALBASE} \
			--with-png=${LOCALBASE} \
			--with-jpeg=${LOCALBASE} \
			--with-gif=${LOCALBASE} \
			--with-curl-config=${LOCALBASE}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		AGG TIFF PDF GDAL GEOS KML MING MYGIS POSTGIS PHP PERL PYTHON \
			WMS WFS MAPSERV FASTCGI DEBUG CAIRO CAIRO_SVG
OPTIONS_DEFAULT=	AGG GDAL GEOS MAPSERV
AGG_DESC=		AGG image rendering support
CAIRO_SVG_DESC=		Cairo SVG parser support
GDAL_DESC=		GDAL library support
KML_DESC=		KML support
MING_DESC=		Macromedia Flash output support
MYGIS_DESC=		MyGIS support
WMS_DESC=		Web map service server and client support
WFS_DESC=		Web feature service support
MAPSERV_DESC=		Mapserv cgi interface support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMAPSERV}
USE_APACHE_RUN=		22+
PLIST_SUB+=		MAPSERV=""
PLIST_SUB+=		APA_VER=${APACHE_VERSION}
PLIST_DIRSTRY=		www/apache${APACHE_VERSION}/cgi-bin
.else
PLIST_SUB+=		MAPSERV="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=		2.6
PLIST_SUB+=		PYTHON=""
MAP_EGG=		MapScript-${PORTVERSION}-${PYTHON_VERSION:S/thon//}
PLIST_SUB+=		MAP_EGG=${MAP_EGG}
.else
PLIST_SUB+=		PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MAGG}
LIB_DEPENDS+=		agg:${PORTSDIR}/graphics/agg
.endif

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=		cairo:${PORTSDIR}/graphics/cairo \
			expat:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=	--with-cairo=yes --with-expat=${LOCALBASE}
USES+=			pkgconfig
.endif

.if ${PORT_OPTIONS:MCAIRO_SVG}
LIB_DEPENDS+=		cairo:${PORTSDIR}/graphics/cairo \
			svg-cairo:${PORTSDIR}/graphics/libsvg-cairo \
			expat:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=	--with-cairo=yes \
			--with-libsvg-cairo \
			--with-expat=${LOCALBASE}
USES+=			pkgconfig
.endif

.if ${PORT_OPTIONS:MKML}
LIB_DEPENDS+=		xml2:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=	--with-kml --with-xml2-config=${LOCALBASE}/bin/xml2-config
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=		tiff:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-tiff
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
CONFIGURE_ARGS+=	--with-wms --with-wmsclient
.endif

.if ${PORT_OPTIONS:MWFS}
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl \
			gdal:${PORTSDIR}/graphics/gdal
CONFIGURE_ARGS+=	--with-wfs --with-wfsclient --with-curl=${LOCALBASE} \
			--with-gdal=${LOCALBASE}/bin/gdal-config \
			--with-ogr=${LOCALBASE}/bin/gdal-config
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
BUILD_DEPENDS+=		${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php5
RUN_BUILDS+=		${LOCALBASE}/bin/php-config:${PORTSDIR}/lang/php5
CONFIGURE_ARGS+=	--with-php=${LOCALBASE}/bin/php-config
PHP_EXTENSION_DIR!=	${LOCALBASE}/bin/php-config --extension-dir | ${SED} -e "s,/usr/local/,,"
PLIST_SUB+=		PHP_EXTENSION_DIR=${PHP_EXTENSION_DIR}
PLIST_SUB+=		PHP=""
.else
PLIST_SUB+=		PHP="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=yes
PLIST_SUB+=		PERL=""
.else
PLIST_SUB+=		PERL="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=		curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MFASTCGI}
BUILD_DEPENDS+=		${LOCALBASE}/bin/cgi-fcgi:${PORTSDIR}/www/fcgi
CONFIGURE_ARGS+=	--with-fastcgi=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

PROG_FILES=		legend scalebar shp2img shptree shptreetst shptreevis \
			sortshp msencrypt tile4ms

post-patch:
.if ${PORT_OPTIONS:MMING}
	${REINPLACE_CMD} -e 's#with_ming/include#with_ming/include/ming#g' \
		${WRKSRC}/configure
.endif

post-build:
.if ${PORT_OPTIONS:MPERL}
	(cd ${WRKSRC}/mapscript/perl && ${PERL5} Makefile.PL && make)
.endif

do-install:
.for f in ${PROG_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/.libs/libmapserver-${PORTVERSION}.so ${PREFIX}/lib

.if ${PORT_OPTIONS:MMAPSERV}
	${MKDIR} ${LOCALBASE}/www/apache${APACHE_VERSION}/cgi-bin/
	${INSTALL_SCRIPT} ${WRKSRC}/.libs/mapserv ${LOCALBASE}/www/apache${APACHE_VERSION}/cgi-bin/mapserv
.endif

.if ${PORT_OPTIONS:MPHP}
	@${MKDIR} ${LOCALBASE}/${PHP_EXTENSION_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/mapscript/php/.libs/php_mapscript.so \
		${LOCALBASE}/${PHP_EXTENSION_DIR}/
.endif

.if ${PORT_OPTIONS:MPERL}
	(cd ${WRKSRC}/mapscript/perl && make install)
.endif

.if ${PORT_OPTIONS:MPYTHON}
	(cd ${WRKSRC}/mapscript/python && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py install)
.endif

post-install:
.if ${PORT_OPTIONS:MPHP}
	@${ECHO_MSG} "Please add the line extension=php_mapscript.so to ${LOCALBASE}/etc/php/extensions.ini"
.endif

.include <bsd.port.mk>
