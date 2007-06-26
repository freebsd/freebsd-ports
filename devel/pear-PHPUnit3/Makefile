# Ports collection makefile for:  pear-PHPUnit3
# Date created:			  17 May 2007
# Whom:				  Gerrit Beine (<gerrit.beine@gmx.de>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit
PORTVERSION=	3.0.6
PORTREVISION=	1
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.phpunit.de/get/

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	PEAR regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

BROKEN=		Does not fetch

CONFLICTS=	*PHPUnit*

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_LOG "PEAR::Log support" off \
		JSON "Enable JSON support" off \

CHANNEL=	pear.phpunit.de

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

USE_PHP=	dom spl

FILES=		PHPUnit2/Extensions/ExceptionTestCase.php \
		PHPUnit2/Extensions/PerformanceTestCase.php \
		PHPUnit2/Extensions/RepeatedTest.php \
		PHPUnit2/Extensions/TestDecorator.php \
		PHPUnit2/Extensions/TestSetup.php \
		PHPUnit2/Framework/Assert.php \
		PHPUnit2/Framework/AssertionFailedError.php \
		PHPUnit2/Framework/ComparisonFailure.php \
		PHPUnit2/Framework/Error.php \
		PHPUnit2/Framework/IncompleteTest.php \
		PHPUnit2/Framework/IncompleteTestError.php \
		PHPUnit2/Framework/Test.php \
		PHPUnit2/Framework/TestCase.php \
		PHPUnit2/Framework/TestListener.php \
		PHPUnit2/Framework/TestResult.php \
		PHPUnit2/Framework/TestSuite.php \
		PHPUnit2/Framework/Warning.php \
		PHPUnit2/Runner/BaseTestRunner.php \
		PHPUnit2/Runner/IncludePathTestCollector.php \
		PHPUnit2/Runner/StandardTestSuiteLoader.php \
		PHPUnit2/Runner/TestCollector.php \
		PHPUnit2/Runner/TestSuiteLoader.php \
		PHPUnit2/Runner/Version.php \
		PHPUnit2/TextUI/ResultPrinter.php \
		PHPUnit2/TextUI/TestRunner.php \
		PHPUnit2/Util/Log/PEAR.php \
		PHPUnit2/Util/Log/XML.php \
		PHPUnit2/Util/Filter.php \
		PHPUnit/Extensions/ExceptionTestCase.php \
		PHPUnit/Extensions/OutputTestCase.php \
		PHPUnit/Extensions/PerformanceTestCase.php \
		PHPUnit/Extensions/RepeatedTest.php \
		PHPUnit/Extensions/SeleniumTestCase.php \
		PHPUnit/Extensions/TestDecorator.php \
		PHPUnit/Extensions/TestSetup.php \
		PHPUnit/Framework/ComparisonFailure/Array.php \
		PHPUnit/Framework/ComparisonFailure/Object.php \
		PHPUnit/Framework/ComparisonFailure/Scalar.php \
		PHPUnit/Framework/ComparisonFailure/String.php \
		PHPUnit/Framework/ComparisonFailure/Type.php \
		PHPUnit/Framework/Constraint/And.php \
		PHPUnit/Framework/Constraint/ArrayHasKey.php \
		PHPUnit/Framework/Constraint/FileExists.php \
		PHPUnit/Framework/Constraint/GreaterThan.php \
		PHPUnit/Framework/Constraint/IsAnything.php \
		PHPUnit/Framework/Constraint/IsEqual.php \
		PHPUnit/Framework/Constraint/IsIdentical.php \
		PHPUnit/Framework/Constraint/IsInstanceOf.php \
		PHPUnit/Framework/Constraint/IsType.php \
		PHPUnit/Framework/Constraint/LessThan.php \
		PHPUnit/Framework/Constraint/Not.php \
		PHPUnit/Framework/Constraint/ObjectHasAttribute.php \
		PHPUnit/Framework/Constraint/Or.php \
		PHPUnit/Framework/Constraint/PCREMatch.php \
		PHPUnit/Framework/Constraint/StringContains.php \
		PHPUnit/Framework/Constraint/TraversableContains.php \
		PHPUnit/Framework/Constraint/Xor.php \
		PHPUnit/Framework/MockObject/Builder/Identity.php \
		PHPUnit/Framework/MockObject/Builder/InvocationMocker.php \
		PHPUnit/Framework/MockObject/Builder/Match.php \
		PHPUnit/Framework/MockObject/Builder/MethodNameMatch.php \
		PHPUnit/Framework/MockObject/Builder/Namespace.php \
		PHPUnit/Framework/MockObject/Builder/ParametersMatch.php \
		PHPUnit/Framework/MockObject/Builder/Stub.php \
		PHPUnit/Framework/MockObject/Matcher/AnyInvokedCount.php \
		PHPUnit/Framework/MockObject/Matcher/AnyParameters.php \
		PHPUnit/Framework/MockObject/Matcher/Invocation.php \
		PHPUnit/Framework/MockObject/Matcher/InvokedAtIndex.php \
		PHPUnit/Framework/MockObject/Matcher/InvokedAtLeastOnce.php \
		PHPUnit/Framework/MockObject/Matcher/InvokedCount.php \
		PHPUnit/Framework/MockObject/Matcher/InvokedRecorder.php \
		PHPUnit/Framework/MockObject/Matcher/MethodName.php \
		PHPUnit/Framework/MockObject/Matcher/Parameters.php \
		PHPUnit/Framework/MockObject/Matcher/StatelessInvocation.php \
		PHPUnit/Framework/MockObject/Stub/ConsecutiveCalls.php \
		PHPUnit/Framework/MockObject/Stub/MatcherCollection.php \
		PHPUnit/Framework/MockObject/Stub/Return.php \
		PHPUnit/Framework/MockObject/Invocation.php \
		PHPUnit/Framework/MockObject/InvocationMocker.php \
		PHPUnit/Framework/MockObject/Invokable.php \
		PHPUnit/Framework/MockObject/Matcher.php \
		PHPUnit/Framework/MockObject/Mock.php \
		PHPUnit/Framework/MockObject/MockObject.php \
		PHPUnit/Framework/MockObject/Stub.php \
		PHPUnit/Framework/MockObject/Verifiable.php \
		PHPUnit/Framework/Assert.php \
		PHPUnit/Framework/AssertionFailedError.php \
		PHPUnit/Framework/ComparisonFailure.php \
		PHPUnit/Framework/Constraint.php \
		PHPUnit/Framework/Error.php \
		PHPUnit/Framework/ExpectationFailedException.php \
		PHPUnit/Framework/IncompleteTest.php \
		PHPUnit/Framework/IncompleteTestError.php \
		PHPUnit/Framework/SelfDescribing.php \
		PHPUnit/Framework/SkippedTest.php \
		PHPUnit/Framework/SkippedTestError.php \
		PHPUnit/Framework/Test.php \
		PHPUnit/Framework/TestCase.php \
		PHPUnit/Framework/TestFailure.php \
		PHPUnit/Framework/TestListener.php \
		PHPUnit/Framework/TestResult.php \
		PHPUnit/Framework/TestSuite.php \
		PHPUnit/Framework/Warning.php \
		PHPUnit/Runner/BaseTestRunner.php \
		PHPUnit/Runner/IncludePathTestCollector.php \
		PHPUnit/Runner/StandardTestSuiteLoader.php \
		PHPUnit/Runner/TestCollector.php \
		PHPUnit/Runner/TestSuiteLoader.php \
		PHPUnit/Runner/Version.php \
		PHPUnit/TextUI/Command.php \
		PHPUnit/TextUI/ResultPrinter.php \
		PHPUnit/TextUI/TestRunner.php \
		PHPUnit/Util/Log/GraphViz.php \
		PHPUnit/Util/Log/JSON.php \
		PHPUnit/Util/Log/PEAR.php \
		PHPUnit/Util/Log/TAP.php \
		PHPUnit/Util/Log/XML.php \
		PHPUnit/Util/Report/Coverage/Node/Directory.php \
		PHPUnit/Util/Report/Coverage/Node/File.php \
		PHPUnit/Util/Report/Coverage/Factory.php \
		PHPUnit/Util/Report/Coverage/Node.php \
		PHPUnit/Util/Report/Template/butter.png \
		PHPUnit/Util/Report/Template/chameleon.png \
		PHPUnit/Util/Report/Template/coverage_directory.html \
		PHPUnit/Util/Report/Template/coverage_file.html \
		PHPUnit/Util/Report/Template/coverage_item.html \
		PHPUnit/Util/Report/Template/coverage_item_details.html \
		PHPUnit/Util/Report/Template/coverage_item_details_header.html \
		PHPUnit/Util/Report/Template/glass.png \
		PHPUnit/Util/Report/Template/scarlet_red.png \
		PHPUnit/Util/Report/Template/snow.png \
		PHPUnit/Util/Report/Template/style.css \
		PHPUnit/Util/Report/Template/testsuite.html \
		PHPUnit/Util/Report/Template/testsuite_item.html \
		PHPUnit/Util/Report/Test/Node/Test.php \
		PHPUnit/Util/Report/Test/Node/TestSuite.php \
		PHPUnit/Util/Report/Test/Factory.php \
		PHPUnit/Util/Report/Test/Node.php \
		PHPUnit/Util/Report/GraphViz.php \
		PHPUnit/Util/Skeleton/IncompleteTestMethod.tpl \
		PHPUnit/Util/Skeleton/TestClass.tpl \
		PHPUnit/Util/Skeleton/TestMethod.tpl \
		PHPUnit/Util/TestDox/ResultPrinter/HTML.php \
		PHPUnit/Util/TestDox/ResultPrinter/Text.php \
		PHPUnit/Util/TestDox/NamePrettifier.php \
		PHPUnit/Util/TestDox/ResultPrinter.php \
		PHPUnit/Util/Array.php \
		PHPUnit/Util/ErrorHandler.php \
		PHPUnit/Util/Fileloader.php \
		PHPUnit/Util/Filesystem.php \
		PHPUnit/Util/Filter.php \
		PHPUnit/Util/FilterIterator.php \
		PHPUnit/Util/Getopt.php \
		PHPUnit/Util/Printer.php \
		PHPUnit/Util/Report.php \
		PHPUnit/Util/Skeleton.php \
		PHPUnit/Util/Template.php \
		PHPUnit/Util/Test.php \
		PHPUnit/Util/Timer.php \
		PHPUnit/Util/Type.php \
		PHPUnit/Framework.php
EXAMPLES=	BankAccount/BankAccount.php \
		BankAccount/BankAccountTest.php \
		Money/IMoney.php \
		Money/Money.php \
		Money/MoneyBag.php \
		Money/MoneyTest.php \
		FailureTest.php
TESTS=		Extensions/AllTests.php \
		Extensions/ExceptionTestCaseTest.php \
		Extensions/ExtensionTest.php \
		Extensions/OutputTestCaseTest.php \
		Extensions/PerformanceTestCaseTest.php \
		Extensions/RepeatedTestTest.php \
		Extensions/SeleniumTestCaseTest.php \
		Framework/AllTests.php \
		Framework/AssertTest.php \
		Framework/ComparisonFailureTest.php \
		Framework/ConstraintTest.php \
		Framework/MockObjectTest.php \
		Framework/SuiteTest.php \
		Framework/TestCaseTest.php \
		Framework/TestImplementorTest.php \
		Framework/TestListenerTest.php \
		Runner/AllTests.php \
		Runner/BaseTestRunnerTest.php \
		Util/TestDox/AllTests.php \
		Util/TestDox/NamePrettifierTest.php \
		Util/AllTests.php \
		_files/AnInterface.php \
		_files/ClassWithNonPublicAttributes.php \
		_files/DoubleTestCase.php \
		_files/Error.php \
		_files/Failure.php \
		_files/InheritedTestCase.php \
		_files/MockRunner.php \
		_files/NoArgTestCaseTest.php \
		_files/NoTestCaseClass.php \
		_files/NoTestCases.php \
		_files/NonStatic.php \
		_files/NotPublicTestCase.php \
		_files/NotVoidTestCase.php \
		_files/OneTestCase.php \
		_files/OutputTestCase.php \
		_files/OverrideTestCase.php \
		_files/SampleClass.php \
		_files/SetupFailure.php \
		_files/Sleep.php \
		_files/Struct.php \
		_files/Success.php \
		_files/TearDownFailure.php \
		_files/TestIterator.php \
		_files/ThrowExceptionTestCase.php \
		_files/ThrowNoExceptionTestCase.php \
		_files/TornDown.php \
		_files/TornDown2.php \
		_files/TornDown3.php \
		_files/TornDown4.php \
		_files/TornDown5.php \
		_files/TornDown6.php \
		_files/WasRun.php \
		AllTests.php \
		TestConfiguration.php.dist
SCRIPTFILES=	phpunit
_EXAMPLESDIR=	PHPUnit/Samples
_TESTSDIR=	PHPUnit/Tests

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if defined(WITH_JSON)
USE_PHP+=	json
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
