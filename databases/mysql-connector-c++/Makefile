# Created by: gahr
# $FreeBSD$

PORTNAME=	mysql-connector-c++
PORTVERSION=	1.1.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL}
MASTER_SITE_SUBDIR=	Connector-C++

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A MySQL database connector for C++

LICENSE=	GPLv2

LIB_DEPENDS=	boost_regex:${PORTSDIR}/devel/boost-libs

USE_MYSQL=	51+
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-DMYSQLCPPCONN_TEST_NOT_IMPLEMENTED:BOOL=1 \
		-DMYSQLCPPCONN_BUILD_EXAMPLES:BOOL=1
.endif

regression-test: build
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

.include <bsd.port.mk>
