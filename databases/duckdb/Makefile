PORTNAME=	duckdb
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system
WWW=		https://duckdb.org/ \
		https://github.com/duckdb/duckdb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cmake:testing compiler:c++11-lang cpe ssl
USE_GITHUB=	yes
GH_TUPLE=	\
		duckdb:duckdb-avro:758fb6063cbb6da49b2e1c16c4044cfcafefc52f:avro/extension/avro \
		duckdb:duckdb-aws:16ae9c135300f750478d648c2496f2952a6f2827:aws/extension/aws \
		duckdb:duckdb-azure:906e92458c33309e5d9413e14a85aad7b4d2275f:azure/extension/azure \
		duckdb:ducklake:417a9117f590e8141742ac0579d02f6a90162e37:ducklake/extension/ducklake \
		duckdb:duckdb-encodings:2d1447a890302d9dff23ac7c8119ddce53ee65ff:encodings/extension/encodings \
		duckdb:duckdb-excel:81bb84b115b97cc4edec4827714cac80da0127e1:excel/extension/excel \
		duckdb:duckdb-fts:2266e67d01c737cb65114e77c7c672e58869a635:fts/extension/fts \
		duckdb:duckdb-httpfs:77392a72077a85897db2519fae11e2c0da972b8a:httpfs/extension/httpfs \
		duckdb:duckdb-iceberg:4c0c0874c48ec82a3e29910554891d04bcc0e988:iceberg/extension/iceberg \
		duckdb:duckdb-inet:fe7f60bb60245197680fb07ecd1629a1dc3d91c8:inet/extension/inet \
		duckdb:duckdb-legacy-parser:bcdf276132fe3a09afcc707c1cdff39096989404:legacy_parser/extension/legacy_parser \
		duckdb:duckdb-postgres:c0f5a3c0c4b68b02afbf669d36d7f0e503985c88:postgres/extension/postgres_scanner \
		duckdb:duckdb-mysql:f7fc0d42716534aa5ad48626d21ced9807b33967:mysql/extension/mysql_scanner \
		duckdb:odbc-scanner:a33698df40f95cc3eb339703dcb085497eabfca3:odbc_scanner/extension/odbc_scanner \
		duckdb:duckdb-quack:f96420ed46aee9c42064bdb99ddfd1230d6c0086:quack/extension/quack \
		duckdb:duckdb-spatial:4e066c17e2d1f24625baff4c62430d68ceb4e41f:spatial/extension/spatial \
		duckdb:duckdb-sqlite:e223dc01493414cef6d5960744f1e048d59fc592:sqlite/extension/sqlite_scanner \
		duckdb:database-connector:c305670b5729cc6dbda8d395eeb63b4d1487c064:sqlite_db_connector/extension/sqlite_scanner/database-connector \
		duckdb:duckdb-sqlsmith:00c4e5796c4e3e1f98ff4adec55d87326d2d2f3c:sqlsmith/extension/sqlsmith \
		duckdb:duckdb-vss:3685131eacaf0d467d430be5c4e5e7d1d483437a:vss/extension/vss
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
OPTIONS_GROUP_EXTENSIONS+=	${GH_TUPLE:C/.*extension\///:tu:N*/*} # out-of-tree extensions (from GH_TUPLE, excluding submodules)

DELTA_BROKEN=			Fetches from git during build
SPATIAL_BROKEN=			Build requires unofficial-sqlite3 dependency
EXCEL_BROKEN=			https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=292757
MYSQL_SCANNER_BROKEN=		https://github.com/duckdb/duckdb-mysql/issues/207
POSTGRES_SCANNER_BROKEN=	https://github.com/duckdb/duckdb-postgres/issues/401
SQLSMITH_BROKEN=		https://github.com/duckdb/duckdb-sqlsmith/issues/66
AZURE_BROKEN=			Broken because of missing Azure C++ SDK in ports
ICEBERG_BROKEN=			Broken because of missing roaring dependency
DUCKLAKE_BROKEN=		Broken because of missing roaring dependency
QUACK_BROKEN=			Need to investigate

AVRO_LIB_DEPENDS=		libavro.so:devel/avro-c \
				libjansson.so:devel/jansson \
				libsnappy.so:archivers/snappy
AVRO_BROKEN=			requires custom fork of avro-c: duckdb/duckdb-avro-c
AWS_LIB_DEPENDS=		libaws-cpp-sdk-core.so:devel/aws-sdk-cpp
AWS_BROKEN=			need to investigate
ODBC_SCANNER_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_SCANNER_BROKEN=		need to investigate

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
POSTGRES_SCANNER_USES=		localbase
POSTGRES_SCANNER_CXXFLAGS=	-I${WRKSRC}/extension/postgres_scanner/src/include # workaround for the header not being found
MYSQL_SCANNER_USES=		mysql:client

TPCE_DESC=			Enable building of the TPC-E tool
TPCE_CMAKE_BOOL=		BUILD_TPCE

VSS_CXXFLAGS=			-I${WRKSRC}/extension/vss/src/include # workaround for the header not being found

post-extract:
	# remove the jemalloc extension directory just in case
	@${RM} -r ${WRKSRC}/extension/jemalloc

post-patch: # remove cmake files of out-of-tree extensions to build them like in-tree extensions (avoid fetching from git)
	@${RM} ${WRKSRC}/.github/config/extensions/*.cmake

post-test: # run tests
	@cd ${TEST_WRKSRC} && test/unittest "test/sql/*" "~*.test_slow"

# tests as of 2.0.0: All tests passed (21 skipped tests, 276555 assertions in 4734 test cases)

.include <bsd.port.mk>
