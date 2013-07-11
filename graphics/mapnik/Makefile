# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mapnik
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics geography
MASTER_SITES=	http://mapnik.s3.amazonaws.com/dist/v${PORTVERSION}/

MAINTAINER=	littlesavage@rambler.ru
COMMENT=	A Free Toolkit For Developing Mapping Applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		icuuc:${PORTSDIR}/devel/icu \
		boost_system:${PORTSDIR}/devel/boost-libs \
		boost_python:${PORTSDIR}/devel/boost-python-libs
BUILD_DEPENDS=	${LOCALBASE}/bin/freetype-config:${PORTSDIR}/print/freetype2 \
		${PYTHON_PKGNAMEPREFIX}icu>=0.8.1:${PORTSDIR}/devel/py-icu

USE_BZIP2=	yes
USES=		pkgconfig
USE_GNOME=	libxml2
USE_PYTHON=	2.6+
USE_LDCONFIG=	yes
USE_SCONS=	yes
MAKE_JOBS_SAFE=	yes
WARNING_CXXFLAGS?=	-w

INPUT_PLUGINS=	geojson python raster shape

NO_OPTIONS_SORT= yes
OPTIONS_DEFINE=	CAIRO CSV GDAL OGR OSM POSTGIS SQLITE3 JPEG PNG TIFF
OPTIONS_DEFAULT=	CAIRO CSV GDAL OGR OSM POSTGIS SQLITE3 JPEG PNG TIFF

CAIRO_DESC=	Enable cairo rendering
CSV_DESC=	CSV input plugin
GDAL_DESC=	GDAL input plugin
OGR_DESC=	OGR input plugin
OSM_DESC=	OSM input plugin
POSTGIS_DESC=	PostGIS input plugin
SQLITE3_DESC=	SQLite input plugin

OPTIONS_SUB=	yes

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS.md CHANGELOG.md README.md

DOCSRCDIR2=	${WRKSRC}/docs
DOCSDIR2=	${DOCSDIR}/docs
DOC_FILES2=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAIRO}
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.2:${PORTSDIR}/graphics/py-cairo
.else
SCONS_ARGS+=	CAIRO=False
.endif

.if ${PORT_OPTIONS:MCSV}
INPUT_PLUGINS+=	csv
.endif

.if ${PORT_OPTIONS:MGDAL}
INPUT_PLUGINS+=	gdal
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
.endif

.if ${PORT_OPTIONS:MOGR}
INPUT_PLUGINS+=	ogr
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
.endif

.if ${PORT_OPTIONS:MOSM}
INPUT_PLUGINS+=	osm
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

.if ${PORT_OPTIONS:MPOSTGIS}
INPUT_PLUGINS+=	postgis
USE_PGSQL=	yes
.endif

.if ${PORT_OPTIONS:MSQLITE3}
INPUT_PLUGINS+=	sqlite
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS+=	sqlite3>=3.7.12:${PORTSDIR}/databases/sqlite3
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=   jpeg:${PORTSDIR}/graphics/jpeg
.else
SCONS_ARGS+=	JPEG=False
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=   png15:${PORTSDIR}/graphics/png
.else
SCONS_ARGS+=	PNG=False
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=   tiff:${PORTSDIR}/graphics/tiff
.else
SCONS_ARGS+=	TIFF=False
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
IGNORE=		does not install: runs out of virtual memory
.endif

SCONS_ARGS+=	WARNING_CXXFLAGS=${WARNING_CXXFLAGS}
SCONS_ARGS+=	INPUT_PLUGINS="`${ECHO} ${INPUT_PLUGINS} | ${TR} ' ' ,`"
SCONS_ARGS+=	JOBS=${MAKE_JOBS_NUMBER}

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

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.post.mk>
