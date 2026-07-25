PORTNAME=	duckdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
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

USES=		cmake:testing compiler:c++11-lang cpe ssl
USE_GITHUB=	yes
GH_TUPLE=	\
		duckdb:duckdb-avro:f9d590297485f0318f480372c70bdd852826e258:avro/extension/avro \
		duckdb:duckdb-aws:efa54a990e16c976576685dd4134d2478cf5a574:aws/extension/aws \
		duckdb:duckdb-azure:003214c96d0caa39d5c3e27a9e1976a0692c7d37:azure/extension/azure \
		duckdb:ducklake:d8a1881e22516ea3d186d73e83c65fe5bd1a1dc4:ducklake/extension/ducklake \
		duckdb:duckdb-encodings:06295e77b13de65842992c82f14289ea679e4730:encodings/extension/encodings \
		duckdb:duckdb-excel:f4c72b5ef04a03b3a78a95b5a2ee94ba93e3178d:excel/extension/excel \
		duckdb:duckdb-fts:6814ec9a7d5fd63500176507262b0dbf7cea0095:fts/extension/fts \
		duckdb:duckdb-httpfs:827222fb45a043a7a852d1f7aae46901492a3cda:httpfs/extension/httpfs \
		duckdb:duckdb-iceberg:45163a28e0ed6a2071a82a1bf1dd432d0216cf9c:iceberg/extension/iceberg \
		duckdb:duckdb-inet:fe7f60bb60245197680fb07ecd1629a1dc3d91c8:inet/extension/inet \
		duckdb:duckdb-postgres:41223e51559cd581f1c06e170b71c71df25bbaac:postgres/extension/postgres_scanner \
		duckdb:duckdb-mysql:7267164dab3409e943261aeee6ae32f1b00847a7:mysql/extension/mysql_scanner \
		duckdb:odbc-scanner:274a3307341dcafd62471c09b45c5d858d6c95cc:odbc_scanner/extension/odbc_scanner \
		duckdb:duckdb-quack:c1548111c1bfd16207e22fd3cb7e4bde1335b9d0:quack/extension/quack \
		duckdb:duckdb-spatial:eb1e57c9d92c0f3f76eb03eaa52c315090f328cc:spatial/extension/spatial \
		duckdb:duckdb-sqlite:f79b1db7d7730b18d0f8400d3650ffa6b45168d8:sqlite/extension/sqlite_scanner \
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

# tests as of 1.5.5: All tests passed (21 skipped tests, 982095 assertions in 4564 test cases)

.include <bsd.port.mk>
