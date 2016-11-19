# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mapnik
PORTVERSION=	3.0.9
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	graphics geography
MASTER_SITES=	http://mapnik.s3.amazonaws.com/dist/v${PORTVERSION}/

MAINTAINER=	littlesavage@rambler.ru
COMMENT=	Free Toolkit For Developing Mapping Applications

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libboost_system.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

BROKEN_powerpc=	does not install: runs out of virtual memory
BROKEN_FreeBSD_9=	does not build: lack of c++11 support

USES=		compiler:c++11-lib pkgconfig python scons tar:bzip2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
MAKE_ARGS=	INPUT_PLUGINS="`${ECHO} ${INPUT_PLUGINS} | ${TR} ' ' ,`" \
		CUSTOM_CFLAGS="${CFLAGS}" CUSTOM_CXXFLAGS="${CXXFLAGS}" \
		CUSTOM_LDFLAGS="${LDFLAGS}"

PORTDOCS=	*

INPUT_PLUGINS=	csv raster shape geojson topojson

OPTIONS_DEFINE=	CAIRO JPEG PNG TIFF WEBP PROJ
OPTIONS_DEFAULT=CAIRO GDAL OGR POSTGIS PGRASTER SQLITE3 JPEG PNG TIFF PROJ WEBP
OPTIONS_GROUP=	INPUT
OPTIONS_GROUP_INPUT=	GDAL OGR POSTGIS PGRASTER SQLITE3
OPTIONS_SUB=	yes

INPUT_DESC=	Input plugins
GDAL_DESC=	GDAL input plugin
OGR_DESC=	OGR input plugin
POSTGIS_DESC=	PostGIS input plugin
PGRASTER_DESC=	PGraster input plugin
SQLITE3_DESC=	SQLite input plugin

PROJ_DESC=	proj4 support

CAIRO_DESC=	Enable cairo rendering

GDAL_VARS=		INPUT_PLUGINS+=gdal
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
OGR_VARS=		INPUT_PLUGINS+=ogr
OGR_LIB_DEPENDS=	libgdal.so:graphics/gdal
POSTGIS_VARS=		INPUT_PLUGINS+=postgis
POSTGIS_USES=		pgsql
PGRASTER_VARS=		INPUT_PLUGINS+=pgraster
PGRASTER_USES=		pgsql
SQLITE3_VARS=		INPUT_PLUGINS+=sqlite
SQLITE3_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MAKE_ARGS_OFF=	PNG=False
JPEG_USES=		jpeg
JPEG_MAKE_ARGS_OFF=	JPEG=False
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_MAKE_ARGS_OFF=	TIFF=False
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp
WEBP_MAKE_ARGS_OFF=	WEBP=False
PROJ_LIB_DEPENDS=	libproj.so:graphics/proj
PROJ_MAKE_ARGS_OFF=	PROJ=False

CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.2:graphics/py-cairo
CAIRO_MAKE_ARGS_OFF=	CAIRO=False

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # gcc c++11 support is broken on FreeBSD
.endif

pre-configure-SQLITE3-on:
	@if ! ${LOCALBASE}/bin/sqlite3 :memory: 'create virtual table foo using rtree(pkid, xmin, xmax, ymin, ymax)' > /dev/null 2>&1; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "The SQLite plugin requires libsqlite3 built with RTREE support"; \
		${ECHO_MSG} "Please, reinstall 'databases/sqlite3' port with R*Tree module enabled"; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' \
		-e 's#/usr/include#${LOCALBASE}/include#g' \
		${WRKSRC}/SConstruct

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mapnik-index \
		${STAGEDIR}${PREFIX}/bin/mapnik-render \
		${STAGEDIR}${PREFIX}/bin/shapeindex
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mapnik/input/*.input

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS.md CHANGELOG.md README.md docs" \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
