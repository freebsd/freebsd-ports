PORTNAME=	duckdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system
WWW=		https://duckdb.org/ \
		https://github.com/duckdb/duckdb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang ssl
USE_GITHUB=	yes
GH_TUPLE=	\
		duckdb:duckdb-excel:f14e7c3beaf379c54b47b996aa896a1d814e1be8:excel/extension/excel \
		duckdb:duckdb-fts:3aa6a180b9c101d78070f5f7214c27552bb091c8:fts/extension/fts \
		duckdb:duckdb-httpfs:85ac4667bcb0d868199e156f8dd918b0278db7b9:httpfs/extension/httpfs \
		duckdb:duckdb-inet:a8b361ab5d43f6390d7cb48c9a9f0638e9581cf9:inet/extension/inet \
		duckdb:duckdb-spatial:2905968a85703e5ca3698976daafd759554e1744:spatial/extension/spatial \
		duckdb:duckdb-sqlite:96e451c043afa40ee39b7581009ba0c72a523a12:sqlite/extension/sqlite_scanner \
		duckdb:duckdb-sqlsmith:e1eb0ae02a258f176d6e06b84c0d6c7a09c6b4da:sqlsmith/extension/sqlsmith \
		duckdb:duckdb-vss:580e8918eb89f478cf2d233ca908ffbd3ec752c5:vss/extension/vss
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
OPTIONS_GROUP_EXTENSIONS=	AUTOCOMPLETE FTS HTTPFS ICU INET JSON PARQUET SQLSMITH TPCDS TPCH \
				SQLITE_SCANNER VSS

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

TPCE_DESC=			Enable building of the TPC-E tool
TPCE_CMAKE_BOOL=		BUILD_TPCE

VSS_CXXFLAGS=			-I${WRKSRC}/extension/vss/src/include # workaround for the header not being found

post-extract: # remove the jemalloc extension directory just in case
	@${RM} -r ${WRKSRC}/extension/jemalloc

post-test: # run tests
	@cd ${TEST_WRKSRC} && test/unittest

# tests as of 1.2.1: All tests passed (48 skipped tests, 398067 assertions in 3602 test cases)

.include <bsd.port.mk>
