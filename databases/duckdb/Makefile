PORTNAME=	duckdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.3
CATEGORIES=	databases
MASTER_SITES=	https://github.com/postgres/postgres/archive/refs/tags/:postgres_sources
DISTFILES=	REL_15_13.tar.gz:postgres_sources

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
		duckdb:duckdb-avro:7f423d69709045e38f8431b3470e0395fce1a595:avro/extension/avro \
		duckdb:duckdb-aws:38d4ed30b7f5855168f4b494bf9be611c868c69a:aws/extension/aws \
		duckdb:duckdb-azure:2ad247d4ca090cd2110f2e35531ab6fcdb80c186:azure/extension/azure \
		duckdb:ducklake:e6a3bd0a8554b74d97cbc7e8acc3e2c9f01a0385:ducklake/extension/ducklake \
		duckdb:duckdb-encodings:06295e77b13de65842992c82f14289ea679e4730:encodings/extension/encodings \
		duckdb:duckdb-excel:f4c72b5ef04a03b3a78a95b5a2ee94ba93e3178d:excel/extension/excel \
		duckdb:duckdb-fts:6814ec9a7d5fd63500176507262b0dbf7cea0095:fts/extension/fts \
		duckdb:duckdb-httpfs:52afb4204a3238d6ee132e83340f8d68c40ee91c:httpfs/extension/httpfs \
		duckdb:duckdb-iceberg:4008894c57168e0e9dff00e87cd725c5168fd81e:iceberg/extension/iceberg \
		duckdb:duckdb-inet:fe7f60bb60245197680fb07ecd1629a1dc3d91c8:inet/extension/inet \
		duckdb:duckdb-postgres:6b2b12cad3afef61e8a4637e714e8a88895fed1a:postgres/extension/postgres_scanner \
		duckdb:duckdb-mysql:496ac9e3cb61bd8d6d1255f73cf69b958a311525:mysql/extension/mysql_scanner \
		duckdb:odbc-scanner:8a3266017af8a9abf14a49e2fd5df83d64eb5520:odbc_scanner/extension/odbc_scanner \
		duckdb:duckdb-quack:1693647c152b438aa2a6a9ad71764f99c5a561e0:quack/extension/quack \
		duckdb:duckdb-spatial:b68b309d371dba936c5bb362980e559b7756b16d:spatial/extension/spatial \
		duckdb:duckdb-sqlite:a087a5878900d8bae155e97fd1b18c4cec0cca21:sqlite/extension/sqlite_scanner \
		duckdb:duckdb-sqlsmith:e47106c6fef6e019feaf8cedfc2ef737428a386c:sqlsmith/extension/sqlsmith \
		duckdb:duckdb-vss:b833341c8737fd3f3558c7720cc575ae8fc82598:vss/extension/vss
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
LIB_DEPENDS+=		${PORT_OPTIONS:M${opt}:?${${opt}_LIB_DEPENDS}:}
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
	# create symlink to Postgres sources for the postgres_scanner extension
	@${LN} -s ${WRKDIR}/postgres-REL_15_13 ${WRKSRC}/extension/postgres_scanner/postgres

post-patch: # remove cmake files of out-of-tree extensions to build them like in-tree extensions (avoid fetching from git)
	@${RM} ${WRKSRC}/.github/config/extensions/*.cmake

post-test: # run tests
	@cd ${TEST_WRKSRC} && test/unittest

# tests as of 1.5.3: All tests passed (22 skipped tests, 978885 assertions in 4469 test cases)

.include <bsd.port.mk>
