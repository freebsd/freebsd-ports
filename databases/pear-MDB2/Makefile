# New ports collection makefile for:   pear-MDB2
# Date created:        26 November 2004
# Whom:                Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	MDB2
PORTVERSION=	2.3.0
CATEGORIES=	databases www pear

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	PEAR database abstraction layer

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		MDB2.php \
		MDB2/Driver/Datatype/Common.php MDB2/Driver/Function/Common.php \
		MDB2/Driver/Manager/Common.php  MDB2/Driver/Native/Common.php \
		MDB2/Driver/Reverse/Common.php \
		MDB2/Date.php MDB2/Extended.php MDB2/Iterator.php MDB2/LOB.php

DOCS=		CONTRIBUTORS datatypes.html MAINTAINERS README STATUS TODO
EXAMPLES=	example.php example_php5.php metapear_test_db.schema
_EXAMPLESDIR=	docs/examples

TESTS=		basic.phpt clitest.php config.php Console_TestListener.php \
		HTML_TestListener.php MDB2_api_testcase.php \
		MDB2_bugs_testcase.php MDB2_Connect_Test.php \
		MDB2_datatype_testcase.php MDB2_extended_testcase.php \
		MDB2_function_testcase.php MDB2_manager_testcase.php \
		MDB2_native_testcase.php MDB2_reverse_testcase.php \
		MDB2_testcase.php README MDB2_usage_testcase.php test.php \
		testchoose.php tests.css testUtils.php test_setup.php.dist \

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
