# Ports collection makefile for:  pear-PHPUnit2
# Date created:			  09 September 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit2
PORTVERSION=	2.3.4
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/Benchmark/Timer.php:${PORTSDIR}/benchmarks/pear-Benchmark
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_LOG "PEAR::Log support" off

USE_PHP=	dom pcre

NO_PACKAGE=	"Conflicting dependences between PHP4 and PHP5"

DEFAULT_PHP_VER=5
BROKEN_WITH_PHP=4

CATEGORY=	PHPUnit2
FILES=		Extensions/ExceptionTestCase.php \
		Extensions/PerformanceTestCase.php Extensions/RepeatedTest.php \
		Extensions/TestDecorator.php Extensions/TestSetup.php \
		Framework/Assert.php Framework/AssertionFailedError.php \
		Framework/Error.php Framework/ComparisonFailure.php \
		Framework/IncompleteTest.php Framework/IncompleteTestError.php \
		Framework/Test.php Framework/TestCase.php \
		Framework/TestFailure.php Framework/TestListener.php \
		Framework/TestResult.php Framework/TestSuite.php \
		Framework/Warning.php Runner/BaseTestRunner.php \
		Runner/IncludePathTestCollector.php \
		Runner/StandardTestSuiteLoader.php Runner/TestCollector.php \
		Runner/TestSuiteLoader.php Runner/Version.php \
		TextUI/ResultPrinter.php TextUI/TestRunner.php \
		Util/CodeCoverage/Renderer/HTML.php \
		Util/CodeCoverage/Renderer/Text.php \
		Util/CodeCoverage/Renderer.php Util/Log/PEAR.php \
		Util/Log/XML.php Util/TestDox/ResultPrinter/HTML.php \
		Util/TestDox/ResultPrinter/Text.php \
		Util/TestDox/NamePrettifier.php Util/TestDox/ResultPrinter.php \
		Util/ErrorHandler.php Util/Fileloader.php Util/Filter.php \
		Util/Printer.php Util/Skeleton.php
EXAMPLES=	BankAccount/BankAccount.php BankAccount/BankAccountTest.php \
		Money/IMoney.php Money/Money.php Money/MoneyBag.php \
		Money/MoneyTest.php
TESTS=		Framework/AllTests.php Framework/AssertTest.php \
		Framework/ComparisonFailureTest.php Framework/SuiteTest.php \
		Framework/TestCaseTest.php Framework/TestImplementorTest.php \
		Framework/TestListenerTest.php Extensions/AllTests.php \
		Extensions/ExceptionTestCaseTest.php \
		Extensions/ExtensionTest.php \
		Extensions/PerformanceTestCaseTest.php \
		Extensions/RepeatedTestTest.php Runner/AllTests.php \
		Runner/BaseTestRunnerTest.php Util/TestDox/AllTests.php \
		Util/TestDox/NamePrettifierTest.php AllTests.php \
		DoubleTestCase.php Error.php Failure.php InheritedTestCase.php \
		MockRunner.php NoArgTestCaseTest.php NonStatic.php \
		NoTestCaseClass.php NoTestCases.php NotPublicTestCase.php \
		NotVoidTestCase.php OneTestCase.php OverrideTestCase.php \
		SetupFailure.php Sleep.php Success.php TearDownFailure.php \
		TestIterator.php ThrowExceptionTestCase.php \
		ThrowNoExceptionTestCase.php TornDown.php TornDown2.php \
		TornDown3.php TornDown4.php TornDown5.php TornDown6.php \
		WasRun.php Util/AllTests.php
SCRIPTFILES=	phpunit
_EXAMPLESDIR=	Samples
_TESTSDIR=	Tests

post-extract:
	@${CP} ${WRKSRC}/${_TESTSDIR}/AllTests.php ${WRKSRC}/${_TESTSDIR}/Util

post-patch:
. for FILE in ${FILES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|g" ${WRKSRC}/${FILE}
. endfor
. for FILE in ${EXAMPLES}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|g" ${WRKSRC}/${_EXAMPLESDIR}/${FILE}
. endfor
. for FILE in ${TESTS}
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|g" ${WRKSRC}/${_TESTSDIR}/${FILE}
. endfor
	@${REINPLACE_CMD} -e "s|@package_version@|${PORTVERSION}|g" ${WRKSRC}/pear-${SCRIPTFILES}

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
