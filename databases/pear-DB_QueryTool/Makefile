# Ports collection makefile for:  pear-DB_QueryTool
# Date created:			  03 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	DB_QueryTool
PORTVERSION=	1.0.0
CATEGORIES=	databases www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR OO-interface for easily retrieving and modifying data in a DB

BUILD_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	DB
FILES=		QueryTool.php QueryTool/Query.php QueryTool/EasyJoin.php \
		QueryTool/Result.php QueryTool/Result/Object.php
EXAMPLES=	example.php mysql.sql pgsql.sql
TESTS=		Common.php Get.php GetAll.php GetCount.php GetQueryString.php index.php \
		Having.php Limit.php sql.php UnitTest.php Where.php SetDbInstance.php \
		simpletest_tests/all_tests.php simpletest_tests/db_querytool_include.php \
		simpletest_tests/db_querytool_test_base.php \
		simpletest_tests/db_querytool_testDbInstance.php \
		simpletest_tests/db_querytool_testGet.php \
		simpletest_tests/db_querytool_testGetAll.php \
		simpletest_tests/db_querytool_testGetCount.php \
		simpletest_tests/db_querytool_testGetQueryString.php \
		simpletest_tests/db_querytool_testHaving.php \
		simpletest_tests/db_querytool_testLimit.php \
		simpletest_tests/db_querytool_tests_get.php \
		simpletest_tests/db_querytool_tests_usage.php \
		simpletest_tests/db_querytool_testWhere.php \
		simpletest_tests/db_settings.php simpletest_tests/index.php \
		simpletest_tests/readme.txt simpletest_tests/simple_include.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
