# Ports collection makefile for:  pear-MDB
# Date created:			  2004-05-29
# Whom:				  Oleg Sharoiko <os@rsu.ru>
#
# $FreeBSD$
#

PORTNAME=	MDB
PORTVERSION=	1.3.0
CATEGORIES=	databases www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR unified API for DB access, based on user meta data

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		MDB.php MDB/Common.php MDB/querysim.php MDB/mssql.php	\
		MDB/ibase.php MDB/oci8.php MDB/fbsql.php MDB/mysql.php	\
		MDB/pgsql.php MDB/Date.php MDB/Manager.php 		\
		MDB/Parser.php MDB/metabase_wrapper.php			\
		MDB/peardb_wrapper.php					\
		MDB/reverse_engineer_xml_schema.php MDB/Modules/LOB.php	\
		MDB/Modules/Manager/Common.php				\
		MDB/Modules/Manager/mssql.php				\
		MDB/Modules/Manager/ibase.php				\
		MDB/Modules/Manager/oci8.php				\
		MDB/Modules/Manager/fbsql.php				\
		MDB/Modules/Manager/mysql.php				\
		MDB/Modules/Manager/pgsql.php
DOCS=		README MAINTAINERS TODO doc/tutorial.html doc/datatypes.html \
		doc/xml_schema_documentation.html doc/xml_schema.xsl \
		doc/skeleton.php doc/Modules_Manager_skeleton.php
TESTS=		README test.php clitest.php testchoose.php		\
		MDB_api_testcase.php MDB_manager_testcase.php		\
		MDB_usage_testcase.php MDB_bugs_testcase.php		\
		HTML_TestListener.php Console_TestListener.php		\
		tests.css testUtils.php test_setup.php.dist		\
		test.schema MDB_test.php MDB_pear_wrapper_test.php	\
		metapear_test_db.schema driver_test_config.php		\
		driver_test.php setup_test.php driver_test.schema	\
		lob_test.schema templates/results.tpl
_DOCSDIR=	.
_TESTDIR=	tests

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
