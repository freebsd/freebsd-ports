PORTNAME=	duckdb
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	In-process SQL OLAP database management system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing compiler:c++11-lang
USE_GITHUB=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_UNITTESTS
CMAKE_TESTING_ON=	BUILD_UNITTESTS
CMAKE_TESTING_TARGET=	${ALL_TARGET} # hack: works as empty target

BINARY_ALIAS=	git=false

OPTIONS_GROUP=			EXTENSIONS
OPTIONS_GROUP_EXTENSIONS=	ICU PARQUET TPCH TPCDS FTS JSON EXCEL SQLSMITH SUBSTRAIT

EXTENSIONS_DESC=		Extensions:

.for opt in ${OPTIONS_GROUP_EXTENSIONS}
.  if "${${opt}_BROKEN}" == ""
OPTIONS_DEFAULT+=	${opt}
.  endif
${opt}_DESC=		Build the ${opt} extension
${opt}_CMAKE_BOOL=	BUILD_${opt}_EXTENSION
${opt}_PLIST_FILES=	lib/lib${opt:tl}_extension.a
.endfor

post-test: # run tests
	@cd ${TEST_WRKSRC} && test/unittest

.include <bsd.port.mk>
