# Created by: Douglas K. Rand <rand@meridian-enviro.com>
# $FreeBSD$

PORTNAME=		mapserver
PORTVERSION=		7.4.3
CATEGORIES=		graphics www geography
MASTER_SITES=		https://download.osgeo.org/mapserver/

MAINTAINER=		wen@FreeBSD.org
COMMENT=		System for developing web-based GIS applications

LICENSE=		MIT

LIB_DEPENDS=		libgd.so:graphics/gd \
			libproj.so:graphics/proj \
			libpng.so:graphics/png \
			libgif.so:graphics/giflib \
			libsvg.so:graphics/libsvg \
			libfreetype.so:print/freetype2

USES=			compiler:c++11-lang cpe cmake gnome jpeg \
			localbase:ldflags
CPE_VENDOR=		umn
LDFLAGS+=		-pthread
CMAKE_ARGS+=		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
			-DCMAKE_INSTALL_PREFIX=${PREFIX} \
			-DWITH_GD=1
MAKE_JOBS_UNSAFE=	yes

PROG_FILES=		legend scalebar shp2img shptree shptreetst shptreevis \
			sortshp msencrypt tile4ms mapserv

OPTIONS_DEFINE=		CAIRO CAIRO_SVG CLIENT_WMS CLIENT_WFS CURL DEBUG \
			FASTCGI FRIBIDI GDAL GEOS HARFBUZZ KML \
			PERL PHP POSTGIS PROTOBUFC PYTHON WCS WFS WMS
OPTIONS_DEFAULT=	CAIRO FRIBIDI GDAL GEOS \
			HARFBUZZ POSTGIS PROTOBUFC WCS WFS
CAIRO_SVG_DESC=		Cairo SVG parser support
GDAL_DESC=		GDAL library support
FRIBIDI_DESC=		Fribidi library support
KML_DESC=		KML support
WMS_DESC=		WMS Server support
WFS_DESC=		WFS Server support
WCS_DESC=		WCS Server support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
USES+=			python:2.7
BUILD_DEPENDS+=		swig3.0:devel/swig30
BINARY_ALIAS=		swig=swig3.0
CMAKE_ARGS+=		-DWITH_PYTHON=yes
PLIST_SUB+=		PYTHON=""
MAP_EGG=		MapScript-${PORTVERSION}-${PYTHON_VERSION:S/thon//}
PLIST_SUB+=		MAP_EGG=${MAP_EGG}
.else
PLIST_SUB+=		PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=		libcairo.so:graphics/cairo \
			libexpat.so:textproc/expat2
CMAKE_ARGS+=		-DWITH_CAIRO=1
.else
CMAKE_ARGS+=		-DWITH_CAIRO=0
.endif

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=		libfribidi.so:converters/fribidi \
			libharfbuzz.so:print/harfbuzz
CMAKE_ARGS+=		-DWITH_FRIBIDI=1 -DWITH_HARFBUZZ=1
.else
CMAKE_ARGS+=		-DWITH_FRIBIDI=0 -DWITH_HARFBUZZ=0
.endif

.if ${PORT_OPTIONS:MHARFBUZZ}
LIB_DEPENDS+=		libfribidi.so:converters/fribidi \
			libharfbuzz.so:print/harfbuzz
CMAKE_ARGS+=		-DWITH_FRIBIDI=1 -DWITH_HARFBUZZ=1
.else
CMAKE_ARGS+=		-DWITH_FRIBIDI=0 -DWITH_HARFBUZZ=0
.endif

.if ${PORT_OPTIONS:MPROTOBUFC}
LIB_DEPENDS+=		libprotobuf-c.so:devel/protobuf-c
CMAKE_ARGS+=		-DWITH_PROTOBUFC=1
.else
CMAKE_ARGS+=		-DWITH_PROTOBUFC=0
.endif

.if ${PORT_OPTIONS:MCAIRO_SVG}
LIB_DEPENDS+=		libcairo.so:graphics/cairo \
			libsvg-cairo.so:graphics/libsvg-cairo \
			libexpat.so:textproc/expat2
CMAKE_ARGS+=		-DWITH_SVGCAIRO=1 -DWITH_CAIRO=1
USES+=			pkgconfig
.else
CMAKE_ARGS+=		-DWITH_SVGCAIRO=0
.endif

.if ${PORT_OPTIONS:MKML}
LIB_DEPENDS+=		libxml2.so:textproc/libxml2
CMAKE_ARGS+=		-DWITH_KML=1
.else
CMAKE_ARGS+=		-DWITH_KML=0
.endif

.if ${PORT_OPTIONS:MWMS}
CMAKE_ARGS+=		-DWITH_WMS=1
.else
CMAKE_ARGS+=		-DWITH_WMS=0
.endif

.if ${PORT_OPTIONS:MWFS}
CMAKE_ARGS+=		-DWITH_WFS=1
.else
CMAKE_ARGS+=		-DWITH_WFS=0
.endif

.if ${PORT_OPTIONS:MWCS}
CMAKE_ARGS+=		-DWITH_WCS=1
.else
CMAKE_ARGS+=		-DWITH_WCS=0
.endif

.if ${PORT_OPTIONS:MGDAL}
USES+=			iconv
LIB_DEPENDS+=		libgdal.so:graphics/gdal
CMAKE_ARGS+=		-DWITH_GDAL=1
.else
CMAKE_ARGS+=		-DWITH_GDAL=0
.endif

.if ${PORT_OPTIONS:MGEOS}
LIB_DEPENDS+=		libgeos.so:graphics/geos
CMAKE_ARGS+=		-DWITH_GEOS=1
.else
CMAKE_ARGS+=		-DWITH_GEOS=0
.endif

.if ${PORT_OPTIONS:MPOSTGIS}
USES+=			pgsql
CMAKE_ARGS+=		-DWITH_POSTGIS=1
.else
CMAKE_ARGS+=		-DWITH_POSTGIS=0
.endif

.if ${PORT_OPTIONS:MPHP}
USES+=			php:build
CMAKE_ARGS+=		-DWITH_PHP=1
PLIST_SUB+=		PHP=""
.else
CMAKE_ARGS+=		-DWITH_PHP=0
PLIST_SUB+=		PHP="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
BUILD_DEPENDS=	swig3.0:devel/swig30
CMAKE_ARGS+=	-DWITH_PERL=1
PLIST_SUB+=	PERL=""
BINARY_ALIAS=	swig=swig3.0
.else
CMAKE_ARGS+=	-DWITH_PERL=0
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=		libcurl.so:ftp/curl
CMAKE_ARGS+=		-DWITH_CURL=1
.else
CMAKE_ARGS+=		-DWITH_CURL=0
.endif

.if ${PORT_OPTIONS:MFASTCGI}
BUILD_DEPENDS+=		${LOCALBASE}/bin/cgi-fcgi:www/fcgi
CMAKE_ARGS+=		-DWITH_FCGI=1
.else
CMAKE_ARGS+=		-DWITH_FCGI=0
.endif

.if ${PORT_OPTIONS:MDEBUG}
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Debug
.else
CMAKE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
.endif

.if ${PORT_OPTIONS:MCLIENT_WMS}
LIB_DEPENDS+=		libcurl.so:ftp/curl
LIB_DEPENDS+=		libgdal.so:graphics/gdal
CMAKE_ARGS+=		-DWITH_CURL=1 -DWITH_GDAL=1 -DWITH_CLIENT_WMS=1
.endif

.if ${PORT_OPTIONS:MCLIENT_WFS}
LIB_DEPENDS+=		libcurl.so:ftp/curl
LIB_DEPENDS+=		libgdal.so:graphics/gdal
CMAKE_ARGS+=		-DWITH_CURL=1 -DWITH_GDAL=1 -DWITH_CLIENT_WFS=1
.endif

do-install:
.for f in ${PROG_FILES}
	${STRIP_CMD} ${BUILD_WRKSRC}/${f}
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libmapserver.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib

	@${LN} -sf libmapserver.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libmapserver.so.2
	@${LN} -sf libmapserver.so.2 ${STAGEDIR}${PREFIX}/lib/libmapserver.so

do-install-PHP-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/mapscript/php/php_mapscript.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php
	@${ECHO_CMD} "extension=php_mapscript.so" > ${STAGEDIR}${PREFIX}/etc/php/ext-20-php_mapscript.ini

do-install-PYTHON-on:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/
	(cd ${BUILD_WRKSRC}/mapscript/python && ${CP} mapscript.py _mapscript.so ${STAGEDIR}${PYTHON_SITELIBDIR}/)

.include <bsd.port.mk>
