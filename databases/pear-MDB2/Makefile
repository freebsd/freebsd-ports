# New ports collection makefile for:   pear-MDB2
# Date created:        26 November 2004
# Whom:                Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	MDB2
DISTVERSION=	2.5.0b2
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR database abstraction layer

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		LICENSE MDB2.php \
		MDB2/Date.php MDB2/Extended.php MDB2/Iterator.php MDB2/LOB.php \
		MDB2/Driver/Datatype/Common.php MDB2/Driver/Function/Common.php \
		MDB2/Driver/Manager/Common.php  MDB2/Driver/Native/Common.php \
		MDB2/Driver/Reverse/Common.php \

TESTS=		Console_TestListener.php HTML_TestListener.php MDB2_Connect_Test.php \
		MDB2_api_testcase.php MDB2_bugs_testcase.php MDB2_datatype_testcase.php \
		MDB2_extended_testcase.php MDB2_function_testcase.php MDB2_internals_testcase.php \
		MDB2_manager_testcase.php MDB2_native_testcase.php MDB2_nonstandard.php \
		MDB2_nonstandard_ibase.php MDB2_nonstandard_mssql.php MDB2_nonstandard_mysql.php \
		MDB2_nonstandard_mysqli.php MDB2_nonstandard_oci8.php MDB2_nonstandard_pgsql.php \
		MDB2_nonstandard_sqlite.php MDB2_reverse_testcase.php MDB2_testcase.php \
		MDB2_usage_testcase.php README basic.phpt clitest.php config.php \
		driver_test.schema.xml import.schema.php test.php testUtils.php test_setup.php.dist \
		tests.css

DOCS=		CONTRIBUTORS datatypes.html MAINTAINERS README STATUS TODO

EXAMPLES=	example.php example_php5.php metapear_test_db.schema
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
