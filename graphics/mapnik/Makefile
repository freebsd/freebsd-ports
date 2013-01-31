# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mapnik
PORTVERSION=	2.1.0
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics geography
MASTER_SITES=	http://cloud.github.com/downloads/${PORTNAME}/${PORTNAME}/

MAINTAINER=	littlesavage@rambler.ru
COMMENT=	A Free Toolkit For Developing Mapping Applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		icuuc:${PORTSDIR}/devel/icu \
		boost_system:${PORTSDIR}/devel/boost-libs \
		boost_python:${PORTSDIR}/devel/boost-python-libs
BUILD_DEPENDS=	${LOCALBASE}/bin/freetype-config:${PORTSDIR}/print/freetype2 \
		icu>=4.2:${PORTSDIR}/devel/icu \
		${PYTHON_PKGNAMEPREFIX}icu>=0.8.1:${PORTSDIR}/devel/py-icu \
		boost-libs>=1.47:${PORTSDIR}/devel/boost-libs \

USE_BZIP2=	yes
USE_PYTHON=	2.6+
USE_LDCONFIG=	yes
USE_SCONS=	yes
USE_AUTOTOOLS=	libltdl
USE_GNOME=	pkgconfig libxml2
MAKE_JOBS_SAFE=	yes
WARNING_CXXFLAGS?=	-w

CONFICTS=	svg2png*

INPUT_PLUGINS=	geojson python raster shape

OPTIONS_DEFINE=	CAIRO CSV GDAL GEOS OGR OSM POSTGIS SQLITE3
OPTIONS_DEFAULT=	CAIRO CSV GDAL OGR OSM POSTGIS SQLITE3

CAIRO_DESC=	Enable cairo rendering
CSV_DESC=	CSV input plugin
GDAL_DESC=	GDAL input plugin
GEOS_DESC=	GEOS input plugin
OGR_DESC=	OGR input plugin
OSM_DESC=	OSM input plugin
POSTGIS_DESC=	PostGIS input plugin
SQLITE3_DESC=	SQLite input plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo \
   		cairomm-1:${PORTSDIR}/graphics/cairomm
BUILD_DEPENDS+=	cairomm>=1.8.0:${PORTSDIR}/graphics/cairomm \
		${PYTHON_PKGNAMEPREFIX}cairo>=1.8.2:${PORTSDIR}/graphics/py-cairo
.else
SCONS_ARGS+=	CAIRO=False
.endif

.if ${PORT_OPTIONS:MCSV}
INPUT_PLUGINS+=	csv
PLIST_SUB+=	CSV=""
.else
PLIST_SUB+=	CSV="@comment "
.endif

.if ${PORT_OPTIONS:MGDAL}
INPUT_PLUGINS+=	gdal
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
PLIST_SUB+=	GDAL=""
.else
PLIST_SUB+=	GDAL="@comment "
.endif

.if ${PORT_OPTIONS:MGEOS}
INPUT_PLUGINS+=	geos
LIB_DEPENDS+=	geos:${PORTSDIR}/graphics/geos
PLIST_SUB+=	GEOS=""
.else
PLIST_SUB+=	GEOS="@comment "
.endif

.if ${PORT_OPTIONS:MOGR}
INPUT_PLUGINS+=	ogr
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
PLIST_SUB+=	OGR=""
.else
PLIST_SUB+=	OGR="@comment "
.endif

.if ${PORT_OPTIONS:MOSM}
INPUT_PLUGINS+=	osm
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
PLIST_SUB+=	OSM=""
.else
PLIST_SUB+=	OSM="@comment "
.endif

.if ${PORT_OPTIONS:MPOSTGIS}
INPUT_PLUGINS+=	postgis
USE_PGSQL=	yes
PLIST_SUB+=	POSTGIS=""
.else
PLIST_SUB+=	POSTGIS="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE3}
INPUT_PLUGINS+=	sqlite
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS+=	sqlite3>=3.7.12:${PORTSDIR}/databases/sqlite3
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
IGNORE=		does not install: runs out of virtual memory
.endif

SCONS_ARGS+=	WARNING_CXXFLAGS=${WARNING_CXXFLAGS}
SCONS_ARGS+=	INPUT_PLUGINS="`${ECHO} ${INPUT_PLUGINS} | ${TR} ' ' ,`"

.if defined (MAKE_JOBS_NUMBER)
SCONS_ARGS+=	JOBS=${MAKE_JOBS_NUMBER}
.endif

pre-configure:
.if ${PORT_OPTIONS:MSQLITE3}
	@if ! ${LOCALBASE}/bin/sqlite3 :memory: 'create virtual table foo using rtree(pkid, xmin, xmax, ymin, ymax)' > /dev/null 2>&1; then \
	   ${ECHO_MSG} "" ; \
	   ${ECHO_MSG} "The SQLite plugin requires libsqlite3 built with RTREE support"; \
	   ${ECHO_MSG} "Please, reinstall 'databases/sqlite3' port with R*Tree module enabled"; \
	   ${ECHO_MSG} "" ; \
	   ${FALSE} ; \
	fi
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		${WRKSRC}/SConstruct

do-install:
	@cd ${INSTALL_WRKSRC} && ${SETENV} ${SCONS_BUILDENV} ${SCONS_BIN} \
	    ${SCONS_INSTALL_TARGET}

.include <bsd.port.post.mk>
