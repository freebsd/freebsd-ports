# Ports collection makefile for:  pear-PHPUnit2
# Date created:			  09 September 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit2
PORTVERSION=	2.2.1
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/Benchmark/Timer.php:${PORTSDIR}/benchmarks/pear-Benchmark
RUN_DEPENDS=	${BUILD_DEPENDS}

OPTIONS=	PEAR_LOG "PEAR::Log support" off \
		DOM "PHP DOM extension support" off

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	pear-${PORTNAME}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

.if defined(WITH_DOM)
USE_PHP=	dom
.endif

NO_PACKAGE=	Conflicting dependences between PHP4 and PHP5

DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4

USE_REINPLACE=	yes

CATEGORY=	PHPUnit2
FILES=		Extensions/CodeCoverage/Renderer/HTML.php \
		Extensions/CodeCoverage/Renderer/Text.php \
		Extensions/CodeCoverage/Renderer.php Extensions/Log/PEAR.php \
		Extensions/Log/XML.php Extensions/TestDox/ResultPrinter/HTML.php \
		Extensions/TestDox/ResultPrinter/Text.php \
		Extensions/TestDox/NamePrettifier.php \
		Extensions/TestDox/ResultPrinter.php \
		Extensions/ExceptionTestCase.php Extensions/PerformanceTestCase.php \
		Extensions/RepeatedTest.php \
		Extensions/TestDecorator.php Extensions/TestSetup.php \
		Framework/Assert.php Framework/AssertionFailedError.php \
		Framework/Error.php Framework/ComparisonFailure.php \
		Framework/IncompleteTest.php Framework/IncompleteTestError.php \
		Framework/Test.php Framework/TestCase.php Framework/TestFailure.php \
		Framework/TestListener.php Framework/TestResult.php \
		Framework/TestSuite.php Framework/Warning.php \
		Runner/BaseTestRunner.php Runner/IncludePathTestCollector.php \
		Runner/StandardTestSuiteLoader.php Runner/TestCollector.php \
		Runner/TestRunListener.php Runner/TestSuiteLoader.php \
		Runner/Version.php Tests/Framework/AllTests.php \
		Tests/Framework/AssertTest.php \
		Tests/Framework/ComparisonFailureTest.php Tests/Framework/SuiteTest.php \
		Tests/Framework/TestCaseTest.php Tests/Framework/TestImplementorTest.php \
		Tests/Framework/TestListenerTest.php Tests/Extensions/TestDox/AllTests.php \
		Tests/Extensions/TestDox/NamePrettifierTest.php \
		Tests/Extensions/AllTests.php Tests/Extensions/ExceptionTestCaseTest.php \
		Tests/Extensions/ExtensionTest.php \
		Tests/Extensions/PerformanceTestCaseTest.php \
		Tests/Extensions/RepeatedTestTest.php Tests/Runner/AllTests.php \
		Tests/Runner/BaseTestRunnerTest.php Tests/AllTests.php \
		Tests/DoubleTestCase.php Tests/Error.php Tests/Failure.php \
		Tests/InheritedTestCase.php Tests/Iterator.php Tests/MockRunner.php \
		Tests/NoArgTestCaseTest.php Tests/NonStatic.php Tests/NoTestCaseClass.php \
		Tests/NoTestCases.php Tests/NotPublicTestCase.php Tests/NotVoidTestCase.php \
		Tests/OneTestCase.php Tests/OverrideTestCase.php Tests/SetupFailure.php \
		Tests/Sleep.php Tests/Success.php Tests/TearDownFailure.php \
		Tests/ThrowExceptionTestCase.php Tests/ThrowNoExceptionTestCase.php \
		Tests/TornDown.php Tests/TornDown2.php Tests/TornDown3.php \
		Tests/TornDown4.php Tests/TornDown5.php Tests/WasRun.php \
		TextUI/ResultPrinter.php TextUI/TestRunner.php Util/Filter.php \
		Util/Printer.php Util/Skeleton.php
SCRIPTFILES=	phpunit

post-patch:
	@${REINPLACE_CMD} -e "s|@version@|${PORTVERSION}|" ${WRKSRC}/Runner/Version.php

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
.endif

.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
