# Ports collection makefile for:  pear-MDB_QueryTool
# Date created:			  03 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	MDB_QueryTool
PORTVERSION=	1.0.0
CATEGORIES=	databases www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR OO-interface for easily retrieving and modifying data in a DB

BUILD_DEPENDS=	${PEARDIR}/MDB.php:${PORTSDIR}/databases/pear-MDB \
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	MDB
FILES=		QueryTool.php QueryTool/Query.php QueryTool/EasyJoin.php \
		QueryTool/Result.php QueryTool/Result/Object.php
EXAMPLES=	example.php mysql.sql pgsql.sql
TESTS=		Common.php index.php Get.php GetAll.php GetCount.php GetQueryString.php \
		Having.php Limit.php SetDbInstance.php sql.php UnitTest.php Where.php \
		simpletest_tests/all_tests.php simpletest_tests/db_settings.php \
		simpletest_tests/index.php simpletest_tests/mdb_querytool_include.php \
		simpletest_tests/mdb_querytool_test_base.php \
		simpletest_tests/mdb_querytool_testDbInstance.php \
		simpletest_tests/mdb_querytool_testGet.php \
		simpletest_tests/mdb_querytool_testGetAll.php \
		simpletest_tests/mdb_querytool_testGetCount.php \
		simpletest_tests/mdb_querytool_testGetQueryString.php \
		simpletest_tests/mdb_querytool_testHaving.php \
		simpletest_tests/mdb_querytool_testLimit.php \
		simpletest_tests/mdb_querytool_tests_get.php \
		simpletest_tests/mdb_querytool_tests_usage.php \
		simpletest_tests/mdb_querytool_testWhere.php simpletest_tests/readme.txt \
		simpletest_tests/simple_include.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
