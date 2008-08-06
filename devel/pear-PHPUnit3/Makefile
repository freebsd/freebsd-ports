# Ports collection makefile for:  pear-PHPUnit3
# Date created:			  17 May 2007
# Whom:				  Gerrit Beine (<gerrit.beine@gmx.de>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit
PORTVERSION=	3.2.21
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.phpunit.de/get/

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	PEAR regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS=	PHPUnit-[0-9]*

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_IMAGE_GRAPHVIZ "PEAR::Image::GraphViz support" off \
		PEAR_LOG "PEAR::Log support" off \
		JSON "Enable JSON support" off \
		PDO "Enable PDO support" off \
		PDO_SQLITE "Enable PDO_SQLite support" off \
		TOKENIZER "Enable Tokenizer support" off \
		PDO_MYSQL "Enable PDO_MySQL support" off \
		XDEBUG "Enable Xdebug support" off

CHANNEL=	pear.phpunit.de
SUB_FILES=	pear-deinstall pear-install
SUB_LIST+=	CHANNEL=${CHANNEL}
PKGINSTALL=	${WRKDIR}/pear-install
PKGDEINSTALL=	${WRKDIR}/pear-deinstall

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

USE_PHP=	dom spl pcre

FILES=		PHPUnit/Extensions/Database/Constraint/DataSetIsEqual.php \
		PHPUnit/Extensions/Database/Constraint/TableIsEqual.php \
		PHPUnit/Extensions/Database/DB/MetaData/InformationSchema.php \
		PHPUnit/Extensions/Database/DB/MetaData/MySQL.php \
		PHPUnit/Extensions/Database/DB/MetaData/Oci.php \
		PHPUnit/Extensions/Database/DB/MetaData/PgSQL.php \
		PHPUnit/Extensions/Database/DB/MetaData/Sqlite.php \
		PHPUnit/Extensions/Database/DB/DataSet.php \
		PHPUnit/Extensions/Database/DB/DefaultDatabaseConnection.php \
		PHPUnit/Extensions/Database/DB/FilteredDataSet.php \
		PHPUnit/Extensions/Database/DB/IDatabaseConnection.php \
		PHPUnit/Extensions/Database/DB/IMetaData.php \
		PHPUnit/Extensions/Database/DB/MetaData.php \
		PHPUnit/Extensions/Database/DB/ResultSetTable.php \
		PHPUnit/Extensions/Database/DB/Table.php \
		PHPUnit/Extensions/Database/DB/TableIterator.php \
		PHPUnit/Extensions/Database/DB/TableMetaData.php \
		PHPUnit/Extensions/Database/DataSet/AbstractDataSet.php \
		PHPUnit/Extensions/Database/DataSet/AbstractTable.php \
		PHPUnit/Extensions/Database/DataSet/AbstractTableMetaData.php \
		PHPUnit/Extensions/Database/DataSet/AbstractXmlDataSet.php \
		PHPUnit/Extensions/Database/DataSet/DataSetFilter.php \
		PHPUnit/Extensions/Database/DataSet/DefaultDataSet.php \
		PHPUnit/Extensions/Database/DataSet/DefaultTable.php \
		PHPUnit/Extensions/Database/DataSet/DefaultTableIterator.php \
		PHPUnit/Extensions/Database/DataSet/DefaultTableMetaData.php \
		PHPUnit/Extensions/Database/DataSet/FlatXmlDataSet.php \
		PHPUnit/Extensions/Database/DataSet/IDataSet.php \
		PHPUnit/Extensions/Database/DataSet/ITable.php \
		PHPUnit/Extensions/Database/DataSet/ITableIterator.php \
		PHPUnit/Extensions/Database/DataSet/ITableMetaData.php \
		PHPUnit/Extensions/Database/DataSet/TableFilter.php \
		PHPUnit/Extensions/Database/DataSet/TableMetaDataFilter.php \
		PHPUnit/Extensions/Database/DataSet/XmlDataSet.php \
		PHPUnit/Extensions/Database/Operation/Composite.php \
		PHPUnit/Extensions/Database/Operation/Delete.php \
		PHPUnit/Extensions/Database/Operation/DeleteAll.php \
		PHPUnit/Extensions/Database/Operation/Exception.php \
		PHPUnit/Extensions/Database/Operation/Factory.php \
		PHPUnit/Extensions/Database/Operation/IDatabaseOperation.php \
		PHPUnit/Extensions/Database/Operation/Insert.php \
		PHPUnit/Extensions/Database/Operation/Null.php \
		PHPUnit/Extensions/Database/Operation/Replace.php \
		PHPUnit/Extensions/Database/Operation/RowBased.php \
		PHPUnit/Extensions/Database/Operation/Truncate.php \
		PHPUnit/Extensions/Database/Operation/Update.php \
		PHPUnit/Extensions/Database/AbstractTester.php \
		PHPUnit/Extensions/Database/DefaultTester.php \
		PHPUnit/Extensions/Database/ITester.php \
		PHPUnit/Extensions/Database/TestCase.php \
		PHPUnit/Extensions/PhptTestCase/Logger.php \
		PHPUnit/Extensions/ExceptionTestCase.php \
		PHPUnit/Extensions/OutputTestCase.php \
		PHPUnit/Extensions/PerformanceTestCase.php \
		PHPUnit/Extensions/PhptTestCase.php \
		PHPUnit/Extensions/PhptTestSuite.php \
		PHPUnit/Extensions/RepeatedTest.php \
		PHPUnit/Extensions/SeleniumTestCase.php \
		PHPUnit/Extensions/TestDecorator.php \
		PHPUnit/Extensions/TestSetup.php \
		PHPUnit/Extensions/SeleniumTestCase/append.php \
		PHPUnit/Extensions/SeleniumTestCase/phpunit_coverage.php \
		PHPUnit/Extensions/SeleniumTestCase/prepend.php \
		PHPUnit/Framework/ComparisonFailure/Array.php \
		PHPUnit/Framework/ComparisonFailure/Object.php \
		PHPUnit/Framework/ComparisonFailure/Scalar.php \
		PHPUnit/Framework/ComparisonFailure/String.php \
		PHPUnit/Framework/ComparisonFailure/Type.php \
		PHPUnit/Framework/Constraint/And.php \
		PHPUnit/Framework/Constraint/ArrayHasKey.php \
		PHPUnit/Framework/Constraint/Attribute.php \
		PHPUnit/Framework/Constraint/ClassHasAttribute.php \
		PHPUnit/Framework/Constraint/ClassHasStaticAttribute.php \
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
		PHPUnit/Framework/Constraint/TraversableContainsOnly.php \
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
		PHPUnit/Framework/MockObject/Stub/Exception.php \
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
		PHPUnit/Framework/Notice.php \
		PHPUnit/Framework/SelfDescribing.php \
		PHPUnit/Framework/SkippedTest.php \
		PHPUnit/Framework/SkippedTestError.php \
		PHPUnit/Framework/SkippedTestSuiteError.php \
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
		PHPUnit/Util/Log/CodeCoverage/Database.php \
		PHPUnit/Util/Log/CodeCoverage/XML.php \
		PHPUnit/Util/Log/Database/MySQL.sql \
		PHPUnit/Util/Log/Database/SQLite3.sql \
		PHPUnit/Util/Log/PMD/Rule/Class/DepthOfInheritanceTree.php \
		PHPUnit/Util/Log/PMD/Rule/Class/EfferentCoupling.php \
		PHPUnit/Util/Log/PMD/Rule/Class/ExcessiveClassLength.php \
		PHPUnit/Util/Log/PMD/Rule/Class/ExcessivePublicCount.php \
		PHPUnit/Util/Log/PMD/Rule/Class/TooManyFields.php \
		PHPUnit/Util/Log/PMD/Rule/Function/CRAP.php \
		PHPUnit/Util/Log/PMD/Rule/Function/CodeCoverage.php \
		PHPUnit/Util/Log/PMD/Rule/Function/CyclomaticComplexity.php \
		PHPUnit/Util/Log/PMD/Rule/Function/ExcessiveMethodLength.php \
		PHPUnit/Util/Log/PMD/Rule/Function/ExcessiveParameterList.php \
		PHPUnit/Util/Log/PMD/Rule/Function/NPathComplexity.php \
		PHPUnit/Util/Log/PMD/Rule/Project/CRAP.php \
		PHPUnit/Util/Log/PMD/Rule/Class.php \
		PHPUnit/Util/Log/PMD/Rule/File.php \
		PHPUnit/Util/Log/PMD/Rule/Function.php \
		PHPUnit/Util/Log/PMD/Rule/Project.php \
		PHPUnit/Util/Log/PMD/Rule.php \
		PHPUnit/Util/Log/CPD.php \
		PHPUnit/Util/Log/Database.php \
		PHPUnit/Util/Log/GraphViz.php \
		PHPUnit/Util/Log/JSON.php \
		PHPUnit/Util/Log/Metrics.php \
		PHPUnit/Util/Log/PEAR.php \
		PHPUnit/Util/Log/PMD.php \
		PHPUnit/Util/Log/TAP.php \
		PHPUnit/Util/Log/XML.php \
		PHPUnit/Util/Metrics/Class.php \
		PHPUnit/Util/Metrics/File.php \
		PHPUnit/Util/Metrics/Function.php \
		PHPUnit/Util/Metrics/Project.php \
		PHPUnit/Util/Report/Node/Directory.php \
		PHPUnit/Util/Report/Node/File.php \
		PHPUnit/Util/Report/Template/butter.png \
		PHPUnit/Util/Report/Template/chameleon.png \
		PHPUnit/Util/Report/Template/close12_1.gif \
		PHPUnit/Util/Report/Template/container-min.js \
		PHPUnit/Util/Report/Template/container.css \
		PHPUnit/Util/Report/Template/directory.html \
		PHPUnit/Util/Report/Template/file.html \
		PHPUnit/Util/Report/Template/file_no_yui.html \
		PHPUnit/Util/Report/Template/glass.png \
		PHPUnit/Util/Report/Template/item.html \
		PHPUnit/Util/Report/Template/method_item.html \
		PHPUnit/Util/Report/Template/scarlet_red.png \
		PHPUnit/Util/Report/Template/snow.png \
		PHPUnit/Util/Report/Template/style.css \
		PHPUnit/Util/Report/Template/yahoo-dom-event.js \
		PHPUnit/Util/Report/Template/yui_item.js \
		PHPUnit/Util/Report/Node.php \
		PHPUnit/Util/Skeleton/IncompleteTestMethod.tpl \
		PHPUnit/Util/Skeleton/TestClass.tpl \
		PHPUnit/Util/Skeleton/TestMethod.tpl \
		PHPUnit/Util/Skeleton/TestMethodBool.tpl \
		PHPUnit/Util/Skeleton/TestMethodBoolStatic.tpl \
		PHPUnit/Util/Skeleton/TestMethodException.tpl \
		PHPUnit/Util/Skeleton/TestMethodExceptionStatic.tpl \
		PHPUnit/Util/Skeleton/TestMethodStatic.tpl \
		PHPUnit/Util/TestDox/ResultPrinter/HTML.php \
		PHPUnit/Util/TestDox/ResultPrinter/Text.php \
		PHPUnit/Util/TestDox/NamePrettifier.php \
		PHPUnit/Util/TestDox/ResultPrinter.php \
		PHPUnit/Util/Class.php \
		PHPUnit/Util/CodeCoverage.php \
		PHPUnit/Util/Configuration.php \
		PHPUnit/Util/ErrorHandler.php \
		PHPUnit/Util/Fileloader.php \
		PHPUnit/Util/Filesystem.php \
		PHPUnit/Util/Filter.php \
		PHPUnit/Util/FilterIterator.php \
		PHPUnit/Util/Getopt.php \
		PHPUnit/Util/Metrics.php \
		PHPUnit/Util/PDO.php \
		PHPUnit/Util/Printer.php \
		PHPUnit/Util/Report.php \
		PHPUnit/Util/Skeleton.php \
		PHPUnit/Util/Template.php \
		PHPUnit/Util/Test.php \
		PHPUnit/Util/TestSuiteIterator.php \
		PHPUnit/Util/Timer.php \
		PHPUnit/Util/Type.php \
		PHPUnit/Util/XML.php \
		PHPUnit/Framework.php
EXAMPLES=	BankAccount/BankAccount.php \
		BankAccount/BankAccountTest.php \
		BankAccountDB/_files/bank-account-after-deposits.xml \
		BankAccountDB/_files/bank-account-after-new-account.xml \
		BankAccountDB/_files/bank-account-after-withdrawals.xml \
		BankAccountDB/_files/bank-account-seed.xml \
		BankAccountDB/BankAccount.php \
		BankAccountDB/BankAccountDBTest.php \
		BankAccountDB/BankAccountDBTestMySQL.php \
		Money/IMoney.php \
		Money/Money.php \
		Money/MoneyBag.php \
		Money/MoneyTest.php \
		FailureTest.php
TESTS=		Extensions/Database/DataSet/AllTests.php \
		Extensions/Database/DataSet/FilterTest.php \
		Extensions/Database/DataSet/XmlDataSetsTest.php \
		Extensions/Database/Operation/AllTests.php \
		Extensions/Database/Operation/OperationsTest.php \
		Extensions/Database/Operation/RowBasedTest.php \
		Extensions/Database/_files/XmlDataSets/DeleteAllOperationTest.xml \
		Extensions/Database/_files/XmlDataSets/DeleteOperationResult.xml \
		Extensions/Database/_files/XmlDataSets/DeleteOperationTest.xml \
		Extensions/Database/_files/XmlDataSets/EmptyTableInsertResult.xml \
		Extensions/Database/_files/XmlDataSets/EmptyTableInsertTest.xml \
		Extensions/Database/_files/XmlDataSets/FilteredTestComparison.xml \
		Extensions/Database/_files/XmlDataSets/FilteredTestFixture.xml \
		Extensions/Database/_files/XmlDataSets/FlatXmlDataSet.xml \
		Extensions/Database/_files/XmlDataSets/InsertOperationResult.xml \
		Extensions/Database/_files/XmlDataSets/InsertOperationTest.xml \
		Extensions/Database/_files/XmlDataSets/OperationsTestFixture.xml \
		Extensions/Database/_files/XmlDataSets/ReplaceOperationResult.xml \
		Extensions/Database/_files/XmlDataSets/ReplaceOperationTest.xml \
		Extensions/Database/_files/XmlDataSets/RowBasedExecute.xml \
		Extensions/Database/_files/XmlDataSets/UpdateOperationResult.xml \
		Extensions/Database/_files/XmlDataSets/UpdateOperationTest.xml \
		Extensions/Database/_files/XmlDataSets/XmlDataSet.xml \
		Extensions/Database/_files/.dummy \
		Extensions/Database/AllTests.php \
		Extensions/AllTests.php \
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
		Util/TimerTest.php \
		_files/AnInterface.php \
		_files/BankAccount.json \
		_files/BankAccount.metrics \
		_files/BankAccount.pmd \
		_files/BankAccount.tap \
		_files/BankAccount.xml \
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
		_files/WasRun.php \
		_files/foo.xml \
		_files/bar.xml \
		AllTests.php \
		TestConfiguration.php.dist
SCRIPTFILES=	phpunit
_EXAMPLESDIR=	PHPUnit/Samples
_TESTSDIR=	PHPUnit/Tests

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_LOG)
RUN_DEPENDS+=	${PEARDIR}/Log/null.php:${PORTSDIR}/sysutils/pear-Log
.endif

.if defined(WITH_PEAR_IMAGE_GRAPHVIZ)
RUN_DEPENDS+=	${PEARDIR}/Image/GraphViz.php:${PORTSDIR}/graphics/pear-Image_GraphViz
.endif

.if defined(WITH_JSON)
USE_PHP+=	json
.endif

.if defined(WITH_PDO)
USE_PHP+=	pdo
.endif

.if defined(WITH_PDO_MYSQL)
USE_PHP+=	pdo_mysql
.endif

.if defined(WITH_PDO_SQLITE)
USE_PHP+=	pdo_sqlite
.endif

.if defined(WITH_TOKENIZER)
USE_PHP+=	tokenizer
.endif

.if defined(WITH_XDEBUG)
RUN_DEPENDS+=	${PREFIX}/lib/php/${PHP_EXT_DIR}/xdebug.so:${PORTSDIR}/devel/php-xdebug
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/PHPUnit/Tests/Extensions/Database/_files/.dummy

.include "${PORTSDIR}/Mk/bsd.php.mk"
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
