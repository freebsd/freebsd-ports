# Ports collection makefile for:  pear-PHPUnit2
# Date created:			  09 September 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit2
PORTVERSION=	2.0.2
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.if !defined(WITHOUT_BENCHMARK)
BUILD_DEPENDS+=	${PEARDIR}/Benchmark/Timer.php:${PORTSDIR}/benchmarks/pear-Benchmark
.endif

NO_PACKAGE=	Conflicting dependences between PHP4 and PHP5

USE_PHP=	yes
DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4

USE_REINPLACE=	yes

CATEGORY=	PHPUnit2
FILES=		Extensions/RepeatedTest.php Extensions/TestDecorator.php \
		Extensions/TestSetup.php Extensions/ExceptionTestCase.php \
		Framework/ComparisonFailure.php Framework/IncompleteTest.php \
		Framework/IncompleteTestError.php Framework/Test.php \
		Framework/TestCase.php Framework/TestFailure.php \
		Framework/TestListener.php Framework/TestResult.php \
		Framework/TestSuite.php Framework/Warning.php Framework/Assert.php \
		Framework/AssertionFailedError.php Runner/TestCollector.php \
		Runner/TestRunListener.php Runner/TestSuiteLoader.php \
		Runner/Version.php Runner/BaseTestRunner.php \
		Runner/StandardTestSuiteLoader.php Tests/Framework/AssertTest.php \
		Tests/Framework/SuiteTest.php Tests/Framework/TestCaseTest.php \
		Tests/Framework/TestImplementorTest.php \
		Tests/Framework/TestListenerTest.php Tests/Framework/AllTests.php \
		Tests/Framework/ComparisonFailureTest.php \
		Tests/Extensions/ExtensionTest.php \
		Tests/Extensions/RepeatedTestTest.php Tests/Extensions/AllTests.php \
		Tests/Extensions/ExceptionTestCaseTest.php Tests/Runner/AllTests.php \
		Tests/Runner/BaseTestRunnerTest.php Tests/DoubleTestCase.php \
		Tests/Error.php Tests/Failure.php Tests/InheritedTestCase.php \
		Tests/MockRunner.php Tests/NoArgTestCaseTest.php Tests/NonStatic.php \
		Tests/NoTestCaseClass.php Tests/NoTestCases.php \
		Tests/NotPublicTestCase.php Tests/NotVoidTestCase.php \
		Tests/OneTestCase.php Tests/OverrideTestCase.php Tests/SetupFailure.php \
		Tests/Success.php Tests/TearDownFailure.php \
		Tests/ThrowExceptionTestCase.php Tests/ThrowNoExceptionTestCase.php \
		Tests/TornDown.php Tests/TornDown2.php Tests/TornDown3.php \
		Tests/TornDown4.php Tests/TornDown5.php Tests/WasRun.php \
		Tests/AllTests.php TextUI/TestRunner.php TextUI/ResultPrinter.php \
		Util/Printer.php Util/Filter.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"

post-patch:
	@${REINPLACE_CMD} -e "s|@version@|${PORTVERSION}|" ${WRKSRC}/Runner/Version.php

.include <bsd.port.post.mk>
