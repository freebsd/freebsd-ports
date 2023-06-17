PORTNAME=	duckdb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system
WWW=		https://duckdb.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang ssl
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_UNITTESTS
CMAKE_TESTING_ON=	BUILD_UNITTESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack: works as empty target

BINARY_ALIAS=	git=false

OPTIONS_DEFINE=			TPCE
OPTIONS_DEFAULT=		TPCE
OPTIONS_GROUP=			EXTENSIONS
OPTIONS_GROUP_EXTENSIONS=	EXCEL FTS HTTPFS ICU INET JEMALLOC JSON PARQUET TPCH TPCDS SQLSMITH VISUALIZER

EXTENSIONS_DESC=		Extensions:

.for opt in ${OPTIONS_GROUP_EXTENSIONS}
.  if "${${opt}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${opt}
.  endif
${opt}_DESC=		Build the ${opt} extension
${opt}_CMAKE_BOOL=	BUILD_${opt}_EXTENSION
${opt}_PLIST_FILES=	lib/lib${opt:tl}_extension.a
.endfor

TPCE_DESC=			Enable building of the TPC-E tool
TPCE_CMAKE_BOOL=		BUILD_TPCE

post-test: # run tests
	@cd ${TEST_WRKSRC} && test/unittest

.include <bsd.port.mk>
