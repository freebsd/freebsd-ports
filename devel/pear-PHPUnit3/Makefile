# Ports collection makefile for:  pear-PHPUnit3
# Date created:			  17 May 2007
# Whom:				  Gerrit Beine (<gerrit.beine@gmx.de>)
#
# $FreeBSD$
#

PORTNAME=	PHPUnit
PORTVERSION=	3.4.12
CATEGORIES=	devel www pear
MASTER_SITES=	http://pear.phpunit.de/get/

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	PEAR regression testing framework for unit tests

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

MANUAL_PACKAGE_BUILD=	attempts to contact pear.phpunit.de during install phase

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

FILES=		PHPUnit/Extensions/Database/AbstractTester.php \
		PHPUnit/Extensions/Database/Constraint/DataSetIsEqual.php \
		PHPUnit/Extensions/Database/Constraint/TableIsEqual.php \
		PHPUnit/Extensions/Database/DB/DataSet.php \
		PHPUnit/Extensions/Database/DB/DefaultDatabaseConnection.php \
		PHPUnit/Extensions/Database/DB/FilteredDataSet.php \
		PHPUnit/Extensions/Database/DB/IDatabaseConnection.php \
		PHPUnit/Extensions/Database/DB/IMetaData.php \
		PHPUnit/Extensions/Database/DB/MetaData.php \
		PHPUnit/Extensions/Database/DB/MetaData/InformationSchema.php \
		PHPUnit/Extensions/Database/DB/MetaData/MySQL.php \
		PHPUnit/Extensions/Database/DB/MetaData/Oci.php \
		PHPUnit/Extensions/Database/DB/MetaData/PgSQL.php \
		PHPUnit/Extensions/Database/DB/MetaData/Sqlite.php \
		PHPUnit/Extensions/Database/DB/ResultSetTable.php \
		PHPUnit/Extensions/Database/DB/Table.php \
		PHPUnit/Extensions/Database/DB/TableIterator.php \
		PHPUnit/Extensions/Database/DB/TableMetaData.php \
		PHPUnit/Extensions/Database/DataSet/AbstractDataSet.php \
		PHPUnit/Extensions/Database/DataSet/AbstractTable.php \
		PHPUnit/Extensions/Database/DataSet/AbstractTableMetaData.php \
		PHPUnit/Extensions/Database/DataSet/AbstractXmlDataSet.php \
		PHPUnit/Extensions/Database/DataSet/CompositeDataSet.php \
		PHPUnit/Extensions/Database/DataSet/CsvDataSet.php \
		PHPUnit/Extensions/Database/DataSet/DataSetFilter.php \
		PHPUnit/Extensions/Database/DataSet/DefaultDataSet.php \
		PHPUnit/Extensions/Database/DataSet/DefaultTable.php \
		PHPUnit/Extensions/Database/DataSet/DefaultTableIterator.php \
		PHPUnit/Extensions/Database/DataSet/DefaultTableMetaData.php \
		PHPUnit/Extensions/Database/DataSet/FlatXmlDataSet.php \
		PHPUnit/Extensions/Database/DataSet/IDataSet.php \
		PHPUnit/Extensions/Database/DataSet/IPersistable.php \
		PHPUnit/Extensions/Database/DataSet/ISpec.php \
		PHPUnit/Extensions/Database/DataSet/ITable.php \
		PHPUnit/Extensions/Database/DataSet/ITableIterator.php \
		PHPUnit/Extensions/Database/DataSet/ITableMetaData.php \
		PHPUnit/Extensions/Database/DataSet/Persistors/Abstract.php \
		PHPUnit/Extensions/Database/DataSet/Persistors/Factory.php \
		PHPUnit/Extensions/Database/DataSet/Persistors/FlatXml.php \
		PHPUnit/Extensions/Database/DataSet/Persistors/Xml.php \
		PHPUnit/Extensions/Database/DataSet/Persistors/Yaml.php \
		PHPUnit/Extensions/Database/DataSet/QueryDataSet.php \
		PHPUnit/Extensions/Database/DataSet/QueryTable.php \
		PHPUnit/Extensions/Database/DataSet/ReplacementDataSet.php \
		PHPUnit/Extensions/Database/DataSet/ReplacementTable.php \
		PHPUnit/Extensions/Database/DataSet/ReplacementTableIterator.php \
		PHPUnit/Extensions/Database/DataSet/Specs/Csv.php \
		PHPUnit/Extensions/Database/DataSet/Specs/DbQuery.php \
		PHPUnit/Extensions/Database/DataSet/Specs/DbTable.php \
		PHPUnit/Extensions/Database/DataSet/Specs/Factory.php \
		PHPUnit/Extensions/Database/DataSet/Specs/FlatXml.php \
		PHPUnit/Extensions/Database/DataSet/Specs/IFactory.php \
		PHPUnit/Extensions/Database/DataSet/Specs/Xml.php \
		PHPUnit/Extensions/Database/DataSet/Specs/Yaml.php \
		PHPUnit/Extensions/Database/DataSet/TableFilter.php \
		PHPUnit/Extensions/Database/DataSet/TableMetaDataFilter.php \
		PHPUnit/Extensions/Database/DataSet/XmlDataSet.php \
		PHPUnit/Extensions/Database/DataSet/YamlDataSet.php \
		PHPUnit/Extensions/Database/DefaultTester.php \
		PHPUnit/Extensions/Database/IDatabaseListConsumer.php \
		PHPUnit/Extensions/Database/ITester.php \
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
		PHPUnit/Extensions/Database/TestCase.php \
		PHPUnit/Extensions/Database/UI/Command.php \
		PHPUnit/Extensions/Database/UI/Context.php \
		PHPUnit/Extensions/Database/UI/IMedium.php \
		PHPUnit/Extensions/Database/UI/IMediumPrinter.php \
		PHPUnit/Extensions/Database/UI/IMode.php \
		PHPUnit/Extensions/Database/UI/IModeFactory.php \
		PHPUnit/Extensions/Database/UI/InvalidModeException.php \
		PHPUnit/Extensions/Database/UI/Mediums/Text.php \
		PHPUnit/Extensions/Database/UI/ModeFactory.php \
		PHPUnit/Extensions/Database/UI/Modes/ExportDataSet.php \
		PHPUnit/Extensions/Database/UI/Modes/ExportDataSet/Arguments.php \
		PHPUnit/Extensions/GroupTestSuite.php \
		PHPUnit/Extensions/OutputTestCase.php \
		PHPUnit/Extensions/PerformanceTestCase.php \
		PHPUnit/Extensions/PhptTestCase.php \
		PHPUnit/Extensions/PhptTestCase/Logger.php \
		PHPUnit/Extensions/PhptTestSuite.php \
		PHPUnit/Extensions/RepeatedTest.php \
		PHPUnit/Extensions/SeleniumTestCase.php \
		PHPUnit/Extensions/SeleniumTestCase/Driver.php \
		PHPUnit/Extensions/SeleniumTestCase/append.php \
		PHPUnit/Extensions/SeleniumTestCase/phpunit_coverage.php \
		PHPUnit/Extensions/SeleniumTestCase/prepend.php \
		PHPUnit/Extensions/Story/Given.php \
		PHPUnit/Extensions/Story/ResultPrinter.php \
		PHPUnit/Extensions/Story/ResultPrinter/HTML.php \
		PHPUnit/Extensions/Story/ResultPrinter/Template/scenario.html.dist \
		PHPUnit/Extensions/Story/ResultPrinter/Template/scenario_header.html.dist \
		PHPUnit/Extensions/Story/ResultPrinter/Template/scenarios.html.dist \
		PHPUnit/Extensions/Story/ResultPrinter/Template/step.html.dist \
		PHPUnit/Extensions/Story/ResultPrinter/Text.php \
		PHPUnit/Extensions/Story/Scenario.php \
		PHPUnit/Extensions/Story/SeleniumTestCase.php \
		PHPUnit/Extensions/Story/Step.php \
		PHPUnit/Extensions/Story/TestCase.php \
		PHPUnit/Extensions/Story/Then.php \
		PHPUnit/Extensions/Story/When.php \
		PHPUnit/Extensions/TestDecorator.php \
		PHPUnit/Extensions/TicketListener.php \
		PHPUnit/Extensions/TicketListener/Trac.php \
		PHPUnit/Framework.php \
		PHPUnit/Framework/Assert.php \
		PHPUnit/Framework/AssertionFailedError.php \
		PHPUnit/Framework/ComparisonFailure.php \
		PHPUnit/Framework/ComparisonFailure/Array.php \
		PHPUnit/Framework/ComparisonFailure/Object.php \
		PHPUnit/Framework/ComparisonFailure/Scalar.php \
		PHPUnit/Framework/ComparisonFailure/String.php \
		PHPUnit/Framework/ComparisonFailure/Type.php \
		PHPUnit/Framework/Constraint.php \
		PHPUnit/Framework/Constraint/And.php \
		PHPUnit/Framework/Constraint/ArrayHasKey.php \
		PHPUnit/Framework/Constraint/Attribute.php \
		PHPUnit/Framework/Constraint/ClassHasAttribute.php \
		PHPUnit/Framework/Constraint/ClassHasStaticAttribute.php \
		PHPUnit/Framework/Constraint/FileExists.php \
		PHPUnit/Framework/Constraint/GreaterThan.php \
		PHPUnit/Framework/Constraint/IsAnything.php \
		PHPUnit/Framework/Constraint/IsEqual.php \
		PHPUnit/Framework/Constraint/IsFalse.php \
		PHPUnit/Framework/Constraint/IsIdentical.php \
		PHPUnit/Framework/Constraint/IsInstanceOf.php \
		PHPUnit/Framework/Constraint/IsNull.php \
		PHPUnit/Framework/Constraint/IsTrue.php \
		PHPUnit/Framework/Constraint/IsType.php \
		PHPUnit/Framework/Constraint/LessThan.php \
		PHPUnit/Framework/Constraint/Not.php \
		PHPUnit/Framework/Constraint/ObjectHasAttribute.php \
		PHPUnit/Framework/Constraint/Or.php \
		PHPUnit/Framework/Constraint/PCREMatch.php \
		PHPUnit/Framework/Constraint/StringContains.php \
		PHPUnit/Framework/Constraint/StringEndsWith.php \
		PHPUnit/Framework/Constraint/StringStartsWith.php \
		PHPUnit/Framework/Constraint/TraversableContains.php \
		PHPUnit/Framework/Constraint/TraversableContainsOnly.php \
		PHPUnit/Framework/Constraint/Xor.php \
		PHPUnit/Framework/Error.php \
		PHPUnit/Framework/Error/Notice.php \
		PHPUnit/Framework/Error/Warning.php \
		PHPUnit/Framework/Exception.php \
		PHPUnit/Framework/ExpectationFailedException.php \
		PHPUnit/Framework/IncompleteTest.php \
		PHPUnit/Framework/IncompleteTestError.php \
		PHPUnit/Framework/MockObject/Builder/Identity.php \
		PHPUnit/Framework/MockObject/Builder/InvocationMocker.php \
		PHPUnit/Framework/MockObject/Builder/Match.php \
		PHPUnit/Framework/MockObject/Builder/MethodNameMatch.php \
		PHPUnit/Framework/MockObject/Builder/Namespace.php \
		PHPUnit/Framework/MockObject/Builder/ParametersMatch.php \
		PHPUnit/Framework/MockObject/Builder/Stub.php \
		PHPUnit/Framework/MockObject/Generator.php \
		PHPUnit/Framework/MockObject/Generator/mocked_class.tpl.dist \
		PHPUnit/Framework/MockObject/Generator/mocked_clone.tpl.dist \
		PHPUnit/Framework/MockObject/Generator/mocked_method.tpl.dist \
		PHPUnit/Framework/MockObject/Generator/unmocked_clone.tpl.dist \
		PHPUnit/Framework/MockObject/Generator/wsdl_class.tpl.dist \
		PHPUnit/Framework/MockObject/Generator/wsdl_method.tpl.dist \
		PHPUnit/Framework/MockObject/Invocation.php \
		PHPUnit/Framework/MockObject/InvocationMocker.php \
		PHPUnit/Framework/MockObject/Invokable.php \
		PHPUnit/Framework/MockObject/Matcher.php \
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
		PHPUnit/Framework/MockObject/MockObject.php \
		PHPUnit/Framework/MockObject/Stub.php \
		PHPUnit/Framework/MockObject/Stub/ConsecutiveCalls.php \
		PHPUnit/Framework/MockObject/Stub/Exception.php \
		PHPUnit/Framework/MockObject/Stub/MatcherCollection.php \
		PHPUnit/Framework/MockObject/Stub/Return.php \
		PHPUnit/Framework/MockObject/Stub/ReturnArgument.php \
		PHPUnit/Framework/MockObject/Stub/ReturnCallback.php \
		PHPUnit/Framework/MockObject/Verifiable.php \
		PHPUnit/Framework/Process/TestCaseMethod.tpl.dist \
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
		PHPUnit/Framework/TestSuite/DataProvider.php \
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
		PHPUnit/Util/Class.php \
		PHPUnit/Util/CodeCoverage.php \
		PHPUnit/Util/Configuration.php \
		PHPUnit/Util/Diff.php \
		PHPUnit/Util/ErrorHandler.php \
		PHPUnit/Util/File.php \
		PHPUnit/Util/Fileloader.php \
		PHPUnit/Util/Filesystem.php \
		PHPUnit/Util/Filter.php \
		PHPUnit/Util/FilterIterator.php \
		PHPUnit/Util/Getopt.php \
		PHPUnit/Util/GlobalState.php \
		PHPUnit/Util/InvalidArgumentHelper.php \
		PHPUnit/Util/Log/CPD.php \
		PHPUnit/Util/Log/CodeCoverage/Database.php \
		PHPUnit/Util/Log/CodeCoverage/XML/Clover.php \
		PHPUnit/Util/Log/CodeCoverage/XML/Source.php \
		PHPUnit/Util/Log/Database.php \
		PHPUnit/Util/Log/Database/MySQL.sql \
		PHPUnit/Util/Log/Database/SQLite3.sql \
		PHPUnit/Util/Log/GraphViz.php \
		PHPUnit/Util/Log/JSON.php \
		PHPUnit/Util/Log/JUnit.php \
		PHPUnit/Util/Log/Metrics.php \
		PHPUnit/Util/Log/PEAR.php \
		PHPUnit/Util/Log/PMD.php \
		PHPUnit/Util/Log/PMD/Rule.php \
		PHPUnit/Util/Log/PMD/Rule/Class.php \
		PHPUnit/Util/Log/PMD/Rule/Class/DepthOfInheritanceTree.php \
		PHPUnit/Util/Log/PMD/Rule/Class/EfferentCoupling.php \
		PHPUnit/Util/Log/PMD/Rule/Class/ExcessiveClassLength.php \
		PHPUnit/Util/Log/PMD/Rule/Class/ExcessivePublicCount.php \
		PHPUnit/Util/Log/PMD/Rule/Class/TooManyFields.php \
		PHPUnit/Util/Log/PMD/Rule/File.php \
		PHPUnit/Util/Log/PMD/Rule/Function.php \
		PHPUnit/Util/Log/PMD/Rule/Function/CRAP.php \
		PHPUnit/Util/Log/PMD/Rule/Function/CodeCoverage.php \
		PHPUnit/Util/Log/PMD/Rule/Function/CyclomaticComplexity.php \
		PHPUnit/Util/Log/PMD/Rule/Function/ExcessiveMethodLength.php \
		PHPUnit/Util/Log/PMD/Rule/Function/ExcessiveParameterList.php \
		PHPUnit/Util/Log/PMD/Rule/Function/NPathComplexity.php \
		PHPUnit/Util/Log/PMD/Rule/Project.php \
		PHPUnit/Util/Log/PMD/Rule/Project/CRAP.php \
		PHPUnit/Util/Log/TAP.php \
		PHPUnit/Util/Metrics.php \
		PHPUnit/Util/Metrics/Class.php \
		PHPUnit/Util/Metrics/File.php \
		PHPUnit/Util/Metrics/Function.php \
		PHPUnit/Util/Metrics/Project.php \
		PHPUnit/Util/PDO.php \
		PHPUnit/Util/PHP.php \
		PHPUnit/Util/Printer.php \
		PHPUnit/Util/Report.php \
		PHPUnit/Util/Report/Node.php \
		PHPUnit/Util/Report/Node/Directory.php \
		PHPUnit/Util/Report/Node/File.php \
		PHPUnit/Util/Report/Template/butter.png \
		PHPUnit/Util/Report/Template/chameleon.png \
		PHPUnit/Util/Report/Template/close12_1.gif \
		PHPUnit/Util/Report/Template/container-min.js \
		PHPUnit/Util/Report/Template/container.css \
		PHPUnit/Util/Report/Template/directory.html.dist \
		PHPUnit/Util/Report/Template/directory_item.html.dist \
		PHPUnit/Util/Report/Template/file.html.dist \
		PHPUnit/Util/Report/Template/file_item.html.dist \
		PHPUnit/Util/Report/Template/file_no_yui.html.dist \
		PHPUnit/Util/Report/Template/glass.png \
		PHPUnit/Util/Report/Template/method_item.html.dist \
		PHPUnit/Util/Report/Template/scarlet_red.png \
		PHPUnit/Util/Report/Template/snow.png \
		PHPUnit/Util/Report/Template/style.css \
		PHPUnit/Util/Report/Template/yahoo-dom-event.js \
		PHPUnit/Util/Report/Template/yui_item.js \
		PHPUnit/Util/Skeleton.php \
		PHPUnit/Util/Skeleton/Class.php \
		PHPUnit/Util/Skeleton/Template/Class.tpl.dist \
		PHPUnit/Util/Skeleton/Template/IncompleteTestMethod.tpl.dist \
		PHPUnit/Util/Skeleton/Template/Method.tpl.dist \
		PHPUnit/Util/Skeleton/Template/TestClass.tpl.dist \
		PHPUnit/Util/Skeleton/Template/TestMethod.tpl.dist \
		PHPUnit/Util/Skeleton/Template/TestMethodBool.tpl.dist \
		PHPUnit/Util/Skeleton/Template/TestMethodBoolStatic.tpl.dist \
		PHPUnit/Util/Skeleton/Template/TestMethodException.tpl.dist \
		PHPUnit/Util/Skeleton/Template/TestMethodExceptionStatic.tpl.dist \
		PHPUnit/Util/Skeleton/Template/TestMethodStatic.tpl.dist \
		PHPUnit/Util/Skeleton/Test.php \
		PHPUnit/Util/Template.php \
		PHPUnit/Util/Test.php \
		PHPUnit/Util/TestDox/NamePrettifier.php \
		PHPUnit/Util/TestDox/ResultPrinter.php \
		PHPUnit/Util/TestDox/ResultPrinter/HTML.php \
		PHPUnit/Util/TestDox/ResultPrinter/Text.php \
		PHPUnit/Util/TestSuiteIterator.php \
		PHPUnit/Util/Timer.php \
		PHPUnit/Util/Type.php \
		PHPUnit/Util/XML.php

EXAMPLES=	BankAccount/BankAccount.php \
		BankAccount/BankAccountTest.php \
		BankAccountDB/_files/bank-account-after-deposits.xml \
		BankAccountDB/_files/bank-account-after-new-account.xml \
		BankAccountDB/_files/bank-account-after-withdrawals.xml \
		BankAccountDB/_files/bank-account-seed.xml \
		BankAccountDB/BankAccount.php \
		BankAccountDB/BankAccountDBTest.php \
		BankAccountDB/BankAccountDBTestMySQL.php \
		BowlingGame/BowlingGame.php \
		BowlingGame/BowlingGameSpec.php \
		BowlingGame/BowlingGameTest.php \
		Money/IMoney.php \
		Money/Money.php \
		Money/MoneyBag.php \
		Money/MoneyTest.php
SCRIPTFILES=	phpunit dbunit
_EXAMPLESDIR=	PHPUnit/Samples

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
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/xdebug.so:${PORTSDIR}/devel/php-xdebug
.endif

post-patch:
	@${MV} ${WRKSRC}/dbunit.php ${WRKSRC}/pear-dbunit
	@${MV} ${WRKSRC}/phpunit.php ${WRKSRC}/pear-phpunit

.include "${PORTSDIR}/Mk/bsd.php.mk"
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
