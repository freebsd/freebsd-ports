# Created by: gahr
# $FreeBSD$

PORTNAME=	mysql-connector-c++
PORTVERSION=	1.1.9
PORTREVISION=	7
CATEGORIES=	databases
MASTER_SITES=	MYSQL/Connector-C++

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	MySQL database connector for C++

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		cmake compiler:c++11-lang mysql ssl
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DDOC_DESTINATION="${DOCSDIR}" -DCMAKE_ENABLE_C++11=ON 

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/INSTALL \
		${STAGEDIR}${DOCSDIR}/COPYING

.if defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-DMYSQLCPPCONN_TEST_NOT_IMPLEMENTED:BOOL=1 \
		-DMYSQLCPPCONN_BUILD_EXAMPLES:BOOL=1

do-test:
#	These tests assume that a database is running on localhost,
#	with user:root and pass:root
	(cd ${WRKDIR}/.build ; \
	test/CJUnitTestsPort/CJUnitTestsPort --verbose ; \
	test/driver_test --verbose ; \
	test/static_test --verbose ; \
	examples/connect --verbose ; \
	examples/connection_meta_schemaobj --verbose ; \
	examples/debug --verbose ; \
	examples/dynamic_load --verbose ; \
	examples/exceptions --verbose ; \
	examples/prepared_statement --verbose ; \
	examples/resultset --verbose ; \
	examples/resultset_binary --verbose ; \
	examples/resultset_meta --verbose ; \
	examples/resultset_types --verbose ; \
	examples/statement --verbose ; \
	test/unit/classes/art_resultset --verbose ; \
	test/unit/classes/connection --verbose ; \
	test/unit/classes/databasemetadata --verbose ; \
	test/unit/classes/parametermetadata --verbose ; \
	test/unit/classes/preparedstatement --verbose ; \
	test/unit/classes/resultset --verbose ; \
	test/unit/classes/resultsetmetadata --verbose ; \
	test/unit/classes/savepoint --verbose ; \
	test/unit/classes/statement )
.endif

.include <bsd.port.mk>
