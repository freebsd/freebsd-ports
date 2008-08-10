# Ports collection makefile for:  pear-PHP_CompatInfo
# Date created:			  15 March 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	PHP_CompatInfo
PORTVERSION=	1.8.0
CATEGORIES=	devel pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PEAR class to find out the minimum version and extensions required

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	tokenizer
USE_DOS2UNIX=	yes

CATEGORY=	PHP
FILES=		CompatInfo/Cli.php CompatInfo/const_array.php \
		CompatInfo/func_array.php scripts/compatinfo.bat scripts/pci.php \
		CompatInfo.php
EXAMPLES=	checkConstants.php checkExtensions.php checkPHP5.php \
		ci_frontend.php cliCustom.php cliOutput.txt \
		ignorePHP5implements.php parseArray.php parseDir.php \
		parseFile.php parseString.php
TESTS=		emptyDir/empty_dir.txt parseDir/PHP5/tokens.php5 \
		parseDir/PHP5/upload_error.php parseDir/extensions.php \
		parseDir/phpinfo.php parseFile/conditional.php \
		parseFile/empty.php parseFile/ignore_functions_match.php \
		parseFile/math.php parseFile/PackageUpdate.php \
		parseFile/php5_method_chaining.php \
		parseFile/php5_method_chaining_samp2.php \
		parseFile/phpweb-entities.php parseFile/zip.php AllTests.php \
		checkMax.php PHP_CompatInfo_TestSuite_Bugs.php \
		PHP_CompatInfo_TestSuite_Cli.php \
		PHP_CompatInfo_TestSuite_Standard.php sample_req6056.php
_EXAMPLESDIR=	docs/examples

LATEST_LINK=	pear-PHP_CompatInfo
OPTIONS=	PEAR_CONSOLE_TABLE "PEAR::Console_Table support" off \
		PEAR_CONSOLE_GETARGS "PEAR::Console_Getargs support" off \
		PEAR_PHPUNIT "PEAR::PHPUnit support" on \
		PEAR_XML_UTIL "PEAR::XML_Util support" on

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_CONSOLE_TABLE)
RUN_DEPENDS+=	${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table
.endif

.if defined(WITH_PEAR_CONSOLE_GETARGS)
RUN_DEPENDS+=	${PEARDIR}/Console/Console_TestListener.php:${PORTSDIR}/devel/pear-Console_Getargs
.endif

.if defined(WITH_PEAR_PHPUNIT)
RUN_DEPENDS+=	${PEARDIR}/PHPUnit.php:${PORTSDIR}/devel/pear-PHPUnit
.endif

.if defined(WITH_PEAR_XML_UTIL)
RUN_DEPENDS+=	${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
