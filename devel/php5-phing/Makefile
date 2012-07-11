# New ports collection makefile for:	php5-phing
# Date Created:				9 Nov, 2005
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phing
PORTVERSION=	2.3.1
CATEGORIES=	devel
MASTER_SITES=	http://pear.phing.info/get/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Project build system based on Apache Ant

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

MANUAL_PACKAGE_BUILD=	attempts to contact pear.phing.info during install phase

USE_PHP=	yes
DEFAULT_PHP_VER=5
WANT_PHP_CLI=	yes
NO_BUILD=	yes

CHANNEL=	pear.phing.info
SUB_FILES=	pear-deinstall pear-install
SUB_LIST+=	CHANNEL=${CHANNEL}
PKGINSTALL=	${WRKDIR}/pear-install
PKGDEINSTALL=	${WRKDIR}/pear-deinstall

CATEGORY=phing
FILES=	etc/log.xsl etc/phpunit2-noframes.xsl etc/phpunit2-frames.xsl \
	etc/coverage-frames.xsl etc/str.replace.function.xsl etc/VERSION.TXT \
	bin/pear-phing.bat bin/pear-phing bin/phing.php \
	IntrospectionHelper.php ProjectComponent.php \
	BuildLogger.php TaskContainer.php BuildEvent.php Task.php \
	TaskAdapter.php Phing.php RuntimeConfigurable.php BuildListener.php \
	Project.php UnknownElement.php BuildException.php Target.php \
	ConfigurationException.php phing.php \
	util/regexp/RegexpEngine.php util/regexp/Regexp.php \
	util/regexp/PregEngine.php \
	util/SourceFileScanner.php util/ExtendedFileStream.php \
	util/DirectoryScanner.php \
	util/LogWriter.php util/FileUtils.php util/StringHelper.php \
	util/PathTokenizer.php \
	filters/util/IniFileTokenReader.php \
	filters/util/ChainReaderHelper.php \
	filters/LineContainsRegexp.php filters/ChainableReader.php \
	filters/ExpandProperties.php filters/TailFilter.php \
	filters/ReplaceTokens.php \
	filters/XsltFilter.php filters/StripLineBreaks.php \
	filters/StripLineComments.php \
	filters/TranslateGettext.php filters/BaseFilterReader.php \
	filters/HeadFilter.php \
	filters/TabToSpaces.php filters/TidyFilter.php \
	filters/StripPhpComments.php\
	filters/XincludeFilter.php filters/ReplaceRegexp.php \
	filters/BaseParamFilterReader.php\
	filters/LineContains.php filters/PrefixLines.php \
	filters/StripWhitespace.php\
	mappers/IdentityMapper.php mappers/RegexpMapper.php \
	mappers/FlattenMapper.php \
	mappers/MergeMapper.php mappers/FileNameMapper.php \
	mappers/GlobMapper.php \
	types/selectors/ContainsRegexpSelector.php \
	types/selectors/SelectorScanner.php  \
	types/selectors/MajoritySelector.php types/selectors/NoneSelector.php \
	types/selectors/DependSelector.php types/selectors/NotSelector.php \
	types/selectors/SelectorUtils.php types/selectors/AndSelector.php \
	types/selectors/DepthSelector.php types/selectors/BaseSelector.php \
	types/selectors/SizeSelector.php types/selectors/DateSelector.php \
	types/selectors/BaseSelectorContainer.php \
	types/selectors/ContainsSelector.php \
	types/selectors/FileSelector.php types/selectors/SelectSelector.php \
	types/selectors/FilenameSelector.php types/selectors/OrSelector.php \
	types/selectors/PresentSelector.php types/selectors/TypeSelector.php \
	types/selectors/BaseExtendSelector.php \
	types/selectors/SelectorContainer.php \
	types/selectors/ExtendSelector.php \
	types/selectors/ExtendFileSelector.php \
	types/Parameterizable.php types/PatternSet.php \
	types/DirSet.php types/FileSet.php types/Path.php types/Reference.php \
	types/TokenSource.php types/PhingFilterReader.php \
	types/TokenReader.php \
	types/Parameter.php types/FileList.php types/DataType.php \
	types/RegularExpression.php  \
	types/defaults.properties types/AbstractFileSet.php \
	types/Description.php \
	types/Mapper.php types/Commandline.php types/FilterChain.php \
	lib/Capsule.php lib/Zip.php \
	system/lang/FileNotFoundException.php \
	system/lang/NullPointerException.php  \
	system/lang/Character.php \
	system/lang/EventObject.php system/lang/SecurityException.php \
	system/io/WinNTFileSystem.php system/io/StringReader.php \
	system/io/Reader.php system/io/InputStreamReader.php \
	system/io/FileReader.php system/io/BufferedReader.php \
	system/io/PhingFile.php \
	system/io/OutputStreamWriter.php \
	system/io/Win32FileSystem.php system/io/FilterReader.php \
	system/io/FileInputStream.php system/io/InputStream.php \
	system/io/FileOutputStream.php \
	system/io/OutputStream.php system/io/FileWriter.php \
	system/io/FileSystem.php system/io/Writer.php \
	system/io/BufferedWriter.php \
	system/io/ConsoleReader.php system/io/IOException.php \
	system/io/UnixFileSystem.php system/util/Properties.php \
	system/util/Timer.php system/util/Message.php \
	system/util/Register.php \
	listener/AnsiColorLogger.php listener/defaults.properties \
	listener/PearLogListener.php \
	listener/XmlLogger.php listener/NoBannerLogger.php \
	listener/DefaultLogger.php \
	listener/StreamRequiredBuildLogger.php \
	tasks/ext/ioncube/IoncubeLicenseTask.php \
	tasks/ext/ioncube/IoncubeComment.php \
	tasks/ext/ioncube/IoncubeEncoderTask.php \
	tasks/ext/phpunit/phpunit2/SummaryPHPUnit2ResultFormatter.php \
	tasks/ext/phpunit/phpunit2/PHPUnit2ResultFormatter.php \
	tasks/ext/phpunit/phpunit2/XMLPHPUnit2ResultFormatter.php \
	tasks/ext/phpunit/phpunit2/PlainPHPUnit2ResultFormatter.php \
	tasks/ext/phpunit/phpunit3/SummaryPHPUnit3ResultFormatter.php \
	tasks/ext/phpunit/phpunit3/PHPUnit3ResultFormatter.php \
	tasks/ext/phpunit/phpunit3/XMLPHPUnit3ResultFormatter.php \
	tasks/ext/phpunit/phpunit3/PlainPHPUnit3ResultFormatter.php \
	tasks/ext/phpunit/FormatterElement.php \
	tasks/ext/phpunit/PHPUnitTask.php tasks/ext/phpunit/BatchTest.php \
	tasks/ext/phpunit/PHPUnitUtil.php \
	tasks/ext/phpunit/PHPUnitTestRunner.php \
	tasks/ext/phpunit/PHPUnitReportTask.php \
	tasks/ext/simpletest/SimpleTestSummaryResultFormatter.php \
	tasks/ext/simpletest/SimpleTestResultFormatter.php \
	tasks/ext/simpletest/SimpleTestTask.php \
	tasks/ext/simpletest/SimpleTestPlainResultFormatter.php \
	tasks/ext/simpletest/SimpleTestCountResultFormatter.php \
	tasks/ext/simpletest/SimpleTestFormatterElement.php \
	tasks/ext/coverage/CoverageReportTask.php \
	tasks/ext/coverage/CoverageMerger.php \
	tasks/ext/coverage/CoverageReportTransformer.php \
	tasks/ext/coverage/CoverageSetupTask.php \
	tasks/ext/coverage/CoverageMergerTask.php \
	tasks/ext/dbdeploy/DbmsSyntaxMsSql.php \
	tasks/ext/dbdeploy/DbmsSyntax.php \
	tasks/ext/dbdeploy/DbmsSyntaxFactory.php \
	tasks/ext/dbdeploy/DbmsSyntaxSQLite.php \
	tasks/ext/dbdeploy/DbmsSyntaxMysql.php \
	tasks/ext/dbdeploy/DbDeployTask.php \
	tasks/ext/pearpackage/Fileset.php \
	tasks/ext/svn/SvnLastRevisionTask.php \
	tasks/ext/svn/SvnExportTask.php tasks/ext/svn/SvnUpdateTask.php \
	tasks/ext/svn/SvnCheckoutTask.php tasks/ext/svn/SvnBaseTask.php \
	tasks/ext/phpdoc/PhingPhpDocumentorSetup.php \
	tasks/ext/phpdoc/PhpDocumentorTask.php \
	tasks/ext/phpdoc/PhpDocumentorExternalTask.php \
	tasks/ext/creole/CreoleSQLExecTask.php \
	tasks/ext/creole/CreoleTask.php tasks/ext/PearPackage2Task.php \
	tasks/ext/FtpDeployTask.php tasks/ext/ManifestTask.php \
	tasks/ext/PhpLintTask.php tasks/ext/SmartyTask.php \
	tasks/ext/JslLintTask.php tasks/ext/MailTask.php \
	tasks/ext/XmlLintTask.php tasks/ext/TarTask.php \
	tasks/ext/PearPackageTask.php tasks/ext/UntarTask.php \
	tasks/ext/CapsuleTask.php tasks/ext/pdo/PDOResultFormatter.php \
	tasks/ext/PhpCodeSnifferTask.php \
	tasks/ext/pdo/PDOSQLExecTask.php tasks/ext/pdo/PDOTask.php \
	tasks/ext/pdo/PDOSQLExecFormatterElement.php \
	tasks/ext/pdo/PlainPDOResultFormatter.php \
	tasks/ext/pdo/XMLPDOResultFormatter.php \
	tasks/ext/PackageAsPathTask.php \
	tasks/ext/ScpSendTask.php tasks/ext/ZipTask.php \
	tasks/ext/ZendCodeAnalyzerTask.php tasks/ext/ExtractBaseTask.php \
	tasks/ext/UnzipTask.php tasks/system/condition/IsFalseCondition.php \
	tasks/system/condition/AndCondition.php \
	tasks/system/condition/ContainsCondition.php \
	tasks/system/condition/IsSetCondition.php \
	tasks/system/condition/ConditionBase.php \
	tasks/system/condition/EqualsCondition.php \
	tasks/system/condition/IsTrueCondition.php \
	tasks/system/condition/ReferenceExistsCondition.php \
	tasks/system/condition/Condition.php \
	tasks/system/condition/NotCondition.php \
	tasks/system/condition/OrCondition.php \
	tasks/system/condition/OsCondition.php \
	tasks/system/SequentialTask.php \
	tasks/system/ForeachTask.php tasks/system/TstampTask.php \
	tasks/system/ExitTask.php tasks/system/ChownTask.php\
	tasks/system/TaskdefTask.php tasks/system/EchoTask.php \
	tasks/system/ConditionTask.php \
	tasks/system/CvsPassTask.php tasks/system/PropertyTask.php \
	tasks/system/UpToDateTask.php \
	tasks/system/PhpEvalTask.php tasks/system/XsltTask.php \
	tasks/system/CvsTask.php \
	tasks/system/PropertyPromptTask.php tasks/system/ResolvePathTask.php \
	tasks/system/InputTask.php \
	tasks/system/TypedefTask.php tasks/system/PhingTask.php \
	tasks/system/MoveTask.php \
	tasks/system/MkdirTask.php tasks/system/AppendTask.php \
	tasks/system/WarnTask.php \
	tasks/system/CopyTask.php tasks/system/AdhocTask.php \
	tasks/system/AdhocTaskdefTask.php \
	tasks/system/AvailableTask.php tasks/system/TouchTask.php \
	tasks/system/ExecTask.php \
	tasks/system/ReflexiveTask.php tasks/system/MatchingTask.php \
	tasks/system/ChmodTask.php \
	tasks/system/IfTask.php tasks/system/AdhocTypedefTask.php \
	tasks/system/IncludePathTask.php \
	tasks/system/PhingCallTask.php tasks/system/DeleteTask.php \
	tasks/defaults.properties \
	parser/ProjectConfigurator.php parser/DataTypeHandler.php \
	parser/NestedElementHandler.php \
	parser/ExpatParseException.php parser/AbstractSAXParser.php \
	parser/ExpatParser.php \
	parser/TaskHandler.php parser/AbstractHandler.php \
	parser/RootHandler.php \
	parser/ProjectHandler.php parser/TargetHandler.php \
	parser/Location.php \
	input/InputHandler.php input/InputRequest.php \
	input/MultipleChoiceInputRequest.php \
	input/DefaultInputHandler.php input/PropertyFileInputHandler.php \
	input/YesNoInputRequest.php

_DOCSDIR=.
DOCS=	CHANGELOG CREDITS README
EXAMPLES=	src/HelloWorldTest.php src/HelloWorld.php build.xml
SCRIPTFILES=	phing

post-extract:
	${MV} ${WRKSRC}/example ${WRKSRC}/examples

post-patch:
	${MKDIR} ${WRKSRC}/pear-bin
	${SED} -e "s|/opt/phing|${PREFIX}/lib/php/phing|" \
		-e "s|@PHP-BIN@|${PREFIX}/bin/php|" \
		-e "s|@PEAR-DIR@|${PREFIX}/share/pear/phing|" \
	${WRKSRC}/bin/pear-phing > ${WRKSRC}/pear-phing
	${CP} ${WRKSRC}/bin/phing.php ${WRKSRC}/phing.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
