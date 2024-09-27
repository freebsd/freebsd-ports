PORTNAME=	duckdb
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system
WWW=		https://duckdb.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang ssl
USE_GITHUB=	yes
GH_TUPLE=	duckdb:duckdb_inet:eca867b2517af06eabc89ccd6234266e9a7d6d71:inet/extension/inet \
		duckdb:duckdb_spatial:bb9c829693965f029eb5a312aefed4c538fad781:spatial/extension/spatial \
		duckdb:substrait:be71387cf0a484dc7b261a0cb21abec0d0e0ce5c:sqlsmith/extension/substrait \
		duckdb:sqlite_scanner:315861963c8106397af36cbda10faebc8dae485a:sqlite/extension/sqlite_scanner \
		duckdb:duckdb_sqlsmith:f24be8b5b0cd0eeed7541e10cff42d7050771afc:sqlsmith/extension/sqlsmith \
		duckdb:duckdb_vss:77739ea5382cce3220af83803ac0b1e98b3ab7d8:vss/extension/vss
# the list of out-of-tree extensions is here: .github/config/out_of_tree_extensions.cmake

CXXFLAGS+=	-I${WRKSRC}/extension/inet/src/include \
		-I${WRKSRC}/extension/sqlsmith/src/include # https://github.com/duckdb/duckdb/issues/13971
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_UNITTESTS
CMAKE_ARGS=	-DOVERRIDE_GIT_DESCRIBE=v${DISTVERSION}-0-g0000000000
CMAKE_TESTING_ON=	BUILD_UNITTESTS # 1 test fails, Signal 11 during tests, see https://github.com/duckdb/duckdb/issues/13972
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack: works as empty target

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=			TPCE
OPTIONS_DEFAULT=		TPCE
OPTIONS_GROUP=			EXTENSIONS
OPTIONS_GROUP_EXTENSIONS=	AUTOCOMPLETE FTS HTTPFS ICU INET JEMALLOC JSON PARQUET SQLSMITH TPCDS TPCH \
				SQLITE_SCANNER

EXTENSIONS_DESC=		Extensions:

.for opt in ${OPTIONS_GROUP_EXTENSIONS}
.  if "${${opt}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${opt}
.  endif
${opt}_DESC=		Build the ${opt} extension
DUCKDB_EXTENSIONS+=	;${opt:tl}
${opt}_PLIST_FILES=	lib/lib${opt:tl}_extension.a
.endfor

CMAKE_ARGS+=	-DBUILD_EXTENSIONS="${DUCKDB_EXTENSIONS:tW:S/ //g:S/^;//}" \
		-DDUCKDB_MAJOR_VERSION=${PORTVERSION:R:R} \
		-DDUCKDB_MINOR_VERSION=${PORTVERSION:R:E} \
		-DDUCKDB_PATCH_VERSION=${PORTVERSION:E}

SQLITE_SCANNER_CXXFLAGS=	-I${WRKSRC}/extension/sqlite_scanner/src/include # workaround for the header not being found

TPCE_DESC=			Enable building of the TPC-E tool
TPCE_CMAKE_BOOL=		BUILD_TPCE

post-test: # run tests
	@cd ${TEST_WRKSRC} && test/unittest

.include <bsd.port.mk>
