# New ports collection makefile for:   pear-MDB2
# Date created:        26 November 2004
# Whom:                Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	MDB2
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	databases www pear
DISTNAME=	${PORTNAME}-${PORTVERSION}beta3

MAINTAINER=	antonio@php.net
COMMENT=	PEAR database abstraction layer

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		MDB2/Date.php MDB2/Extended.php MDB2/Iterator.php MDB2/LOB.php \
		MDB2/Driver/fbsql.php MDB2/Driver/ibase.php MDB2/Driver/mssql.php \
		MDB2/Driver/mysql.php MDB2/Driver/mysqli.php MDB2/Driver/oci8.php \
		MDB2/Driver/pgsql.php MDB2/Driver/querysim.php MDB2/Driver/sqlite.php \
		MDB2/Driver/Datatype/Common.php MDB2/Driver/Datatype/fbsql.php \
		MDB2/Driver/Datatype/ibase.php MDB2/Driver/Datatype/mssql.php \
		MDB2/Driver/Datatype/mysql.php MDB2/Driver/Datatype/mysqli.php \
		MDB2/Driver/Datatype/oci8.php MDB2/Driver/Datatype/pgsql.php \
		MDB2/Driver/Datatype/sqlite.php MDB2/Driver/Manager/Common.php \
		MDB2/Driver/Manager/fbsql.php MDB2/Driver/Manager/ibase.php \
		MDB2/Driver/Manager/mssql.php MDB2/Driver/Manager/mysql.php \
		MDB2/Driver/Manager/mysqli.php MDB2/Driver/Manager/oci8.php \
		MDB2/Driver/Manager/pgsql.php MDB2/Driver/Manager/sqlite.php \
		MDB2/Driver/Native/fbsql.php MDB2/Driver/Native/ibase.php \
		MDB2/Driver/Native/mssql.php MDB2/Driver/Native/mysql.php \
		MDB2/Driver/Native/mysqli.php MDB2/Driver/Native/oci8.php \
		MDB2/Driver/Native/pgsql.php MDB2/Driver/Native/sqlite.php \
		MDB2/Driver/Reverse/Common.php MDB2/Driver/Reverse/fbsql.php \
		MDB2/Driver/Reverse/ibase.php MDB2/Driver/Reverse/mssql.php \
		MDB2/Driver/Reverse/mysql.php MDB2/Driver/Reverse/mysqli.php \
		MDB2/Driver/Reverse/oci8.php MDB2/Driver/Reverse/pgsql.php \
		MDB2/Driver/Reverse/sqlite.php MDB2/Tools/Manager.php \
		MDB2/Tools/reverse_engineer_xml_schema.php \
		MDB2/Tools/Manager/Parser.php MDB2/Tools/Manager/Writer.php \
		MDB2/Wrapper/peardb.php MDB2.php
DOCS=		CONTRIBUTORS datatypes.html Driver_Datatype_skeleton.php \
		Driver_Manager_skeleton.php Driver_Native_skeleton.php \
		Driver_Reverse_skeleton.php Driver_skeleton.php MAINTAINERS \
		MDB.dtd MDB.xsl querysim_readme.txt README STATUS TODO \
		xml_schema_documentation.html
EXAMPLES=	example.php metapear_test_db.schema peardb_wrapper_example.php
TESTS=		clitest.php Console_TestListener.php driver_test.schema \
		HTML_TestListener.php lob_test.schema MDB2_api_testcase.php \
		MDB2_bugs_testcase.php MDB2_manager_testcase.php \
		MDB2_native_testcase.php MDB2_reverse_testcase.php \
		MDB2_usage_testcase.php README test.php testchoose.php \
		tests.css testUtils.php test_setup.php.dist templates/results.tpl
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
