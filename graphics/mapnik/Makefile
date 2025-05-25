PORTNAME=	mapnik
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.6
PORTREVISION=	1
CATEGORIES=	graphics geography

PATCH_SITES=	https://github.com/mapnik/mapnik/commit/
PATCHFILES=	102cf2b2c4b58d3540b3ff15c65ad90335f3a80d.patch:-p1

MAINTAINER=	hummeltech@sherpaguru.com
COMMENT=	Free Toolkit For Developing Mapping Applications
WWW=		http://www.mapnik.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu \
		protozero>0:devel/protozero
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libboost_regex.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libicuuc.so:devel/icu
RUN_DEPENDS=	dejavu>0:x11-fonts/dejavu

USE_GITHUB=	yes
GH_ACCOUNT=	mapnik
GH_PROJECT=	mapnik
GH_TUPLE=	mapbox:geometry.hpp:c83a2ab:geometry_hpp/deps/mapbox/geometry \
		mapbox:polylabel:51f09d0:polylabel/deps/mapbox/polylabel \
		mapbox:variant:a2a4858:variant/deps/mapbox/variant \
		catchorg:Catch2:v2.13.10:catch2/test/catch2 \
		mapnik:test-data:41c4cee:test_data/test/data

USES=		compiler:c++20-lang cmake:testing gnome pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DFONTS_INSTALL_DIR:PATH=share/fonts/dejavu
CMAKE_ON=	USE_EXTERNAL_MAPBOX_PROTOZERO

OPTIONS_DEFINE=		CAIRO DOCS JPEG PNG PROJ TIFF WEBP
OPTIONS_DEFAULT=	CAIRO JPEG PNG PROJ TIFF WEBP \
			GDAL OGR PGRASTER POSTGIS SQLITE3 \
			TESTING \
			GEOMETRY_TO_WKB MAPNIK_INDEX MAPNIK_RENDER PGSQL2SQLITE SHAPEINDEX SVG2PNG
OPTIONS_GROUP=		INPUT TESTS UTILS
OPTIONS_GROUP_INPUT=	GDAL OGR PGRASTER POSTGIS SQLITE3
OPTIONS_GROUP_TESTS=	BENCHMARK DEMO_CPP DEMO_VIEWER TESTING
OPTIONS_GROUP_UTILS=	GEOMETRY_TO_WKB MAPNIK_INDEX MAPNIK_RENDER OGRINDEX PGSQL2SQLITE SHAPEINDEX SVG2PNG
OPTIONS_SUB=		yes

JPEG_CMAKE_BOOL=	USE_JPEG
JPEG_USES=		jpeg
PNG_CMAKE_BOOL=		USE_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png
TIFF_CMAKE_BOOL=	USE_TIFF
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
WEBP_CMAKE_BOOL=	USE_WEBP
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

CAIRO_DESC=		Enable cairo rendering
PROJ_DESC=		Enable PROJ support

INPUT_DESC=		Input plugins
GDAL_DESC=		GDAL input plugin
OGR_DESC=		OGR input plugin
PGRASTER_DESC=		PGraster input plugin
POSTGIS_DESC=		PostGIS input plugin
SQLITE3_DESC=		SQLite input plugin

TESTS_DESC=		Tests & Demos, etc.
BENCHMARK_DESC=		Benchmark project
DEMO_CPP_DESC=		Demo c++ application
DEMO_VIEWER_DESC=	Demo viewer
TESTING_DESC=		Tests

UTILS_DESC=		Utilities
GEOMETRY_TO_WKB_DESC=	geometry_to_wkb utility
MAPNIK_INDEX_DESC=	mapnik_index utility
MAPNIK_RENDER_DESC=	mapnik_render utility
OGRINDEX_DESC=		ogrindex utility (currently doesn't build)
PGSQL2SQLITE_DESC=	pgsql2sqlite utility
SHAPEINDEX_DESC=	shapeindex utility
SVG2PNG_DESC=		svg2png utility

CAIRO_CMAKE_BOOL=	USE_CAIRO
CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
PROJ_CMAKE_BOOL=	USE_PROJ
PROJ_LIB_DEPENDS=	libproj.so:graphics/proj

GDAL_CMAKE_BOOL=	USE_PLUGIN_INPUT_GDAL
GDAL_LIB_DEPENDS=	libgdal.so:graphics/gdal
OGR_CMAKE_BOOL=		USE_PLUGIN_INPUT_OGR
OGR_LIB_DEPENDS=	libgdal.so:graphics/gdal
PGRASTER_CMAKE_BOOL=	USE_PLUGIN_INPUT_PGRASTER
PGRASTER_USES=		pgsql
POSTGIS_CMAKE_BOOL=	USE_PLUGIN_INPUT_POSTGIS
POSTGIS_USES=		pgsql
SQLITE3_CMAKE_BOOL=	USE_PLUGIN_INPUT_SQLITE
SQLITE3_USES=		sqlite:3

BENCHMARK_CMAKE_BOOL= 	BUILD_BENCHMARK
DEMO_CPP_CMAKE_BOOL= 	BUILD_DEMO_CPP
DEMO_VIEWER_CMAKE_BOOL=	BUILD_DEMO_VIEWER
TESTING_CMAKE_BOOL=	BUILD_TESTING

GEOMETRY_TO_WKB_CMAKE_BOOL= 	BUILD_UTILITY_GEOMETRY_TO_WKB
MAPNIK_INDEX_CMAKE_BOOL= 	BUILD_UTILITY_MAPNIK_INDEX
MAPNIK_RENDER_CMAKE_BOOL= 	BUILD_UTILITY_MAPNIK_RENDER
OGRINDEX_CMAKE_BOOL= 		BUILD_UTILITY_OGRINDEX
PGSQL2SQLITE_CMAKE_BOOL= 	BUILD_UTILITY_PGSQL2SQLITE
SHAPEINDEX_CMAKE_BOOL= 		BUILD_UTILITY_SHAPEINDEX
SVG2PNG_CMAKE_BOOL= 		BUILD_UTILITY_SVG2PNG

pre-configure-SQLITE3-on:
	@if ! ${LOCALBASE}/bin/sqlite3 :memory: 'create virtual table foo using rtree(pkid, xmin, xmax, ymin, ymax)' > /dev/null 2>&1; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "The SQLite plugin requires libsqlite3 built with RTREE support"; \
		${ECHO_MSG} "Please, reinstall 'databases/sqlite3' port with R*Tree module enabled"; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's#GIT_REPOSITORY https://github.com/catchorg/Catch2.git#SOURCE_DIR ${WRKSRC}/test/catch2)#g' \
		-e 's#GIT_TAG        v2.13.7)##g' \
		${WRKSRC}/test/CMakeLists.txt

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/fonts
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mapnik/input/*.input

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS.md CHANGELOG.md CODE_OF_CONDUCT.md INSTALL.md README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/docs
	@cd ${WRKSRC} && ${INSTALL_DATA} docs/* ${STAGEDIR}${DOCSDIR}/docs

.include <bsd.port.mk>
