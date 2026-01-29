PORTNAME=	duckdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.4
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system
WWW=		https://duckdb.org/ \
		https://github.com/duckdb/duckdb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake:testing compiler:c++11-lang ssl
USE_GITHUB=	yes
GH_TUPLE=	\
		duckdb:duckdb-encodings:b5a547ec74fad87698ed3142033d7b9cf86e0b2f:encodings/extension/encodings \
		duckdb:duckdb-excel:9421a2d75bd7544336caa73e5f9e6063cc7f6992:excel/extension/excel \
		duckdb:duckdb-fts:39376623630a968154bef4e6930d12ad0b59d7fb:fts/extension/fts \
		duckdb:duckdb-httpfs:13f8a814d41a978c3f19eb1dc76069489652ea6f:httpfs/extension/httpfs \
		duckdb:duckdb-inet:fe7f60bb60245197680fb07ecd1629a1dc3d91c8:inet/extension/inet \
		duckdb:duckdb-spatial:f129b24b4ddd4d98cfc18f88be5a344a79040e7b:spatial/extension/spatial \
		duckdb:duckdb-sqlite:0c93d610af1e1f66292559fcf0f01a93597a98b6:sqlite/extension/sqlite_scanner \
		duckdb:duckdb-sqlsmith:e6e6750ceb91e1869b2c736abb70d818bac73e9a:sqlsmith/extension/sqlsmith \
		duckdb:duckdb-vss:9b25336989efdca9598ae90364ce13cc976f2f31:vss/extension/vss
# the list of out-of-tree extensions is here: .github/config/out_of_tree_extensions.cmake

CXXFLAGS+=	-I${WRKSRC}/extension/inet/src/include 
CXXFLAGS+=	-I${WRKSRC}/extension/sqlsmith/src/include # https://github.com/duckdb/duckdb/issues/13971
CXXFLAGS+=	-I${WRKSRC}/extension/fts/extension/fts/include # --""--
CXXFLAGS+=	-I${WRKSRC}/extension/httpfs/extension/httpfs/include # --""--
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_UNITTESTS
CMAKE_ARGS=	-DOVERRIDE_GIT_DESCRIBE=v${DISTVERSION}-0-g0000000000
CMAKE_TESTING_ON=	BUILD_UNITTESTS # 1 test fails, Signal 11 during tests, see https://github.com/duckdb/duckdb/issues/13972
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack: works as empty target

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=			TPCE
OPTIONS_DEFAULT=		TPCE
OPTIONS_GROUP=			EXTENSIONS
OPTIONS_GROUP_EXTENSIONS=	AUTOCOMPLETE DELTA ICU JSON PARQUET TPCDS TPCH # in-tree extensions (in extension/)
OPTIONS_GROUP_EXTENSIONS+=	${GH_TUPLE:C/.*extension\///:tu} # out-of-tree extensions (from GH_TUPLE)

DELTA_BROKEN=	Fetches from git during build
SPATIAL_BROKEN=	Build requires unofficial-sqlite3 dependency
EXCEL_BROKEN=	https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=292757

EXTENSIONS_DESC=		Extensions:

.for opt in ${OPTIONS_GROUP_EXTENSIONS}
.  if "${${opt}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${opt}
.  endif
${opt}_DESC=		Build the ${opt} extension
DUCKDB_EXTENSIONS+=	${PORT_OPTIONS:M${opt}:S/${opt}/;${opt:tl}/}
${opt}_PLIST_FILES=	${PORT_OPTIONS:M${opt}:S/${opt}/lib\/lib${opt:tl}_extension.a/}
.endfor

CMAKE_ARGS+=	-DBUILD_EXTENSIONS="${DUCKDB_EXTENSIONS:tW:S/ //g:S/^;//}" \
		-DDUCKDB_MAJOR_VERSION=${PORTVERSION:R:R} \
		-DDUCKDB_MINOR_VERSION=${PORTVERSION:R:E} \
		-DDUCKDB_PATCH_VERSION=${PORTVERSION:E}
CMAKE_ARGS+=	-DSKIP_EXTENSIONS=jemalloc # temporary? see https://github.com/duckdb/duckdb/issues/14363#issuecomment-2412095766


SQLITE_SCANNER_CXXFLAGS=	-I${WRKSRC}/extension/sqlite_scanner/src/include # workaround for the header not being found
ENCODINGS_CXXFLAGS=		-I${WRKSRC}/extension/encodings/src/include # workaround for the header not being found
HTTPFS_CXXFLAGS=		-I${WRKSRC}/extension/httpfs/src/include # workaround for the header not being found

TPCE_DESC=			Enable building of the TPC-E tool
TPCE_CMAKE_BOOL=		BUILD_TPCE

VSS_CXXFLAGS=			-I${WRKSRC}/extension/vss/src/include # workaround for the header not being found

post-extract: # remove the jemalloc extension directory just in case
	@${RM} -r ${WRKSRC}/extension/jemalloc

post-patch: # remove cmake files of out-of-tree extensions to build them like in-tree extensions (avoid fetching from git)
	@${RM} ${WRKSRC}/.github/config/extensions/*.cmake

post-test: # run tests
	@cd ${TEST_WRKSRC} && test/unittest

# tests as of 1.4.4: All tests passed (28 skipped tests, 365953 assertions in 4014 test cases)

.include <bsd.port.mk>
