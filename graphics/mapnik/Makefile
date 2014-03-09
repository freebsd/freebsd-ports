# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mapnik
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	graphics geography
MASTER_SITES=	http://mapnik.s3.amazonaws.com/dist/v${PORTVERSION}/

MAINTAINER=	littlesavage@rambler.ru
COMMENT=	A Free Toolkit For Developing Mapping Applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libproj.so:${PORTSDIR}/graphics/proj \
		libicuuc.so:${PORTSDIR}/devel/icu \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libboost_python.so:${PORTSDIR}/devel/boost-python-libs
BUILD_DEPENDS=	${LOCALBASE}/bin/freetype-config:${PORTSDIR}/print/freetype2 \
		${PYTHON_PKGNAMEPREFIX}icu>=0.8.1:${PORTSDIR}/devel/py-icu

USE_BZIP2=	yes
USES=		pkgconfig scons
USE_GNOME=	libxml2
USE_PYTHON=	yes
USE_LDCONFIG=	yes
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
LIB_DEPENDS+=	libcairo.so:${PORTSDIR}/graphics/cairo
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.2:${PORTSDIR}/graphics/py-cairo
.else
MAKE_ARGS+=	CAIRO=False
.endif

.if ${PORT_OPTIONS:MCSV}
INPUT_PLUGINS+=	csv
.endif

.if ${PORT_OPTIONS:MGDAL}
INPUT_PLUGINS+=	gdal
LIB_DEPENDS+=	libgdal.so:${PORTSDIR}/graphics/gdal
.endif

.if ${PORT_OPTIONS:MOGR}
INPUT_PLUGINS+=	ogr
LIB_DEPENDS+=	libgdal.so:${PORTSDIR}/graphics/gdal
.endif

.if ${PORT_OPTIONS:MOSM}
INPUT_PLUGINS+=	osm
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
.endif

.if ${PORT_OPTIONS:MPOSTGIS}
INPUT_PLUGINS+=	postgis
USE_PGSQL=	yes
.endif

.if ${PORT_OPTIONS:MSQLITE3}
INPUT_PLUGINS+=	sqlite
LIB_DEPENDS+=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS+=	sqlite3>=3.7.12:${PORTSDIR}/databases/sqlite3
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=   libjpeg.so:${PORTSDIR}/graphics/jpeg
.else
MAKE_ARGS+=	JPEG=False
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=   libpng15.so:${PORTSDIR}/graphics/png
.else
MAKE_ARGS+=	PNG=False
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=   libtiff.so:${PORTSDIR}/graphics/tiff
.else
MAKE_ARGS+=	TIFF=False
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
IGNORE=		does not install: runs out of virtual memory
.endif

MAKE_ARGS+=	CUSTOM_CFLAGS=-I${LOCALBASE}/include
MAKE_ARGS+=	CUSTOM_CXXFLAGS=-I${LOCALBASE}/include
MAKE_ARGS+=	CUSTOM_LDFLAGS=-L${LOCALBASE}/lib
MAKE_ARGS+=	WARNING_CXXFLAGS=${WARNING_CXXFLAGS}
MAKE_ARGS+=	INPUT_PLUGINS="`${ECHO} ${INPUT_PLUGINS} | ${TR} ' ' ,`"
MAKE_ARGS+=	JOBS=${MAKE_JOBS_NUMBER}
MAKE_ARGS+=	${MAKE_ENV}

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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.post.mk>
